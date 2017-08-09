#include <robo_hardware2.h> 
#include <Servo.h>

//*************PINOS PARA LIGAR MOTORES*************//
//   Motor direito:
//pino1 PWM_RODA_DIREITA	6
//pino2 SENTIDO_RODA_DIREITA	7
//   Motor esquerdo:
//pino1 PWM_RODA_ESQUERDA	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//*********PINOS PARA LIGAR MOTORES*********//

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR_LINHA_ESQUERDO			A0
//
//SENSOR_LINHA_DIREITO			A1
//
//*********PINOS PARA SENSORES REFLETANCIA*********//

#define DIVISOR_BRANCO_PRETO 50

float valor_sensor_dir;
float valor_sensor_esq;

void setup(){
	robo.configurar(false);
}

void loop(){

	valor_sensor_esq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valor_sensor_dir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir

	//Identifica se os dois sensores viram branco
	if(valor_sensor_dir > DIVISOR_BRANCO_PRETO && valor_sensor_esq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(50,50);	//Aciona os dois motores com a mesma velocidade
	}
	//Identifica se o sensor da esquerda viu banco e o da direita viu preto
	else if (valor_sensor_dir < DIVISOR_BRANCO_PRETO && valor_sensor_esq > DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(50,0);	//Aciona o motor esquerdo e mantem o motor direito desligado
	}
	//Identifica se o sensor da direita viu banco e o da esquerda viu preto
	else if ( valor_sensor_dir > DIVISOR_BRANCO_PRETO && valor_sensor_esq < DIVISOR_BRANCO_PRETO){
		robo.acionarMotores(0,50);	//Aciona o motor direito e mantem o motor esquerdo desligado
	}
	else{ //Identifica se os dois sensores viram preto
		robo.acionarMotores(0,0);
	}

}

