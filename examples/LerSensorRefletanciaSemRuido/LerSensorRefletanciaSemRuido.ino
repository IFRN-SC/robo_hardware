#include <robo_hardware2.h> 
#include <Servo.h>

//-----PINOS PARA SENSORES REFLETANCIA-----//
//SENSOR_LINHA_MAIS_ESQUERDO	    A3
//SENSOR_LINHA_ESQUERDO			    A2
//SENSOR_LINHA_DIREITO			    A1	
//SENSOR_LINHA_MAIS_DIREITO			A0	
//
//LED_SENSOR_LINHA_MAIS_DIREITO     11
//LED_SENSOR_DIREITO                10
//LED_SENSOR_ESQUERDO                9
//LED_SENSOR_LINHA_MAIS_ESQUERDO     8
//-----PINOS PARA SENSORES REFLETANCIA-----//

float valorSensorMaisEsq;
float valorSensorEsq;
float valorSensorDir;
float valorSensorMaisDir;
float valorSensorCentral;
float valorSensorFrontal;

void setup(){
	Serial.begin(9600);
	robo.configurar();
}

void loop(){
	valorSensorFrontal = robo.lerSensorLinhaFrontalSemRuido(); //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorCentral = robo.lerSensorLinhaCentralSemRuido(); //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorMaisEsq = robo.lerSensorLinhaMaisEsqSemRuido(); //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorEsq = robo.lerSensorLinhaEsqSemRuido();         //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorDir = robo.lerSensorLinhaDirSemRuido();         //le um valor do sensor. O sensor retornar um valor de 0 100
	valorSensorMaisDir = robo.lerSensorLinhaMaisDirSemRuido(); //le um valor do sensor. O sensor retornar um valor de 0 100

	//Impressão dos valores dos sensores
	Serial.print("Sensores refletancia sem ruido: +esq: ");
	Serial.print(valorSensorMaisEsq);   //Imprime o valor do sensor pela porta serial
	Serial.print("; esq: ");
	Serial.print(valorSensorEsq);       //Imprime o valor do sensor pela porta serial
	Serial.print("; dir: ");
	Serial.print(valorSensorDir);       //Imprime o valor do sensor pela porta serial
	Serial.print("; +dir: ");
	Serial.print(valorSensorMaisDir); //Imprime o valor do sensor pela porta serial
	Serial.print("; central: ");
	Serial.print(valorSensorCentral); //Imprime o valor do sensor pela porta serial
	Serial.print("; Frontal: ");
	Serial.println(valorSensorFrontal); //Imprime o valor do sensor pela porta serial

	delay(1000);

}


