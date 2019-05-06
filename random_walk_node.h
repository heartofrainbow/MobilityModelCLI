//
// Created by nikki on 2019/4/17.
//

#ifndef MOBILITYMODELCLI_RANDOM_WALK_NODE_H
#define MOBILITYMODELCLI_RANDOM_WALK_NODE_H

#include <thread>
#include "node.h"
#include "publicvar.h"


class random_walk_node:public node{
public:
    void run();
    void update(double time);
    void reflect(int err);
    //node(QObject *parent=NULL);
    random_walk_node(int n);
};


#endif //MOBILITYMODELCLI_RANDOM_WALK_NODE_H
