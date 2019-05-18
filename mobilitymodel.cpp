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
#include <unistd.h>     //Linux下用的头文件，主要是用于sleep相关函数，如果在Windows下编译，则应改为windows.h
#include <stdarg.h>
#include <string>
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
glm::vec3* points_wgs84;

//void mobilitymodel(const char* modeltype,...){
//
//}


//template <class ... Args>
//void mobilitymodel(Args... params) {
//    cout<<sizeof...(Args)<<endl;
//}

//void mobilitymodel() {
//    double type = 0;
//    //std::cout << "Hello, World!" << std::endl;
//    cout<<"请选择节点移动模型类型，仅输入一位阿拉伯数字（不含括号）后按回车："<<endl;
//    cout<<"[1]随机走动模型\t\tRandom Walk Mobility Model"<<endl<<"[2]随机方向移动模型\t\tRandom Direction Mobility Model"
//        <<endl<<"[3]随机路点移动模型\t\tRandom Waypoint Mobility Model"<<endl<<"[4]高斯-马尔科夫移动模型\t\t Gauss Markov Mobility Model"<<endl;
//    cin>>type;
//    running = true;
//    int num_threads = 5;
////    glm::vec3 points[num_threads];
//    points = new glm::vec3[num_threads];
//    thread t[num_threads];
//    if(type == 1){
//        for(int i=0;i<num_threads;i++){
//            t[i] = thread(&random_walk_node::run,new random_walk_node(i));
//        }
//    }else if(type == 2){
//        for(int i=0;i<num_threads;i++){
//            t[i] = thread(&random_direction_node::run,new random_direction_node(i));
//        }
//    }else if(type == 3){
//        for(int i=0;i<num_threads;i++){
//            t[i] = thread(&random_waypoint_node::run, new random_waypoint_node(i));
//        }
//    }else if(type == 4){
//        for(int i=0;i<num_threads;i++){
//            t[i] = thread(&gauss_markov_node::run, new gauss_markov_node(i));
//        }
//    }else{
//        cout<<"输入有误，程序已退出，请重新运行"<<endl;
//    }
//
//    thread pointsDisplayer([]{          //示例线程，每隔1s便输出第一个节点的位置，可按需修改
//        while(true){
//            cout<<points[0].x<<"\t"<<points[0].y<<"\t"<<points[0].z<<endl;
//            usleep(1000000);
//        }
//    });
//
//    for (int j = 0; j < num_threads; ++j) {
//        t[j].join();
//    }
//    pointsDisplayer.join();
//    delete points;
//}

