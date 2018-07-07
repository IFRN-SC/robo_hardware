#include "MpuRoboHardware.h"

#define INTERRUPT_PIN 2  // use pin 2 on Arduino Uno & most boards

volatile bool MpuRoboHardware::mpuInterrupt=false;

void MpuRoboHardware::configurar(){
	dmpReady = false;
//	teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };
	mpuInterrupt = false;

  // join I2C bus (I2Cdev library doesn't do this automatically)
  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
      Wire.begin();
      Wire.setClock(400000); // 400kHz I2C clock. Comment this line if having compilation difficulties
  #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
      Fastwire::setup(400, true);
  #endif

  Serial.begin(115200);

  Serial.println(F("Initializing I2C devices..."));

  mpu.initialize();
  pinMode(INTERRUPT_PIN, INPUT);

  // verify connection
  Serial.println(F("Testing device connections..."));
  Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

  // wait for ready
  Serial.println(F("\nSend any character to begin DMP programming and demo: "));
  while (Serial.available() && Serial.read()); // empty buffer
  while (!Serial.available());                 // wait for data
  while (Serial.available() && Serial.read()); // empty buffer again

  // load and configure the DMP
  Serial.println(F("Initializing DMP..."));
  devStatus = mpu.dmpInitialize();

  // supply your own gyro offsets here, scaled for min sensitivity
  mpu.setXGyroOffset(220);
  mpu.setYGyroOffset(76);
  mpu.setZGyroOffset(-85);
  mpu.setZAccelOffset(1788); // 1688 factory default for my test chip


  // make sure it worked (returns 0 if so)
  if (devStatus == 0) {
      // turn on the DMP, now that it's ready
      Serial.println(F("Enabling DMP..."));
      mpu.setDMPEnabled(true);

      // enable Arduino interrupt detection
      Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
      attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
      mpuIntStatus = mpu.getIntStatus();

      // set our DMP Ready flag so the main loop() function knows it's okay to use it
      Serial.println(F("DMP ready! Waiting for first interrupt..."));
      dmpReady = true;

      // get expected DMP packet size for later comparison
      packetSize = mpu.dmpGetFIFOPacketSize();
  } else {
      // ERROR!
      // 1 = initial memory load failed
      // 2 = DMP configuration updates failed
      // (if it's going to break, usually the code will be 1)
      Serial.print(F("DMP Initialization failed (code "));
      Serial.print(devStatus);
      Serial.println(F(")"));
  }

}

Ypr MpuRoboHardware::getData(){
	Ypr y;
  // if programming failed, don't try to do anything
  if (!dmpReady) return y;

  // wait for MPU interrupt or extra packet(s) available
  if (mpuInterrupt || fifoCount >= packetSize) {

		// reset interrupt flag and get INT_STATUS byte
		mpuInterrupt = false;
		mpuIntStatus = mpu.getIntStatus();

		// get current FIFO count
		fifoCount = mpu.getFIFOCount();

		// check for overflow (this should never happen unless our code is too inefficient)
		if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
		    // reset so we can continue cleanly
		    mpu.resetFIFO();
//		    Serial.println(F("FIFO overflow!  "));

		// otherwise, check for DMP data ready interrupt (this should happen frequently)
		} 
		else if (mpuIntStatus & 0x02) {

			readData();
			dataToYPR();
	 		printData();
		}
	}
	y.y = ypr[0];
	y.p = ypr[1];
	y.r = ypr[2];
	return y;
}

void MpuRoboHardware::dmpDataReady() {
  mpuInterrupt = true;
}

void MpuRoboHardware::readData(){
	// wait for correct available data length, should be a VERY short wait
//	while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
	fifoCount = mpu.getFIFOCount();
	if(fifoCount >= packetSize){
		// read a packet from FIFO
		mpu.getFIFOBytes(fifoBuffer, packetSize);
	
		// track FIFO count here in case there is > 1 packet available
		// (this lets us immediately read more without waiting for an interrupt)
		fifoCount -= packetSize;
	}
}

void MpuRoboHardware::dataToYPR(){
  mpu.dmpGetQuaternion(&q, fifoBuffer);
  mpu.dmpGetGravity(&gravity, &q);
  mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
}

void MpuRoboHardware::printData(){
	/*
  Serial.print("ypr\t");
  Serial.print(ypr[0] * 180/M_PI);
  Serial.print("\t");
  Serial.print(ypr[1] * 180/M_PI);
  Serial.print("\t");
  Serial.println(ypr[2] * 180/M_PI);
	*/
}
