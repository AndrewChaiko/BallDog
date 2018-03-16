#ifndef OUTPUTD_H_
#define OUTPUTD_H_

class OutputD
{
private:
	int leg;
	bool state;

public:
	OutputD(int);
	void TurnOn();
	void TurnOff();
};

#endif