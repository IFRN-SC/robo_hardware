#include <robo_hardware2.h> 
#include <Servo.h>

//*********PINOS PARA LIGAR MOTORES*********//
//    Motor1:
//pino1 PWM_RODA_DIREITA 	6
//pino2 SENTIDO_RODA_DIREITA 	7
//    Motor2:
//pino1 PWM_RODA_ESQUERDA 	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//*********PINOS PARA LIGAR MOTORES*********//

//*********PINOS PARA CONECTAR OS ENCODERS*********//
//    Motor1:
//pino1 ENCODER1_INTERRUPCAO 	18
//pino2 ENCODER1_DIRECAO	7
//    Motor2:
//pino1 ENCODER2_INTERRUPCAO 	19
//pino2 ENCODER2_DIRECAO	4
//*********PINOS PARA CONECTAR OS ENCODERS*********//



void setup(){
	//Configura o robo.
	robo.configurar(false);
}

void loop(){
	//Posiciona os dois motores 90 graus
	robo.acionarMotoresPos(90, 90);
	delay(1000);

	//Posiciona os dois motores 0 graus
	robo.acionarMotoresVel(0, 0);
	delay(1000);

	//Posiciona os dois motores -90 graus
	robo.acionarMotoresVel(-90, -90);
	delay(1000);

	//Posiciona os dois motores 0 graus
	robo.acionarMotoresVel(0, 0);
	delay(1000);
}

