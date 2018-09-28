#include "EncoderI2C.h"

EncoderI2C::EncoderI2C(int address){
	ultimosPulsos = 0;
	pulsosPorRevolucao=224.4;
	Wire.begin();
	ATtinyAddress= address;
}

long EncoderI2C::getData(){

	uint8_t byteArray[DATA_SIZE];

	for(int i=0; i<DATA_SIZE; i++ ){
		Wire.beginTransmission(ATtinyAddress);
		Wire.write(i);
		Wire.endTransmission();
		Wire.requestFrom(ATtinyAddress, 1);

		while(Wire.available()){ 
				byteArray[i] = Wire.read(); 
		}
	}
	return conv.arrayToLong(byteArray);
}

float EncoderI2C::getAngulo(){
	return pulsosParaAngulo(getPulsos());
}

long EncoderI2C::getPulsos(){
	long pulsos = getData();
	ultimosPulsos = pulsos;
	return pulsos;
}

float EncoderI2C::getAnguloRelativo(){
	long pulsos=ultimosPulsos;
	tempoVel.initTime();
	return pulsosParaAngulo(getPulsos() - pulsos);
}

float EncoderI2C::getVel(){
	float tempo = tempoVel.timePassed();
	float ang = getAnguloRelativo();

	return ang/(tempo/1000.0);
}
