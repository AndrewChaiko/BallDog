#pragma once
#include "States.h"

typedef struct
{
    long delay;
    States nextState;
} Transition;
