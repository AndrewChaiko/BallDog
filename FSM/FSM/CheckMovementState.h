#pragma once
#include "State.h"
#include "mpu6050.h"

class CheckMovementState :
    public State
{
public:
    CheckMovementState();
    virtual Transition Update(long);

private:
    MPU6050 mpu;
};

