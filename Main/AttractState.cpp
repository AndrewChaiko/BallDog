#include "AttractState.h"
#include "math.h"
#include "OutputD.h"

AttractState::AttractState()
{
  this->vibro = new OutputD(4);
}

States AttractState::GetType()
{
  return VIBRO;
}

Transition AttractState::Update(long dt)
{
  Transition t;

  if(vibro->IsOn())
  {
    vibro->TurnOff();
    t.delay = 100;
    t.nextState = WAIT;
  }
  else
  {
    vibro->TurnOn();
    t.delay = 200;
    t.nextState = VIBRO;
  }

  return t;
}
