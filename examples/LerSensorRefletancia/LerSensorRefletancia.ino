#include <robo_hardware.h> 
#include <Servo.h>

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR_LINHA_ESQUERDO			A0
//SENSOR_LINHA_DIREITO			A1
//
//*********PINOS PARA SENSORES REFLETANCIA*********//

float valor_sensor_dir;
float valor_sensor_esq;

void setup(){
	Serial.begin(9600);
	robo.configurar(false);
}

void loop(){
	valor_sensor_esq = robo.lerSensorLinhaEsq(); //le um valor do sensor. O sensor retornar um valor de 0 100
	valor_sensor_dir = robo.lerSensorLinhaDir(); //le um valor do sensor. O sensor retornar um valor de 0 100

	Serial.print("Valor do sensor direito é: ");
	Serial.println(valor_sensor_dir); //Imprime o valor do sensor pela porta serial

	Serial.print("Valor do sensor esquerdo é: ");
	Serial.println(valor_sensor_esq); //Imprime o valor do sensor pela porta serial

	delay(1000);

}

