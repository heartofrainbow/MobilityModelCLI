#ifndef GAUSS_MARKOV_NODE_H
#define GAUSS_MARKOV_NODE_H


#include "node.h"
#include "publicvar.h"

class gauss_markov_node : public node
{
public:
    gauss_markov_node();
    void run();
    void update(double time);
    void reflect(int err);
    void setdmean(double dm);
    gauss_markov_node(int n);
private:
    double d_mean;
    double p_mean;
};

#endif // GAUSS_MARKOV_NODE_H
