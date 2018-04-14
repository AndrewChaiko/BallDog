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
  size_t size = sizeof(states) / sizeof(states[0]);

  Transition tr = states[0]->Update(100);

  if (currState->type != tr.nextState)
  {
    for (size_t i = 0; i < size; i++)
    {
      if (states[i]->type == tr.nextState)
      {
        currState = states[i];
      }
    }
  }

  return tr.delay;
}

