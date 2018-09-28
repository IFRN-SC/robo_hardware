#ifndef ENCODER_I2C_H
#define ENCODER_I2C_H

#include <Arduino.h>
//#ifdef AVR_ATtiny85
//	#include <TinyWireS.h>
//#else
#include <Wire.h>
//#include <Conversao.h>
//#endif

#define DATA_SIZE 4
#define ENDERECO_ENCODER_DIR 0X26
#define ENDERECO_ENCODER_ESQ 0X27

class Conversao{
  public:
  long arrayToLong(const uint8_t* c){
    unsigned long temp=0;
 		for(int i=DATA_SIZE-1; i>=0; i--){
		  temp+=(unsigned long)c[i];
			if(i>0)
			  temp<<=8;  
		}
//  temp = (long)c[0];
    return (long)temp;
  }

  void longToArray(const long t, uint8_t* c){
    c[0] = t>>24;
    c[1] = t>>16;
    c[2] = t>>8;
    c[3] = t & 0xff;
  }
  
  void intToChar(const int t, uint8_t* c){
    c[0] = t>>8;
    c[1] = t & 0xff;
  }

};

Class Time{

	public:

	void initTime(){
		time = micros();
	}

	unsigned long timePassed(){
		return ( micros() - time );
	}
	private:
		unsigned long time;

};


class EncoderI2C{
	public:
		EncoderI2C(int address);

		long getPulsos();
		float getAngulo();
		float getAnguloRelativo();

		inline void setPulsosPorRevolucao(float ppr){pulsosPorRevolucao=ppr;}

	private:
		int ATtinyAddress;
		float pulsosPorRevolucao;
		Conversao conv;
		Timme tempoVel;
		long ultimosPulsos;

		long getData();

		float pulsosParaAngulo(long pulsos){return 360*(pulsos/pulsosPorRevolucao);}
};

#endif
