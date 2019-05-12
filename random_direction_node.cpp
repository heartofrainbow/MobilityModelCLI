#define M_PI 3.141592654
#include "random_direction_node.h"
#include "publicvar.h"
#include <iostream>
#include <random>
#include <math.h>
#include <iomanip>
#include <chrono>
#include <thread>
#include <unistd.h>

using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

random_direction_node::random_direction_node(int n):node(n){
    this->id = n;
}


void random_direction_node::update(double time){   //parameter time is in second
    if (this->x <= XMIN) {      //If random_direction_node hit the XMIN bound then reflect
        this->x = 2*XMIN - this->x;     //Fix out of bound bug: if OutOfBound then mirror
        reflect(1);
    }else if(this->x >= XMAX){  //If random_direction_node hit the XMAX bound then reflect
        this->x = 2*XMAX - this->x;
        reflect(2);
    }
    if (this->y <= YMIN) {
        this->y = 2*YMIN - this->y;
        reflect(3);
    } else if(this->y >= YMAX){
        this->y = 2*YMAX - this->y;
        reflect(4);
    }
    if (this->z <=ZMIN){
        this->z = 2*ZMIN - this->z;
        reflect(5);
    }else if(this->z >= ZMAX){
        this->z = 2*ZMAX - this->z;
        reflect(6);
    }
    this->x += this->getv()*cos(this->getd())*sin(this->getp())*time;
    this->y += this->getv()*sin(this->getd())*sin(this->getp())*time;
    this->z += this->getv()*cos(this->getp())*time;
//    printf("ID=%d\t\tX=%f\t\tY=%f\t\tZ=%f\n",this->id,this->x,this->y,this->z);
    points[this->id] = glm::vec3(this->x, this->y, this->z);
    calc(this->id, this->x, this->y, this->z);    //这句是将xyz转换为wgs84坐标系
    if(reflected == true){
        sleep(interval);
        reflected = false;
    }
}

void random_direction_node::reflect(int err){      //err: 1 XMIN 2 XMAX 3 YMIN 4 YMAX
    uniform_real_distribution<double> randomDir(0,2*M_PI);
    uniform_real_distribution<double> randomPitch(0,M_PI);
    if (err == lastErr) {           //In case random_direction_node reflect forever near an edge
        return;
    }
    if(err == 1){
        do{
            d = randomDir(e);
            p = randomPitch(e);
        }while(d >= M_PI/2 && d <= 3*M_PI/2);
    }else if(err == 2){
        do{
            d = randomDir(e);
            p = randomPitch(e);
        }while(d <= M_PI/2 || d >= 3*M_PI/2);
    }else if(err == 3){
        do{
            d = randomDir(e);
            p = randomPitch(e);
        }while(d >= M_PI);
    }else if(err == 4){
        do{
            d = randomDir(e);
            p = randomPitch(e);
        }while(d <= M_PI);
    }else if(err == 5){
        do{
            d = randomDir(e);
            p = randomPitch(e);
        }while(p >= 0.5*M_PI);
    }else if(err == 6){
        do{
            d = randomDir(e);
            p = randomPitch(e);
        }while(p <= 0.5*M_PI);
    }
    lastErr = err;
    reflected = true;
}

void random_direction_node::run(){
    uniform_real_distribution<double> randomX(XMIN,XMAX);
    uniform_real_distribution<double> randomY(YMIN,YMAX);
    uniform_real_distribution<double> randomZ(ZMIN,ZMAX);
    uniform_real_distribution<double> randomVel(VMIN,VMAX);
    uniform_real_distribution<double> randomDir(0,2*M_PI);
    uniform_real_distribution<double> randomPitch(0,M_PI);
    x = randomX(e);
    y = randomY(e);
    z = randomZ(e);
    v = randomVel(e);
    d = randomDir(e);
    p = randomPitch(e);
    std::chrono::duration<double, std::micro> tmpTime;     //Time between current and lastshow
    std::chrono::duration<double, std::micro> loopTime;    //Time used for a single loop
    std::chrono::duration<double, std::micro> changeTime;
    std::chrono::duration<double, std::micro> wholeTime;
    high_resolution_clock::time_point loopEndTime;
    cout<<setiosflags(ios::fixed);
    high_resolution_clock::time_point baseTime = high_resolution_clock::now();
    high_resolution_clock::time_point lastChange = high_resolution_clock::now();    //Time when random_direction_node info changed
    high_resolution_clock::time_point  lastUpdate = lastChange;   //Time when random_direction_node loc updated
    high_resolution_clock::time_point lastShow = lastUpdate;    //Time when random_direction_node info shown
    high_resolution_clock::time_point currentTime = high_resolution_clock::now();
    wholeTime = currentTime-baseTime;
//    printf("ID=%d\t\tX=%f\t\tY=%f\t\tZ=%f\n",this->id,this->x,this->y,this->z);
    points[this->id] = glm::vec3(this->x, this->y, this->z);
    calc(this->id, this->x, this->y, this->z);    //这句是将xyz转换为wgs84坐标系
    //initial output
    while(running == true){
        currentTime = high_resolution_clock::now();
        tmpTime = (currentTime-lastShow);
        loopEndTime = high_resolution_clock::now();
        if (first) {
            lastUpdate = loopEndTime;
            lastChange = loopEndTime;
            first = false;
        }
        loopTime=(loopEndTime-lastUpdate);
        this->update(loopTime.count()/1e6);

        lastUpdate = high_resolution_clock::now();
        currentTime = high_resolution_clock::now();
        changeTime = currentTime-lastChange;
        usleep(1000);
    }
}
