#ifndef ENCODER_I2C_H
#define ENCODER_I2C_H

#include <Arduino.h>
//#ifdef AVR_ATtiny85
//	#include <TinyWireS.h>
//#else
#include <Wire.h>
//#include <Conversao.h>
//#endif

#include <math.h>

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

class Time{

	public:

	void initTime(){
		time = micros();
	}

	long timePassed(){
		diferencaTempo = (micros() - time );
		return diferencaTempo;
	}
	private:
		unsigned long time;
		int diferencaTempo;

};


class EncoderI2C{
	public:
		EncoderI2C(int address);

		long getPulsos();
		float getAngulo();
		float getAnguloRelativo();
		float getVel();

		inline void setPulsosPorRevolucao(float ppr){pulsosPorRevolucao=ppr;}

	private:
		int ATtinyAddress;
		float pulsosPorRevolucao;
		Conversao conv;
		Time tempoVel;
		long ultimosPulsos;

		long getData();

		inline float pulsosParaAngulo(long pulsos){return 360*(pulsos/pulsosPorRevolucao);}
		inline float radianoToGraus(float r){return 360*r/(2*M_PI);}
		inline float grausToRadiano(float g){return 2*M_PI*g/(360);}
};

#endif
