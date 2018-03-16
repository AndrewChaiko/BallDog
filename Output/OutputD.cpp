#include "OutputD.h"
#include <avr/io.h>

#define OUT_REG DDRD
#define OUT_PORT PORTD

OutputD::OutputD(int a)
{
	this->leg = a;
	this->state = false;
	OUT_REG |= (1 << leg);
}

void OutputD::TurnOn()
{
	if(!state)
	{
		OUT_PORT |= (1 << leg);
		state = true;
	}
}

void OutputD::TurnOff()
{
	if(state)
	{
		OUT_PORT &= ~(1 << leg);
		state = false;
	}
}