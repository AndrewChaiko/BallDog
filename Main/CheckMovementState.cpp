#include "CheckMovementState.h"
#include "math.h"

CheckMovementState::CheckMovementState()
{
  this->mpu = MPU6050();
}

States CheckMovementState::GetType()
{
  return WAIT;
}

Transition CheckMovementState::Update(long dt)
{
    float accelX = mpu.getGyroX();
    float accelY = mpu.getGyroY();
    float accelZ = mpu.getGyroZ();
    
    float len = sqrt(accelX * accelX + accelY * accelY + accelZ * accelZ);

    Transition t;
 
    if(len > 50 || check >= 5)
    {
        t.delay = 200;
        t.nextState = VIBRO;
        check = 0;
    }
    else
    {
        t.delay = 1000;
        t.nextState = WAIT;
        check++;
    }

    return t;
}
