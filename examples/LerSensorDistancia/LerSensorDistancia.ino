#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA SENSORES DE DISTANCIA***********//
//  SONAR_TRIGGER_FRONTAL	uno-A4; mega-16
//  SONAR_ECHO_FRONTAL		uno-A5; mega-17

//  SONAR_TRIGGER_ESQ	uno-0; mega-22
//  SONAR_ECHO_ESQ		uno-1; mega-24

//  SONAR_TRIGGER_DIR	uno-0; mega-23
//  SONAR_ECHO_DIR		uno-1; mega-25
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
