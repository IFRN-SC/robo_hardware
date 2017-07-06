#include <robo_hardware.h> 
#include <Servo.h>

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR_LINHA_ESQUERDO			A0
//SENSOR_LINHA_DIREITO			A1
//
//*********PINOS PARA SENSORES REFLETANCIA*********//

#define CINZA 50

float valor_sensor_dir;
float valor_sensor_esq;

void setup(){
	Serial.begin(9600);
	robo.configurar(false);
}

void loop(){
	valor_sensor_dir = robo.lerSensorLinhaEsq();
	valor_sensor_esq = robo.lerSensorLinhaDir();

	Serial.print("Valor do sensor é: ");
	Serial.println(valor_sensor_dir);
	if(valor_sensor_dir > CINZA ){
		Serial.println("Sensor direito é Preto");
	}
	else{
		Serial.println("Sensor direito é Branco");
	}

	Serial.print("Valor do sensor é: ");
	Serial.println(valor_sensor_esq);
	if(valor_sensor_esq > CINZA ){
		Serial.println("Sensor esquerdo é Preto");
	}
	else{
		Serial.println("Sensor esquerdo é Branco");
	}


}

