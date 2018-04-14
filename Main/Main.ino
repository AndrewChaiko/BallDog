#include "FSM.h"

FSM *fsm;
float dt = 0;

void setup()
{
  fsm = new FSM();
}

void loop()
{
  dt = fsm->Update(dt);

  delay(dt);
}

