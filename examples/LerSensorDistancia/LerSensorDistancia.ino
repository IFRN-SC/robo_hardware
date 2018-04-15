#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA SENSORES DE DISTANCIA***********//
//  SONAR_TRIGGER_FRONTAL	A4
//  SONAR_ECHO_FRONTAL		A5

//  SONAR_TRIGGER_LATERAL	A2
//  SONAR_ECHO_LATERAL		A3
//*********PINOS PARA SENSORES DE DISTANCIA*********//

float valor_sensor_frontal;
float valor_sensor_lateral;

void setup(){
	Serial.begin(9600);
	robo.configurar(false);
}

void loop(){
	valor_sensor_lateral = robo.lerSensorSonarEsq(); //FUNCAO PARA LER VALOR DO SENSOR LATERAL
	valor_sensor_frontal = robo.lerSensorSonarFrontal(); //FUNCAO PARA LER VALOR DO SENSOR FRONTAL

        Serial.print("Valor do sensor frontal: ");
        Serial.print(valor_sensor_frontal);
        
        Serial.print("  lateral: ");
        Serial.println(valor_sensor_lateral);
        Serial.println();
        
        delay(500);
}
