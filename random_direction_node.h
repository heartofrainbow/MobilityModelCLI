#ifndef RANDOM_DIRECTION_NODE_H
#define RANDOM_DIRECTION_NODE_H

#include "node.h"
#include "publicvar.h"

class random_direction_node : public node
{
public:
    void run();
    void update(double time);
    void reflect(int err);
    random_direction_node(int n);
private:
    bool reflected = false;
};

#endif // RANDOM_DIRECTION_NODE_H
