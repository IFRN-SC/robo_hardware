#ifndef LED_H
#define LED_H

class Led{
	private:
	const int pinoLed;
	public:
	Led(const int pin):pinoLed(pin){}

	void config(){pinMode(pinoLed, OUTPUT);}
	void ligar(){ digitalWrite(pinoLed, HIGH);}
	void desligar(){digitalWrite(pinoLed, LOW);}

};

#endif
