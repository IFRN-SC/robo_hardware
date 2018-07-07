#ifndef MPU_ROBO_HARDWARE
#define MPU_ROBO_HARDWARE

#include <MPU6050_hardware.h>

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"
#endif


class MpuRoboHardware{

	// MPU control/status vars
	bool dmpReady;  				// set true if DMP init was successful
	uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
	uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
	uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
	uint16_t fifoCount;     // count of all bytes currently in FIFO
	uint8_t fifoBuffer[64]; // FIFO storage buffer

	// orientation/motion vars
	Quaternion q;           // [w, x, y, z]         quaternion container
	VectorInt16 aa;         // [x, y, z]            accel sensor measurements
	VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
	VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
	VectorFloat gravity;    // [x, y, z]            gravity vector
	float euler[3];         // [psi, theta, phi]    Euler angle container
	float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

	// packet structure for InvenSense teapot demo
	//uint8_t teapotPacket[14];

	static volatile bool mpuInterrupt;     // indicates whether MPU interrupt pin has gone high

	MPU6050 mpu;

	public:
	void configurar();
	void getData();

	private:
	
	static void dmpDataReady();

	void readData();
	void dataToYPR();	
	void printData();

};

#endif
