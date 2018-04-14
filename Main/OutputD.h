#pragma once
#include "Output.h"

class OutputD : public Output
{
  public:
    OutputD(int);
    virtual void TurnOn();
    virtual void TurnOff();
    virtual bool IsOn();
};
