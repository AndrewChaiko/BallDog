#ifndef MPU6050_H_
#define MPU6050_H_

#define MPU_ADDR 0x68

class MPU6050
{
private:
	void setupMPU();

public:
	MPU6050();
	float getAccelX();
	float getAccelY();
	float getAccelZ();
	float getGyroX();
	float getGyroY();
	float getGyroZ();
};

#endif