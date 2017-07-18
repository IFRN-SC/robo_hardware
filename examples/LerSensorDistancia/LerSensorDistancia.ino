#include <robo_hardware.h> 
#include <Servo.h>

//********PINOS PARA SENSORES DE DISTANCIA***********//
//  SONAR_TRIGGER_FRONTAL	4
//  SONAR_ECHO_FRONTAL		3

//  SONAR_TRIGGER_LATERAL	13
//  SONAR_ECHO_LATERAL		12
//*********PINOS PARA SENSORES DE DISTANCIA*********//

float valor_sensor_frontal;
float valor_sensor_lateral;

void setup(){
	Serial.begin(9600);
	robo.configurar(false);
}

void loop(){
	valor_sensor_lateral = robo.lerSensorSonarLateral(); //FUNCAO PARA LER VALOR DO SENSOR LATERAL
	valor_sensor_frontal = robo.lerSensorSonarFrontal(); //FUNCAO PARA LER VALOR DO SENSOR FRONTAL

        Serial.print("Valor do sensor frontal: ");
        Serial.println(valor_sensor_frontal);
        Serial.println();
        
        Serial.print("Valor do sensor lateral: ");
        Serial.println(valor_sensor_lateral);
        Serial.println();
        
        delay(500);
}
