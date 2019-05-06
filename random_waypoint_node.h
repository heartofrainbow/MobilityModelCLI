#ifndef RANDOM_WAYPOINT_NODE_H
#define RANDOM_WAYPOINT_NODE_H

#include "node.h"

class random_waypoint_node : public node
{
public:
    void run();
    void update(double time);
    void reflect();
    //node(QObject *parent=NULL);
    random_waypoint_node(int n);
private:
    double destx;
    double desty;
    double destz;
//    double dx,dy,dz;
};

#endif // RANDOM_WAYPOINT_NODE_H
