#pragma once
#include "Transition.h"

class State
{
public:
    States type;
    virtual Transition Update(long) = 0;
};

