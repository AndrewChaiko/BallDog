#pragma once
#include "State.h"
#include "Output.h"

class AttractState :
    public State
{
public:
    AttractState();
    virtual Transition Update(long);

private:
    OutputB *output;
    long time;
};

