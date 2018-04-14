#include "AttractState.h"
#include "math.h"

AttractState::AttractState()
{
  this->output = new OutputB(5);
  this->type = VIBRO;
}

Transition AttractState::Update(long dt)
{
  Transition t;

  if (time > 5000)
  {
    time = 0;
    output->TurnOff();
    t.delay = 0;
    t.nextState = WAIT;
  }
  else
  {
    time += dt;
    output->TurnOn();
    t.delay = 100;
    t.nextState = VIBRO;
  }

  return t;
}