void mobilitymodel(...){
    cout<<"所给参数不正确，请重新运行！"<<endl;
    return;
}
void mobilitymodel(string str, int num_threads, double xmin, double xmax, double ymin, double ymax, double zmin, double zmax, double vmin, double vmax, double m_interval, bool isGeo){
//    if(str != "rw" || str != "rd" || str != "rwp"){
    if(str.compare("rw")!= 0 && str.compare("rd")!=0 && str.compare("rwp")!=0){ //compare函数，相同则返回0，不同则返回一个非0的数（不一定是1）
//        cout<<"checkpoint 1 failed"<<endl;
        mobilitymodel();
        return;
    }
    if(isGeo == true){
        double a[8][3];
        rev_calc(XMIN,YMIN,ZMIN,a[0]);
        rev_calc(XMIN,YMIN,ZMAX,a[1]);
        rev_calc(XMIN,YMAX,ZMIN,a[2]);
        rev_calc(XMIN,YMAX,ZMAX,a[3]);
        rev_calc(XMAX,YMIN,ZMIN,a[4]);
        rev_calc(XMAX,YMIN,ZMAX,a[5]);
        rev_calc(XMAX,YMAX,ZMIN,a[6]);
        rev_calc(XMAX,YMAX,ZMAX,a[7]);
        double min = a[0][0];
        double max = a[0][0];
        for(int i=0; i<8;i++){
            if(a[0][i] < min) min = a[0][i];
            if(a[0][i] > max) max = a[0][i];
        }
        XMIN = min;
        XMAX = max;
//        double m_x[2] = {min, max};
//        min = a[1][0];
//        max = a[1][0];
        for(int i=0; i<8;i++){
            if(a[1][i] < min) min = a[1][i];
            if(a[1][i] > max) max = a[1][i];
        }
        YMIN = min;
        YMAX = max;
//        double m_y[2] = {min,max};
//        min = a[2][0];
//        max = a[2][0];
        for(int i=0; i<8;i++){
            if(a[2][i] < min) min = a[2][i];
            if(a[2][i] > max) max = a[2][i];
        }
        ZMIN = min;
        ZMAX = max;
//        double m_z[2] = {min,max};
    }
    else{
        XMIN = xmin;
        XMAX = xmax;
        YMIN = ymin;
        YMAX = ymax;
        ZMIN = zmin;
        ZMAX = zmax;
    }
    nNodes = num_threads;
    VMIN = vmin;
    VMAX = vmax;
    interval = m_interval;
    points = new glm::vec3[num_threads];
    points_wgs84 = new glm::vec3[num_threads];
    thread t[num_threads];
    running = true; //关键语句，如果该变量为false则节点都原地不动，各线程结束
    //在编写程序时，请记得在程序运行结束后的处理语句中将running设为false以退出循环！
    if(str.compare("rw")== 0){
        cout<<"节点移动模型：随机走动模型(Random Walk Mobility Model)"<<endl;
//        cout<<"节点数目："<<nNodes<<endl;
//        cout<<"位置范围：X:["<<XMIN<<","<<XMAX<<"] Y:["<<YMIN<<","<<YMAX<<"] Z:["<<ZMIN<<","<<ZMAX<<"]"<<endl;
//        cout<<"速度范围：["<<VMIN<<","<<VMAX<<"]"<<endl;
        for(int i=0;i<num_threads;i++){
            t[i] = thread(&random_walk_node::run,new random_walk_node(i));
        }
//        cout<<"random walk threads created"<<endl;
    }else if(str.compare("rd")== 0){
        cout<<"节点移动模型：随机方向移动模型(Random Direction Mobility Model)"<<endl;
        for(int i=0;i<num_threads;i++){
            t[i] = thread(&random_direction_node::run,new random_direction_node(i));
        }
    }else if(str.compare("rwp")== 0){
        cout<<"节点移动模型：随机路点移动模型(Random Waypoint Mobility Model)"<<endl;
        for(int i=0;i<num_threads;i++){
            t[i] = thread(&random_waypoint_node::run, new random_waypoint_node(i));
        }
    }else{
        mobilitymodel();
        return;
    }
    cout<<"节点数目："<<nNodes<<endl;
    cout<<"时间间隔:"<<interval<<endl;
    cout<<"位置范围：X:["<<XMIN<<","<<XMAX<<"] Y:["<<YMIN<<","<<YMAX<<"] Z:["<<ZMIN<<","<<ZMAX<<"]"<<endl;
    cout<<"速度范围：["<<VMIN<<","<<VMAX<<"]"<<endl;
    thread pointsDisplayer([]{          //示例线程，每隔1s便输出第一个节点的位置，可按需修改
         while(true){
//            cout<<points[0].x<<"\t"<<points[0].y<<"\t"<<points[0].z<<endl;
             cout<<"X="<<points[0].x<<"\tY="<<points[0].y<<"\tZ="<<points[0].z<<"\tLongitude="<<points_wgs84[0].x<<"\tLatitude="<<points_wgs84[0].y<<"\tHeight="<<points_wgs84[0].z<<endl;
            usleep(1000000);
         }
    });

    for (int j = 0; j < num_threads; j++) {
        t[j].join();
    }
    pointsDisplayer.join();
}

