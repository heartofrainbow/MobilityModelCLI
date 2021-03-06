//
// Created by nikki on 2019/5/7.
//

#ifndef MOBILITYMODELCLI_MOBILITYMODEL_H
#define MOBILITYMODELCLI_MOBILITYMODEL_H

#include <iostream>
#include <stdarg.h>

//class mobilitymodel {
//
//};


using namespace std;

void mobilitymodel(string str, int nodes, double xmin, double xmax, double ymin, double ymax, double zmin, double zmax, double vmin, double vmax, double m_interval=2.0, bool isGeo = true);
void mobilitymodel(string str, int nodes, double xmin, double xmax, double ymin, double ymax, double zmin, double zmax, double vmin, double vmax, double m_vmean, double m_dmean, double m_pmean, double m_alpha, bool isGeo = true);
void mobilitymodel(...);
void rev_calc(double longitude, double latitude, double height, double* res);//将经纬高（WGS84）转化为XYZ

#endif //MOBILITYMODELCLI_MOBILITYMODEL_H
