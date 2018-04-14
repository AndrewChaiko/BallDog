#include "State.h"
#include "stdlib.h"

Transition State::Update(long ms)
{
    Transition t;
    t.delay = 1234;
    t.nextState = START;
    return t;
}

