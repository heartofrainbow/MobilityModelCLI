//
// Created by nikki on 2019/5/7.
//

#include "mobilitymodel.h"
#include "glm/vec3.hpp"
#include <iostream>
#include "publicvar.h"
#include "node.h"
#include "random_walk_node.h"
#include "random_direction_node.h"
#include "random_waypoint_node.h"
#include "gauss_markov_node.h"
#include <iostream>
#include <random>
#include <math.h>
#include <iomanip>
#include <chrono>
#include <thread>
#include <unistd.h>
#include "glm/vec3.hpp"



double XMAX = 100;
double XMIN = 0;
double YMAX = 100;
double YMIN = 0;
double ZMIN = 0;
double ZMAX = 100;
double VMIN = 10;
double VMAX = 20;
double vmean = 15;
double dmean = 3.141592654;
double pmean = 1.570796327;
double alpha = 0.5;
double xbuffer = (XMAX-XMIN)/10;
double ybuffer = (YMAX-YMIN)/10;
double zbuffer = (ZMAX-ZMIN)/10;

bool running = false;
int nNodes = 0;
int type = 0;   //1=RandomWalk, 2=RandomDirection, 3=RandomWaypoint, 4=Gauss-markov
double interval = 2;
random_device rd;
default_random_engine e(rd());

glm::vec3* points;

void mobilitymodel() {
    double type = 1;
    //std::cout << "Hello, World!" << std::endl;
    cout<<"请选择节点移动模型类型，仅输入一位阿拉伯数字（不含括号）后按回车："<<endl;
    cout<<"[1]随机走动模型\t\tRandom Walk Mobility Model"<<endl<<"[2]随机方向移动模型\t\tRandom Direction Mobility Model"
        <<endl<<"[3]随机路点移动模型\t\tRandom Waypoint Mobility Model"<<endl<<"[4]高斯-马尔科夫移动模型\t\t Gauss Markov Mobility Model"<<endl;
    cin>>type;
    running = true;
    int num_threads = 5;
//    glm::vec3 points[num_threads];
    points = new glm::vec3[num_threads];
    thread t[num_threads];
    if(type == 1){
        for(int i=0;i<num_threads;i++){
            t[i] = thread(&random_walk_node::run,new random_walk_node(i));
        }
    }else if(type == 2){
        for(int i=0;i<num_threads;i++){
            t[i] = thread(&random_direction_node::run,new random_direction_node(i));
        }
    }else if(type == 3){
        for(int i=0;i<num_threads;i++){
            t[i] = thread(&random_waypoint_node::run, new random_waypoint_node(i));
        }
    }else if(type == 4){
        for(int i=0;i<num_threads;i++){
            t[i] = thread(&gauss_markov_node::run, new gauss_markov_node(i));
        }
    }else{
        cout<<"输入有误，程序已退出，请重新运行"<<endl;
    }

    thread pointsDisplayer([]{          //示例线程，每隔1s便输出第一个节点的位置，可按需修改
        while(true){
            cout<<points[0].x<<"\t"<<points[0].y<<"\t"<<points[0].z<<endl;
            usleep(1000000);
        }
    });

    for (int j = 0; j < num_threads; ++j) {
        t[j].join();
    }
    pointsDisplayer.join();
    delete points;
}