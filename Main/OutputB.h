#pragma once
#include "Output.h"

class OutputB : public Output
{
  public:
    OutputB(int);
    virtual void TurnOn();
    virtual void TurnOff();
    virtual bool IsOn();
};
