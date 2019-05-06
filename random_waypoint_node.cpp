#define M_PI 3.141592654
#include "random_waypoint_node.h"
#include "publicvar.h"
#include <iostream>
#include <random>
#include <math.h>
#include <iomanip>
#include <chrono>
#include <thread>
#include "node.h"
#include <unistd.h>


using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

random_waypoint_node::random_waypoint_node(int n):node(n){
    this->id = n;
}

void random_waypoint_node::update(double time){   //parameter time is in second
    if(x < destx && (d >= M_PI/2 && d <= 3*M_PI/2)){
        reflect();
        return;
    }else if(x > destx && (d<= M_PI/2 || d >= 3*M_PI/2)){
        reflect();
        return;
    }else if(d == M_PI/2 && y > desty){
        reflect();
        return;
    }else if(d == 3*M_PI/2 && y < desty){
        reflect();
        return;
    }else if(p < M_PI/2 && z > destz){
        reflect();
        return;
    }else if(p > M_PI/2 && z < destz){
        reflect();
        return;
    }
//    if((desty - y) * d <0 || (destx -x) * d <0 ||  (destz -z) * p <0){
//        reflect();
//        return;
//    }
    this->x += this->getv()*cos(this->getd())*sin(this->getp())*time;
    this->y += this->getv()*sin(this->getd())*sin(this->getp())*time;
    this->z += this->getv()*cos(this->getp())*time;
    printf("ID=%d\t\tX=%f\t\tY=%f\t\tZ=%f\n",this->id,this->x,this->y,this->z);
}

void random_waypoint_node::reflect(){      //err: 1 XMIN 2 XMAX 3 YMIN 4 YMAX
    this->x = destx;
    this->y = desty;
    this->z = destz;
    printf("ID=%d\t\tX=%f\t\tY=%f\t\tZ=%f\n",this->id,this->x,this->y,this->z);
//    usleep(interval*1000000);
    sleep(interval);
    lastErr=1;

}

void random_waypoint_node::run(){
    uniform_real_distribution<double> randomX(XMIN,XMAX);
    uniform_real_distribution<double> randomY(YMIN,YMAX);
    uniform_real_distribution<double> randomZ(ZMIN,ZMAX);
    uniform_real_distribution<double> randomVel(VMIN,VMAX);
    uniform_real_distribution<double> randomDir(0,2*M_PI);
    uniform_real_distribution<double> randomPitch(0,M_PI);
    x = randomX(e);
    y = randomY(e);
    z = randomZ(e);
    destx = randomX(e);
    desty = randomY(e);
    destz = randomZ(e);
    v = randomVel(e);
    d = atan2(desty-y,destx-x);
    p = acos((destz-z)/(sqrt((desty-y)*(desty-y)+(destx-x)*(destx-x)+(destz -z)*(destz -z))));
    std::chrono::duration<double, std::micro> tmpTime;     //Time between current and lastshow
    std::chrono::duration<double, std::micro> loopTime;    //Time used for a single loop
    std::chrono::duration<double, std::micro> changeTime;
    std::chrono::duration<double, std::micro> wholeTime;
    high_resolution_clock::time_point loopEndTime;
    cout<<setiosflags(ios::fixed);
    high_resolution_clock::time_point baseTime = high_resolution_clock::now();
    high_resolution_clock::time_point lastChange = high_resolution_clock::now();    //Time when random_waypoint_node info changed
    high_resolution_clock::time_point  lastUpdate = lastChange;   //Time when random_waypoint_node loc updated
    high_resolution_clock::time_point lastShow = lastUpdate;    //Time when random_waypoint_node info shown
    high_resolution_clock::time_point currentTime = high_resolution_clock::now();
    wholeTime = currentTime-baseTime;
    printf("ID=%d\t\tX=%f\t\tY=%f\t\tZ=%f\n",this->id,this->x,this->y,this->z);
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
        if(lastErr == 1){       //Regenerate random_waypoint_node info every $timeout second
            lastChange = currentTime;
            destx = randomX(e);
            desty = randomY(e);
            destz = randomZ(e);
            this->setv(randomVel(e));
            this->setd(atan2(desty-y,destx-x));
            this->setp(acos((destz-z)/(sqrt((desty-y)*(desty-y)+(destx-x)*(destx-x)+(destz -z)*(destz -z)))));
            lastErr = 0;                //To avoid random_waypoint_node bouncing near the edge
        }
        usleep(1000);
    }
}

