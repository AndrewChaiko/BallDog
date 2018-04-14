#pragma once

#include "State.h"
#include "States.h"

class FSM
{
public:
	FSM();
    float Update(float);

private:
    State **states;
    State *currState;
};
