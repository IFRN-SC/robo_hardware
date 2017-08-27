#include "robo_hardware2.h"
#include <math.h>

Servo robo_hardware::servoGarra1;
Servo robo_hardware::servoGarra2;

//#if defined(__AVR_ATmega2560__)
	#define CONTROLE_MOTOR_HABILITADO true
	Motor robo_hardware::motorEsq(PWM_RODA_ESQUERDA, SENTIDO_RODA_ESQUERDA, Encoder(ENCODER_ESQ_INTERRUPCAO, ENCODER_ESQ_DIRECAO) );
	Motor robo_hardware::motorDir(PWM_RODA_DIREITA , SENTIDO_RODA_DIREITA , Encoder(ENCODER_DIR_INTERRUPCAO, ENCODER_DIR_DIRECAO) );
//#else
//	#define CONTROLE_MOTOR_HABILITADO false
//	Motor robo_hardware::motorEsq(PWM_RODA_ESQUERDA, SENTIDO_RODA_ESQUERDA );
//	Motor robo_hardware::motorDir(PWM_RODA_DIREITA , SENTIDO_RODA_DIREITA  );
//#endif

robo_hardware::robo_hardware():	corDireita	(SENSOR_COR_DIR_S2,SENSOR_COR_DIR_S3,SENSOR_COR_DIR_OUT),
																corEsquerda	(SENSOR_COR_ESQ_S2,SENSOR_COR_ESQ_S3,SENSOR_COR_ESQ_OUT),
																sonarFrontal(SONAR_TRIGGER_FRONTAL, SONAR_ECHO_FRONTAL),
																sonarLateral(SONAR_TRIGGER_LATERAL, SONAR_ECHO_LATERAL)
{

}

void robo_hardware::configurar(bool habilitar_garra){
  Serial.begin(9600);

	//Com essas funcoes os sonares sao calibrados 
	//Quanto maior o valor de CALIBRACAO_SONAR menor a inclinacao da curva de calibracao 
	sonarFrontal.setDivisor(CALIBRACAO_SONAR, Ultrasonic::CM);  
	sonarLateral.setDivisor(CALIBRACAO_SONAR, Ultrasonic::CM);

	//Chamda de configuracao dos motores
	motorEsq.configurar();
	motorDir.configurar();

	attachInterrupt(0,calculaPulsoEsq, CHANGE);
	attachInterrupt(0,calculaPulsoDir, CHANGE);
  
	if(habilitar_garra){
  	servoGarra1.attach(SERVO_GARRA_1);
  	servoGarra2.attach(SERVO_GARRA_2);
	}

  pinMode(BOTAO, INPUT_PULLUP);

	MsTimer2::set(50, loopControle);
}

boolean robo_hardware::lerSensorFimDeCurso(){
  return digitalRead(BOTAO); 
}

int robo_hardware::lerSensorDeLinha(int sensor){
  return analogRead(sensor);
}

void robo_hardware::acionarMotores(float percentualMotorEsq, float percentualMotorDir){
	motorEsq.acionarMotor(percentualMotorEsq);
	motorDir.acionarMotor(percentualMotorDir);
}

void robo_hardware::acionarMotoresVel(float velMotorEsquerdo, float velMotorDireito){
	motorEsq.acionarMotorVel(velMotorEsquerdo);
	motorDir.acionarMotorVel(velMotorDireito);
}

void robo_hardware::acionarMotoresPos(float angEsquerdoRef, float angDireitoRef){
	motorEsq.acionarMotorPos(angEsquerdoRef);
	motorDir.acionarMotorPos(angDireitoRef);

}

float robo_hardware::lerSensorSonarFrontal(){
	long microsec = sonarFrontal.timing();
	return sonarFrontal.convert(microsec, Ultrasonic::CM);  //retorna a distância do sensor ao obstáculo em cm.
}

float robo_hardware::lerSensorSonarLateral(){
	long microsec = sonarLateral.timing();
	return sonarLateral.convert(microsec, Ultrasonic::CM);  //retorna a distância do sensor ao obstáculo em cm.
}

void robo_hardware::acionarServoGarra1(float angulo){
  servoGarra1.write(angulo);
}

void robo_hardware::acionarServoGarra2(float angulo){
  servoGarra2.write(angulo);
}

HSV robo_hardware::getHSVEsquerdo(){
  return corEsquerda.getHSV();
}

HSV robo_hardware::getHSVDireito(){
  return corDireita.getHSV();
}

RGB robo_hardware::getRGBEsquerdo(){
  return corEsquerda.getRGB();
}

RGB robo_hardware::getRGBDireito(){
  return corDireita.getRGB();
}

void  robo_hardware::salvarCalibracao(calibracao_dados calibraca_val){
	EEPROM.put(ENDERECO_EEPROM, calibraca_val);
}

void robo_hardware::lerCalibracao(calibracao_dados &cal){
	EEPROM.get(ENDERECO_EEPROM, cal);
}

void robo_hardware::loopControle(){
	Serial.println("teste");
}
