#include "CorTcs34.h"
#define NUM_MAX_SENSORES_COR 10

Adafruit_TCS34725 CorTcs34::tcsCorHardware = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

int CorTcs34::pinosLigaDesliga[NUM_MAX_SENSORES_COR];
int CorTcs34::numPinos=0;

CorTcs34::CorTcs34(int pino){

	pinoLiga = pino;
	
	if(numPinos<NUM_MAX_SENSORES_COR){
		pinosLigaDesliga[numPinos] = pino;
		numPinos++;
	}
	
	
}

void CorTcs34::desligarOutrosSensores(){
	for(int i=0; i<numPinos; i++){
		digitalWrite(pinosLigaDesliga[i], LOW);
	}
}


void CorTcs34::ligarSensor(){
	desligarOutrosSensores();
	digitalWrite(pinoLiga, HIGH);
}
