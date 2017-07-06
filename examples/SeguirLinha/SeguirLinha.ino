#include <robo_hardware.h> 
#include <Servo.h>

//*************PINOS PARA LIGAR MOTORES*************//
//   Motor direito:
//pino1 PWM_RODA_DIREITA	6
//pino2 SENTIDO_RODA_DIREITA	8
//   Motor esquerdo:
//pino1 PWM_RODA_ESQUERDA	5
//pino2 SENTIDO_RODA_ESQUERDA	7
//*********PINOS PARA LIGAR MOTORES*********//

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR_LINHA_ESQUERDO			A0
//
//SENSOR_LINHA_DIREITO			A1
//
//*********PINOS PARA SENSORES REFLETANCIA*********//

#define CINZA 50

float valor_sensor_dir;
float valor_sensor_esq;

void setup(){
	robo.configurar(false);
}

void loop(){
	valor_sensor_dir = robo.lerSensorLinhaEsq();
	valor_sensor_esq = robo.lerSensorLinhaDir();

	if(valor_sensor_dir > CINZA && valor_sensor_esq > CINZA){
		robo.acionarMotores(50,50);
	}
	else if (valor_sensor_dir < CINZA && valor_sensor_esq > CINZA){
		robo.acionarMotores(0,50);
	}
	else if (valor_sensor_dir > CINZA && valor_sensor_esq < CINZA){
		robo.acionarMotores(0,50);
	}
	else{
		robo.acionarMotores(0,0);
	}

}

