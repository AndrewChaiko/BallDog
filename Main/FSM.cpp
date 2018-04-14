#include "FSM.h"
#include "stdlib.h"
#include "CheckMovementState.h"
#include "AttractState.h"

FSM::FSM()
{
  states = new State*[2];
  states[0] = new CheckMovementState();
  states[1] = new AttractState();
  currState = states[0];
}

float FSM::Update(float dt)
{
  int num = 2;

  Transition tr = currState->Update(dt);

  if (currState->GetType() != tr.nextState)
  {
    for (size_t i = 0; i < num; i++)
    {
      if (states[i]->GetType() == tr.nextState)
      {
        currState = states[i];
      }
    }
  }

  return tr.delay;
}

