#pragma once

class Output
{
  protected:
    int leg;
    bool state;

  public:
    virtual void TurnOn() = 0;
    virtual void TurnOff() = 0;
    virtual bool IsOn() = 0;
};
