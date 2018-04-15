#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA SENSORES DE DISTANCIA***********//
//  SONAR_TRIGGER_FRONTAL	A4
//  SONAR_ECHO_FRONTAL		A5

//  SONAR_TRIGGER_LATERAL	A2
//  SONAR_ECHO_LATERAL		A3
//*********PINOS PARA SENSORES DE DISTANCIA*********//

float valorSensorFrontal;
float valorSensorLateral;

void setup(){
	Serial.begin(9600);
	robo.configurar(false);
}

void loop(){
	valorSensorLateral = robo.lerSensorSonarEsq(); //FUNCAO PARA LER VALOR DO SENSOR LATERAL
	valorSensorFrontal = robo.lerSensorSonarFrontal(); //FUNCAO PARA LER VALOR DO SENSOR FRONTAL

        Serial.print("Valor do sensor frontal: ");
        Serial.print(valorSensorFrontal);
        
        Serial.print("  lateral: ");
        Serial.println(valorSensorLateral);
        Serial.println();
        
        delay(500);
}
