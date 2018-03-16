#include "OutputB.h"
#include <avr/io.h>

#define OUT_REG DDRB
#define OUT_PORT PORTB

OutputB::OutputB(int a)
{
	this->leg = a;
	this->state = false;
	OUT_REG |= (1 << leg);
}

void OutputB::TurnOn()
{
	if(!state)
	{
		OUT_PORT |= (1 << leg);
		state = true;
	}
}

void OutputB::TurnOff()
{
	if(state)
	{
		OUT_PORT &= ~(1 << leg);
		state = false;
	}
}