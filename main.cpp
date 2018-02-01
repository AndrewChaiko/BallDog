#include <avr/io.h>
#include <util/delay.h>
#include "EyeToSee/EyeToSee.h"

#define MPU_ADDR 0x68

EyeToSee bus;

void setupMPU();
//void processAccelData();

int main(void)
{
	setupMPU();
	unsigned char c;
	bool success = bus.read(MPU_ADDR, 0x02, &c);
	while(success)
	{
		_delay_ms(500);
	}

	return -1;
}

void setupMPU()
{
	bus.write(MPU_ADDR, 0x6B, 0b00000000);
	bus.write(MPU_ADDR, 0x1B, 0b00000000);
	bus.write(MPU_ADDR, 0x1C, 0b00000000);
}

void recordAccelRegisters() {
	uint8_t low;
	uint8_t high;
  bus.read(MPU_ADDR, 0x3B, &low);
  bus.read(MPU_ADDR, 0x3C, &high);
  uint8_t accelX = high<<8|low; //Store first two bytes into accelX
  
  //byte accelY = Wire.read()<<8|Wire.read(); //Store middle two bytes into accelY
  //byte accelZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ
  //processAccelData();
}
/*/
void processAccelData(){
  uint8_t gForceX = accelX / 16384.0;
  uint8_t gForceY = accelY / 16384.0; 
  uint8_t gForceZ = accelZ / 16384.0;
}

void recordGyroRegisters() {
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x43); //Starting register for Gyro Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Gyro Registers (43 - 48)
  while(Wire.available() < 6);
  gyroX = Wire.read()<<8|Wire.read(); //Store first two bytes into accelX
  gyroY = Wire.read()<<8|Wire.read(); //Store middle two bytes into accelY
  gyroZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ
  processGyroData();
}

void processGyroData() {
  rotX = gyroX / 131.0;
  rotY = gyroY / 131.0; 
  rotZ = gyroZ / 131.0;
}/*/