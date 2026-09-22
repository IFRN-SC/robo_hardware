#include <robo_hardware2.h> 
#include <Servo.h>

//-----PINOS PARA SENSORES DE DISTANCIA-----//
//  SONAR_TRIGGER_FRONTAL	12
//  SONAR_ECHO_FRONTAL		13
//-----PINOS PARA SENSORES DE DISTANCIA-----//

float valorSensorFrontal;

void setup(){
	Serial.begin(9600);
	robo.configurar();
}

void loop(){
        valorSensorFrontal = robo.lerSensorSonarFrontal(); //FUNCAO PARA LER VALOR DO SENSOR FRONTAL

        Serial.print("Valor do sensor frontal: ");
        Serial.print(valorSensorFrontal);
        Serial.println();

        delay(500);
        }
