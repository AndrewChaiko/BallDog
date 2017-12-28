#include <avr/io.h>
#include <util/delay.h>
#include "utils.h"
#include "EyeToSee/EyeToSee.h"

int main(void)
{
	EyeToSee bus;
	unsigned char c;
	bool success = bus.read(0x68, 0x02, &c);
	while(success)
	{
		_delay_ms(500);
	}

	return -1;
}