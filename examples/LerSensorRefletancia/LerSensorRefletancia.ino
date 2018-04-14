#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR_LINHA_MAIS_ESQUERDO		A0
//SENSOR_LINHA_ESQUERDO			A1
//SENSOR_LINHA_DIREITO			A2
//SENSOR_LINHA_MAIS_DIREITO			A3
//
//*********PINOS PARA SENSORES REFLETANCIA*********//

float valorSensorMaisEsq;
float valorSensorEsq;
float valorSensorDir;
float valorSensorMaisDir;

void setup(){
	Serial.begin(9600);
	robo.configurar(false);
}

void loop(){
	valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq(); //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorEsq = robo.lerSensorLinhaEsq(); //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorDir = robo.lerSensorLinhaDir(); //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorMaisDir = robo.lerSensorLinhaMaisDir(); //le um valor do sensor. O sensor retornar um valor de 0 100

	//Impressão dos valores dos sensores
	Serial.print("Sensores refletancia: +esq; esq; dir; +dir ");
	Serial.print(valorSensorMaisEsq); //Imprime o valor do sensor pela porta serial
	Serial.print("; ");
	Serial.print(valorSensorEsq); //Imprime o valor do sensor pela porta serial
	Serial.print("; ");
	Serial.print(valorSensorDir); //Imprime o valor do sensor pela porta serial
	Serial.print("; ");
	Serial.println(valorSensorMaisDir); //Imprime o valor do sensor pela porta serial

	delay(1000);

}

