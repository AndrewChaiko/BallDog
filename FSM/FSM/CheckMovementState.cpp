#include "CheckMovementState.h"
#include "math.h"

CheckMovementState::CheckMovementState()
{
  this->mpu = MPU6050();
  this->type = WAIT;
}

Transition CheckMovementState::Update(long dt)
{
    float accelX = mpu.getGyroX();
    float accelY = mpu.getGyroY();
    float accelZ = mpu.getGyroZ();
    
    float len = sqrt(accelX * accelX + accelY * accelY + accelZ * accelZ);

    Transition t;
 
    if(len > 100)
    {
        t.delay = len;
        t.nextState = WAIT;
    }
    else
    {
        t.delay = 100;
        t.nextState = VIBRO;
    }

    
    return t;
}