void mobilitymodel(string str, int num_threads, double xmin, double xmax, double ymin, double ymax, double zmin, double zmax, double vmin, double vmax, double m_vmean, double m_dmean, double m_pmean, double m_alpha, bool isGeo){
    if(str.compare("gm")!= 0 ){ //compare函数，相同则返回0，不同则返回一个非0的数（不一定是1）
//        cout<<"checkpoint 1 failed"<<endl;
        mobilitymodel();
        return;
    }
    if(isGeo == true){
        double a[8][3];
        rev_calc(XMIN,YMIN,ZMIN,a[0]);
        rev_calc(XMIN,YMIN,ZMAX,a[1]);
        rev_calc(XMIN,YMAX,ZMIN,a[2]);
        rev_calc(XMIN,YMAX,ZMAX,a[3]);
        rev_calc(XMAX,YMIN,ZMIN,a[4]);
        rev_calc(XMAX,YMIN,ZMAX,a[5]);
        rev_calc(XMAX,YMAX,ZMIN,a[6]);
        rev_calc(XMAX,YMAX,ZMAX,a[7]);
        double min = a[0][0];
        double max = a[0][0];
        for(int i=0; i<8;i++){
            if(a[0][i] < min) min = a[0][i];
            if(a[0][i] > max) max = a[0][i];
        }
        XMIN = min;
        XMAX = max;
//        double m_x[2] = {min, max};
        min = a[1][0];  //重新初始化min和max这两个临时变量，下同
        max = a[1][0];
        for(int i=0; i<8;i++){
            if(a[1][i] < min) min = a[1][i];
            if(a[1][i] > max) max = a[1][i];
        }
        YMIN = min;
        YMAX = max;
//        double m_y[2] = {min,max};
        min = a[2][0];
        max = a[2][0];
        for(int i=0; i<8;i++){
            if(a[2][i] < min) min = a[2][i];
            if(a[2][i] > max) max = a[2][i];
        }
        ZMIN = min;
        ZMAX = max;
//        double m_z[2] = {min,max};
    }
    else{
        XMIN = xmin;
        XMAX = xmax;
        YMIN = ymin;
        YMAX = ymax;
        ZMIN = zmin;
        ZMAX = zmax;
    }
    nNodes = num_threads;

    VMIN = vmin;
    VMAX = vmax;
    vmean = m_vmean;
    dmean = m_dmean;
    pmean = m_pmean;
    alpha = m_alpha;
    points = new glm::vec3[num_threads];
    points_wgs84 = new glm::vec3[num_threads];
    thread t[num_threads];
    running = true; //关键语句，如果该变量为false则节点都原地不动，各线程结束
    //在编写程序时，请记得在程序运行结束后的处理语句中将running设为false以退出循环！
    cout<<"节点移动模型：高斯-马尔科夫移动模型(Gauss Markov Mobility Model)"<<endl;
    for(int i=0;i<num_threads;i++){
            t[i] = thread(&gauss_markov_node::run, new gauss_markov_node(i));
    }
    cout<<"节点数目："<<nNodes<<endl;
//    cout<<"时间间隔:"<<interval<<endl;
    cout<<"位置范围：X:["<<XMIN<<","<<XMAX<<"] Y:["<<YMIN<<","<<YMAX<<"] Z:["<<ZMIN<<","<<ZMAX<<"]"<<endl;
    cout<<"速度范围：["<<VMIN<<","<<VMAX<<"]"<<endl;
    cout<<"速度均值："<<vmean<<" 方向角均值"<<dmean<<" 仰角均值"<<pmean<<endl;
    cout<<"相关系数α="<<alpha<<endl;
    thread pointsDisplayer([]{          //示例线程，每隔1s便输出第一个节点的位置，可按需修改
        while(true){
            cout<<"X="<<points[0].x<<"\tY="<<points[0].y<<"\tZ="<<points[0].z<<"\tLongitude="<<points_wgs84[0].x<<"\tLatitude="<<points_wgs84[0].y<<"\tHeight="<<points_wgs84[0].z<<endl;
            usleep(1000000);
        }
    });

    for (int j = 0; j < num_threads; j++) {
        t[j].join();
    }
    pointsDisplayer.join();

}

void rev_calc(double longitude, double latitude, double height, double* res){
    double _radiusEquator = 6378137;
    double _radiusPolar =  6356752.3142;
    double f = 1/298.257223563;
    double _eccentricitySquared = 2*f - pow(f,2);
    double N = _radiusEquator / sqrt( 1.0 - _eccentricitySquared*sin(latitude)*sin(latitude));
    double X = (N + height)*cos(latitude)*cos(longitude);
    double Y = (N + height)*cos(latitude)*sin(longitude);
    double Z = (N*(1-_eccentricitySquared) + height)*sin(latitude);
    res[0] = X;
    res[1] = Y;
    res[2] = Z;
}
