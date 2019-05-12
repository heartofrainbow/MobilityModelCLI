#define M_PI 3.141592654
#include "node.h"
#include "publicvar.h"
#include <math.h>

void node::run(){

}
node::node(int n){
//    this->id = n;
}

double node::getx(){
    return x;
}
double node::gety(){
    return y;
}
double node::getz(){
    return z;
}
double node::getv(){
    return v;
}
double node::getd(){
    return d;
}
double node::getp(){
    return p;
}
void node::setx(double x){
    this->x = x;
}
void node::sety(double y){
    this->y = y;
}
void node::setz(double z){
    this->z = z;
}
void node::setv(double v){
    this->v = v;
}
void node::setd(double d){
    if(d<0){
        d += 2*M_PI;
    }else if(d>=2*M_PI){
        d -= 2*M_PI;
    }
    this->d = d;
}
void node::setp(double p){
    this->p = p;
}
bool node::isIn(double x, double a, double b){
    if(a > b){
        double tmp = a;
        a = b;
        b = tmp;
    }
    if(a <= x && x <= b){
        return true;
    }return false;
}

void node::calc(int id, double X, double Y, double Z){
    double _radiusEquator = 6378137;
    double _radiusPolar =  6356752.3142;
    double f = 1/298.257223563;
    double _eccentricitySquared = 2*f - pow(f,2);
    double p = sqrt(X*X + Y*Y);

    double theta = atan2(Z*_radiusEquator , (p*_radiusPolar));

    double eDashSquared = (_radiusEquator*_radiusEquator - _radiusPolar*_radiusPolar)/
                          (_radiusPolar*_radiusPolar);


    double sin_theta = sin(theta);

    double cos_theta = cos(theta);


    double latitude = atan( (Z + eDashSquared*_radiusPolar*sin_theta*sin_theta*sin_theta) /
                            (p - _eccentricitySquared*_radiusEquator*cos_theta*cos_theta*cos_theta) );

    double longitude = atan2(Y,X);


    double sin_latitude = sin(latitude);

    double N = _radiusEquator / sqrt( 1.0 - _eccentricitySquared*sin_latitude*sin_latitude);


    double height = p/cos(latitude) - N;
//    points->replace(id,QVector3D(latitude,longitude,height));
    //DoSomething
    points_wgs84[this->id] = glm::vec3(longitude,latitude,height);
}
