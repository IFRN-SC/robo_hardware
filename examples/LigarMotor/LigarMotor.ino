#include <robo_hardware.h> 
#include <Servo.h>

//*********PINOS PARA LIGAR MOTORES*********//
//    Motor1:
//pino1 PWM_RODA_DIREITA 	6
//pino2 SENTIDO_RODA_DIREITA 	8
//    Motor2:
//pino1 PWM_RODA_ESQUERDA 	5
//pino2 SENTIDO_RODA_ESQUERDA	7
//*********PINOS PARA LIGAR MOTORES*********//


void setup(){
	robo.configurar(false);
}

void loop(){
	robo.acionarMotores(50, 50);
	delay(1000);
	robo.acionarMotores(0, 50);
	delay(1000);
	robo.acionarMotores(0, 0);
	delay(1000);
	robo.acionarMotores(-50, 0);
	delay(1000);
	robo.acionarMotores(-50, -50);
	delay(1000);
}

