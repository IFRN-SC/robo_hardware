#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR_LINHA_MAIS_ESQUERDO		uno-A0;	mega-A0
//SENSOR_LINHA_ESQUERDO			uno-A1;	mega-A1
//SENSOR_LINHA_DIREITO			uno-A2;	mega-A2
//SENSOR_LINHA_MAIS_DIREITO		uno-A3;	mega-A3
//
//*********PINOS PARA SENSORES REFLETANCIA*********//

float valorSensor;
float valorSensor_SemRuido;
float valorSensor_Ruido;

void setup(){
	Serial.begin(9600);
	robo.configurar(false);
}

void loop(){
	valorSensor = robo.lerSensorLinhaEsq(); //le um valor do sensor esquerdo. O sensor retorna um valor de 0 100
	//valorSensor = robo.lerSensorLinhaMaisEsq(); //le um valor do sensor mais esquerdo. O sensor retorna um valor de 0 100
	//valorSensor = robo.lerSensorLinhaDir(); //le um valor do sensor direito. O sensor retorna um valor de 0 100
	//valorSensor = robo.lerSensorLinhaMaisDir(); //le um valor do sensor mais direito. O sensor retorna um valor de 0 100
	
	valorSensor_SemRuido = robo.lerSensorLinhaEsqSemRuido();  //valor do sensor esquerdo sem ruido
	//valorSensor_SemRuido = robo.lerSensorLinhaMaisEsqSemRuido();  //valor do sensor mais esquerdo sem ruido
	//valorSensor_SemRuido = robo.lerSensorLinhaDirSemRuido();  //valor do sensor direito sem ruido
	//valorSensor_SemRuido = robo.lerSensorLinhaMaisDirSemRuido();  //valor do sensor mais direito sem ruido
	
	valorSensor_Ruido = robo.lerSensorDeLinha(A0,false);
	//valorSensor_Ruido = robo.lerSensorDeLinha(A1,false);
	//valorSensor_Ruido = robo.lerSensorDeLinha(A2,false);	
	//valorSensor_Ruido = robo.lerSensorDeLinha(A3,false);
	
	
	Serial.print("Valor sensor: ");
	Serial.println(valorSensor); //Imprime o valor do sensor pela porta serial
	Serial.print("Valor sensor sem ruido: ");
	Serial.println(valorSensor_SemRuido); //Imprime o valor do sensor pela porta serial
	Serial.print("ruido do sensor: ");
	Serial.println(valorSensor_Ruido); //Imprime o valor do sensor pela porta serial

	delay(1000);

}

