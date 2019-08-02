#ifndef COR_TCS34_H
#define COR_TCS34_H

#include <Arduino.h>
#include "Adafruit_TCS34725.h"
#include "CorHardware.h"

class CorTcs34 : public CorHardware{
	private:
	static Adafruit_TCS34725 tcsCorHardware;

	static int pinosLigaDesliga[];
	static int numPinos;
	int pinoLiga;

	void ligarSensor();
	void desligaTodosSensores();
	
	public:

	void atualizarRGB();
	void config();
	CorTcs34(int pinLigaDesliga);

};

#endif
