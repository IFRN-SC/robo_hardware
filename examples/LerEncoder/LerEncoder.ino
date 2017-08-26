#include <encoder.h>
#include <Servo.h>

#define LED 13
#define PINO_INTERRUPCAO 2
#define PINO_DIRECAO 3

Encoder encoder(PINO_INTERRUPCAO,PINO_DIRECAO);

void blink_(){
  static bool active=true;

  (active) ? digitalWrite(LED,HIGH) : digitalWrite(LED,LOW);
  active = ! active;
}

void interrupcao(){
	encoder.calculaPulso();
	blink_();
}

void setup(){
	attachInterrupt(0, interrupcao, CHANGE);
	Serial.begin(9600);
	encoder.configurar();
	pinMode(LED, OUTPUT);
}

void loop(){
	encoder.calculaVelocidade();

	Serial.print("Velocidade: ");
	Serial.print(encoder.getVelocidade());
	Serial.print("\t Angulo Absoluto: ");
	Serial.println(encoder.getAnguloAbsoluto());
	delay(1000);

}
