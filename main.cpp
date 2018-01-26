#include <avr/io.h>
#include <util/delay.h>
#include "EyeToSee/EyeToSee.h"
#include "MPU6050/MPU6050.h"

int main(void)
{
	EyeToSee bus;
	MPU6050 mpu;
	unsigned char c;
	bool success = bus.read(0x68, 0x02, &c);
	while(success)
	{
		_delay_ms(500);
		mpu.getAccelerationX();
	}

	return -1;
}