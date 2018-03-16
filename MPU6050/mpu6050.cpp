#include "mpu6050.h"
#include "../EyeToSee/EyeToSee.h"

EyeToSee bus;

MPU6050::MPU6050()
{
	setupMPU();
}

void MPU6050::setupMPU()
{
  	bus = EyeToSee();
	bus.write(MPU_ADDR, 0x6B, 0b00000000); // no sleep, no cycle, internal 8MHz resonator
	bus.write(MPU_ADDR, 0x1B, 0b00000000); // set gyro scale to ± 250 °/s
	bus.write(MPU_ADDR, 0x1C, 0b00000000); // set accl scale to ± 2g
}

// +- 2g
float MPU6050::getAccelX() {
	uint8_t low;
	uint8_t high;
  bus.read(MPU_ADDR, 0x3B, &low);
  bus.read(MPU_ADDR, 0x3C, &high);
  long accelX = low << 8 | high;
  float gForceX = accelX / 16384.0;
  return gForceX;
}

// +- 2g
float MPU6050::getAccelY() {
  uint8_t low;
  uint8_t high;
  bus.read(MPU_ADDR, 0x3D, &low);
  bus.read(MPU_ADDR, 0x3E, &high);
  long accelY = low << 8 | high;
  float gForceY = accelY / 16384.0;
  return gForceY;
}

// +- 2g
float MPU6050::getAccelZ() {
  uint8_t low;
  uint8_t high;
  bus.read(MPU_ADDR, 0x3F, &low);
  bus.read(MPU_ADDR, 0x40, &high);
  long accelZ = low << 8 | high;
  float gForceZ = accelZ / 16384.0;
  return gForceZ;
}

// +/- 250deg/s
float MPU6050::getGyroX() {
  uint8_t low;
  uint8_t high;
  bus.read(MPU_ADDR, 0x43, &low);
  bus.read(MPU_ADDR, 0x44, &high);
  long accelX = low << 8 | high;
  float gForceX = accelX / 131.0;
  return gForceX;
}

// +/- 250deg/s
float MPU6050::getGyroY() {
  uint8_t low;
  uint8_t high;
  bus.read(MPU_ADDR, 0x45, &low);
  bus.read(MPU_ADDR, 0x46, &high);
  long accelY = low << 8 | high;
  float gForceY = accelY / 131.0;
  return gForceY;
}

// +/- 250deg/s
float MPU6050::getGyroZ() {
  uint8_t low;
  uint8_t high;
  bus.read(MPU_ADDR, 0x47, &low);
  bus.read(MPU_ADDR, 0x48, &high);
  long accelZ = low << 8 | high;
  float gForceZ = accelZ / 131.0;
  return gForceZ;
}