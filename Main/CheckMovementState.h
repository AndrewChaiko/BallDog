#pragma once
#include "State.h"
#include "mpu6050.h"

class CheckMovementState :
    public State
{
public:
    CheckMovementState();
    virtual Transition Update(long);
    virtual States GetType();

private:
    MPU6050 mpu;
    int check;
};

