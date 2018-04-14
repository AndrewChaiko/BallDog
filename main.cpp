#include <avr/io.h>
#include <util/delay.h>
#include "Output/Output.h"
#include <stdlib.h>
#include "FSM/FSM/FSM.h"

int main(void)
{
    FSM *fsm = new FSM();

    while(true)
    {
        float f = fsm->Update(100);
        _delay_ms(100);
    }

    return -1;
}
