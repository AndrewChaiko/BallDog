#ifndef OUTPUTB_H_
#define OUTPUTB_H_

class OutputB
{
private:
	int leg;
	bool state;

public:
	OutputB(int);
	void TurnOn();
	void TurnOff();
};

#endif