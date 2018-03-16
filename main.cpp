#include <avr/io.h>
#include <util/delay.h>
#include "Output/OutputB.h"
#include "Output/OutputD.h"
#include "avr/sleep.h"
#include "stdlib.h"
#include "MPU6050/mpu6050.h"

OutputB led = OutputB(5);     // B5 output for led (built in)
OutputD vibro = OutputD(5);   // D5 output for vibro
MPU6050 mpu = MPU6050();

int main(void)
{
  while(true)
  {
	   float accelX = mpu.getGyroX();
     if(abs(accelX) > 100)
     {
      led.TurnOn();
     }
     else
     {
      led.TurnOff();
     }

		_delay_ms(100);
	}

	return -1;
}
