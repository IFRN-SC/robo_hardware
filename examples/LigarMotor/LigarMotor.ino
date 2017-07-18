#include <robo_hardware.h> 
#include <Servo.h>

//*********PINOS PARA LIGAR MOTORES*********//
//    Motor1:
//pino1 PWM_RODA_DIREITA 	6
//pino2 SENTIDO_RODA_DIREITA 	7
//    Motor2:
//pino1 PWM_RODA_ESQUERDA 	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//*********PINOS PARA LIGAR MOTORES*********//


void setup(){
	//Configura o robo.
	robo.configurar(false);
}

void loop(){
	//Liga os dois motores com 50% da valocidade maxima
	robo.acionarMotores(50, 50);
	delay(1000);

	//Desliga os dois motores
	robo.acionarMotores(0, 0);
	delay(1000);

	//Liga os dois motores com 50% da velocidade maxima so que no sentido oposto
	robo.acionarMotores(-50, -50);
	delay(1000);

	//Desliga os dois motores
	robo.acionarMotores(0, 0);
	delay(1000);
}

