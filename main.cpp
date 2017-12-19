#include <avr/io.h>
#include <util/delay.h>
#include "utils.h"
#include "mpu6050/mpu6050.h"

int main(void)
{
	mpu6050_init();

	while(1)
	{
		_delay_ms(500);
	}

	return -1;
}