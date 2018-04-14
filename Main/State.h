#pragma once
#include "Transition.h"

class State
{
public:
    virtual States GetType() = 0;
    virtual Transition Update(long) = 0;
};

