#define M_PI 3.141592654
#include "gauss_markov_node.h"
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

gauss_markov_node::gauss_markov_node(int n):node(n){
    this->id = n;
}
void gauss_markov_node::setdmean(double dm){
    if(dm<0){
        dm += 2*M_PI;
    }else if(dm>=2*M_PI){
        dm -= 2*M_PI;
    }
    dmean = dm;
}

void gauss_markov_node::update(double time){   //parameter time is in second
    if (this->x <= XMIN) {      //If gauss_markov_node hit the XMIN bound then reflect
        this->x = 2*XMIN - this->x;     //Fix out of bound bug: if OutOfBound then mirror
        reflect(1);
    }else if(this->x >= XMAX){  //If gauss_markov_node hit the XMAX bound then reflect
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
//    if(this->x >= (XMAX-xbuffer)){
//        if(this->y >= (YMAX-ybuffer)) this->setdmean(1.25*M_PI);
//        else if(this->y <= (YMIN+ybuffer)) this->setdmean(0.75*M_PI);
//        else this->setdmean(M_PI);
//    }else if(this->x <= (XMIN+xbuffer)){
//        if(this->y >= (YMAX-ybuffer)) this->setdmean(1.75*M_PI);
//        else if(this->y <= (YMIN+ybuffer)) this->setdmean(0.25*M_PI);
//        else this->setdmean(0);
//    }else {
//        if(this->y >= (YMAX-ybuffer)) this->setdmean(1.5*M_PI);
//        else if(this->y <= (YMIN+ybuffer)) this->setdmean(0.5*M_PI);
//    }
    this->x += this->getv()*cos(this->getd())*sin(this->getp())*time;
    this->y += this->getv()*sin(this->getd())*sin(this->getp())*time;
    this->z += this->getv()*cos(this->getp())*time;
    printf("ID=%d\t\tX=%f\t\tY=%f\t\tZ=%f\n",this->id,this->x,this->y,this->z);
//    series->dataProxy()->resetArray(points);
}

void gauss_markov_node::reflect(int err){      //err: 1 XMIN 2 XMAX 3 YMIN 4 YMAX
    double dd = this->getd();
    double pp = this->getp();
    if (err == lastErr) {           //In case gauss_markov_node reflect forever near an edge
        return;
    }
    if (err ==1 || err == 2) {
        //this->setd(M_PI-dd);
        this->d = M_PI-dd;
        //this->setdmean(M_PI-dmean);
        d_mean = M_PI-d_mean;
        this->lastErr = err;
    } else if (err ==3 || err ==4) {
        //this->setd(2*M_PI-dd);
        this->d = 2*M_PI-dd;
        //this->setdmean(-dmean);
        d_mean = -d_mean;
        this->lastErr = err;
    } else if(err == 5 || err == 6){
        this->p = M_PI - pp;
        p_mean = M_PI - p_mean;
        this->lastErr = err;
    }
}

void gauss_markov_node::run(){
    d_mean = dmean;
    p_mean = pmean;
    uniform_real_distribution<double> randomX(XMIN,XMAX);
    uniform_real_distribution<double> randomY(YMIN,YMAX);
    uniform_real_distribution<double> randomZ(ZMIN,ZMAX);
    uniform_real_distribution<double> randomVel(VMIN,VMAX);
    uniform_real_distribution<double> randomDir(0,2*M_PI);
    uniform_real_distribution<double> randomPitch(0,M_PI);
    normal_distribution<double> randomVr(0,1);
    normal_distribution<double> randomDr(0,1);
    normal_distribution<double> randomPr(0,1);
    x = randomX(e);
    y = randomY(e);
    z = randomZ(e);
    v = randomVel(e);
    this->setd(randomDir(e));
    this->setp(randomPitch(e));
    //qDebug()<<this->id<<"\t"<<this->getd()<<endl;
//    double timeout = interval;        //Change gauss_markov_node speed&direction every $interval second
    std::chrono::duration<double, std::micro> tmpTime;     //Time between current and lastshow
    std::chrono::duration<double, std::micro> loopTime;    //Time used for a single loop
    std::chrono::duration<double, std::micro> changeTime;
    std::chrono::duration<double, std::micro> wholeTime;
    high_resolution_clock::time_point loopEndTime;
    cout<<setiosflags(ios::fixed);
    high_resolution_clock::time_point baseTime = high_resolution_clock::now();
    high_resolution_clock::time_point lastChange = high_resolution_clock::now();    //Time when gauss_markov_node info changed
    high_resolution_clock::time_point  lastUpdate = lastChange;   //Time when gauss_markov_node loc updated
    high_resolution_clock::time_point lastShow = lastUpdate;    //Time when gauss_markov_node info shown
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
        //qDebug()<<this->getd()<<endl;
        v = alpha*v + (1-alpha)*vmean + sqrt(1-alpha*alpha)*randomVr(e);
        d = alpha*d + (1-alpha)*d_mean + sqrt(1-alpha*alpha)*randomDr(e);
        p = alpha*p + (1-alpha)*p_mean + sqrt(1-alpha*alpha)*randomPr(e);
        this->lastErr = 0;
        lastUpdate = high_resolution_clock::now();
        currentTime = high_resolution_clock::now();
        changeTime = currentTime-lastChange;
//        if(changeTime.count() > timeout*1e6){       //Regenerate gauss_markov_node info every $timeout second
//            lastChange = currentTime;
////            this->setv(randomVel(e));
////            this->setd(randomDir(e));

//            lastErr = 0;                //To avoid gauss_markov_node bouncing near the edge
//        }
        usleep(1000);
    }
}

