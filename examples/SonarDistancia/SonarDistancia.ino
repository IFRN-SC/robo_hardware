#include <robo_hardware.h> 
#include <Servo.h>

//*********PINOS PARA SONARES*********//
//    SONAR_FRONTAL:
//pino1 SONAR_TRIGGER_FRONTAL 4
//pino2 SONAR_ECHO_FRONTAL		3
//    SONAR_LATERAL:
//pino1 SONAR_TRIGGER_LATERAL	13
//pino2 SONAR_ECHO_LATERAL		12
//*********PINOS PARA SONARES*********//

float valorSonarFrontal=0;
float valorSonarLateral=0;

void setup(){
	//Configura o robo.
	robo.configurar(false);
}

void loop(){
	//Le o sonar frontal
	valorSonarFrontal = robo.lerSensorSonarFrontal();

	//Le o sonar lateral
	valorSonarLateral = robo.lerSensorSonarLateral();

	Serial.print("Sensor Frontal: ");
	Serial.println(valorSonarFrontal);

	Serial.print("Sensro Lateral: ");
	Serial.println(valorSonarLateral);
	delay(1000);

}

