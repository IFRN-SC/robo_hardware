#include "robo_hardware2.h"
#include <math.h>

Servo robo_hardware::servoGarra1;
Servo robo_hardware::servoGarra2;
int robo_hardware::tipoSensorCor;

robo_hardware::robo_hardware():	corDireita	(SENSOR_COR_DIR_S2,SENSOR_COR_DIR_S3,SENSOR_COR_DIR_OUT),
																corEsquerda	(SENSOR_COR_ESQ_S2,SENSOR_COR_ESQ_S3,SENSOR_COR_ESQ_OUT),
																corDireita34(SENSOR_COR_DIR_TCS34),
																corEsquerda34(SENSOR_COR_ESQ_TCS34),
																sonarFrontal(SONAR_TRIGGER_FRONTAL, SONAR_ECHO_FRONTAL),
																sonarEsq(SONAR_TRIGGER_ESQ, SONAR_ECHO_ESQ),
																sonarDir(SONAR_TRIGGER_DIR, SONAR_ECHO_DIR),
																botao1(BOTAO_1), botao2(BOTAO_2), botao3(BOTAO_3),
																led1(LED_1), led2(LED_2), led3(LED_3)
{
	tipoSensorCor = TCS23;
}

void robo_hardware::tensao(float valor_por_cento,int pino){
  float k = 255/100.0;

  if(valor_por_cento < -100) 
    valor_por_cento = -100;	//se o valor passado em valor_por_cento for menor que -100 obriga-se o mmotor a ficar em -100
  if(valor_por_cento >  100) 
    valor_por_cento =  100;	//se o valor passado em valor_por_cento for maior que 100 obriga-se o mmotor a ficar em 100

  float valor_ate_255 = valor_por_cento * k;
  
  analogWrite(pino, abs(valor_ate_255)); 
}

void robo_hardware::habilitaTCS23(){
	tipoSensorCor = TCS23;
}

void robo_hardware::habilitaTCS34(){
	tipoSensorCor = TCS34;
}

void robo_hardware::configurar(bool habilitar_garra){
//  Serial.begin(9600);

	//Com essas funcoes os sonares sao calibrados 
	//Quanto maior o valor de CALIBRACAO_SONAR menor a inclinacao da curva de calibracao 
	sonarFrontal.setDivisor(CALIBRACAO_SONAR, Ultrasonic::CM);  
	sonarEsq.setDivisor(CALIBRACAO_SONAR, Ultrasonic::CM);
	sonarDir.setDivisor(CALIBRACAO_SONAR, Ultrasonic::CM);
  
	if(habilitar_garra){
  	servoGarra1.attach(SERVO_GARRA_1);
  	servoGarra2.attach(SERVO_GARRA_2);
	}

  pinMode(PWM_RODA_ESQUERDA, OUTPUT); 
  pinMode(PWM_RODA_DIREITA, OUTPUT); 
  pinMode(SENTIDO_RODA_ESQUERDA, OUTPUT); 
  pinMode(SENTIDO_RODA_DIREITA, OUTPUT);

  pinMode(LED_SENSOR_LINHA_MAIS_ESQUERDO, OUTPUT);
  pinMode(LED_SENSOR_LINHA_ESQUERDO, OUTPUT);
  pinMode(LED_SENSOR_LINHA_DIREITO, OUTPUT);
  pinMode(LED_SENSOR_LINHA_MAIS_DIREITO, OUTPUT);
	
	botao1.config();
	botao2.config();
	botao3.config();

	led1.config();
	led2.config();
	led3.config();

	corDireita34.config();
	corEsquerda34.config();
}

const float robo_hardware::lerSensorDeLinha(const int sensor, bool ledLigado=true){
	int pino;
	switch(sensor){
		case SENSOR_LINHA_MAIS_ESQUERDO:
			pino = LED_SENSOR_LINHA_MAIS_ESQUERDO;
		break;
			
		case SENSOR_LINHA_ESQUERDO:
			pino = LED_SENSOR_LINHA_ESQUERDO;
		break;

		case SENSOR_LINHA_DIREITO:
			pino = LED_SENSOR_LINHA_DIREITO;
		break;

		case SENSOR_LINHA_MAIS_DIREITO:
			pino = LED_SENSOR_LINHA_MAIS_DIREITO;
		break;
	}

	digitalWrite(pino, ledLigado);

	delay(1);
	
	return ( 100 - 100.0 * ( analogRead(sensor) )/1023.0);
}

void robo_hardware::acionarMotores(float motor1, float motor2){
 
  if(motor1 < 0){
    digitalWrite(SENTIDO_RODA_ESQUERDA, false);
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }else{
    digitalWrite(SENTIDO_RODA_ESQUERDA, true);
    motor1 = 100 - motor1;
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }
  
  if(motor2 < 0){
    digitalWrite(SENTIDO_RODA_DIREITA, false);
    tensao(motor2,PWM_RODA_DIREITA);  
  }else{
    digitalWrite(SENTIDO_RODA_DIREITA, true);
    motor2 = 100 - motor2;
    tensao(motor2,PWM_RODA_DIREITA);  
  }
    
}

float robo_hardware::lerSensorSonarFrontal(){
	long microsec = sonarFrontal.timing();
	return sonarFrontal.convert(microsec, Ultrasonic::CM);  //retorna a distância do sensor ao obstáculo em cm.
}

float robo_hardware::lerSensorSonarEsq(){
	long microsec = sonarEsq.timing();
	return sonarEsq.convert(microsec, Ultrasonic::CM);  //retorna a distância do sensor ao obstáculo em cm.
}

float robo_hardware::lerSensorSonarDir(){
	long microsec = sonarDir.timing();
	return sonarDir.convert(microsec, Ultrasonic::CM);  //retorna a distância do sensor ao obstáculo em cm.
}

void robo_hardware::acionarServoGarra1(int angInicial, int angFinal, int tempo){
  	if (angFinal > angInicial) {
		for(int angulo = angInicial; angulo < angFinal; angulo++){	
			acionarServoGarra1(angulo);
			delay(tempo);
		}
	}
	else {
		for(int angulo = angInicial; angulo > angFinal; angulo--){
			acionarServoGarra1(angulo);
			delay(tempo);
		}
	}

}


void robo_hardware::acionarServoGarra2(int angInicial, int angFinal, int tempo){
  	if(angFinal > angInicial){
		for(int angulo = angInicial; angulo < angFinal; angulo++){
			acionarServoGarra2(angulo);
			delay(tempo);
		}
	}
	else {
		for(int angulo = angInicial; angulo > angFinal; angulo--){
			acionarServoGarra2(angulo);
			delay(tempo);
		}
	}

}

void robo_hardware::acionarServoGarra1(int angulo){
	servoGarra1.write(angulo);
}

void robo_hardware::acionarServoGarra2(int angulo){
	servoGarra2.write(angulo);
}
HSV robo_hardware::getHSVEsquerdo(){
  switch(tipoSensorCor){
    case TCS34:
      return corEsquerda34.getHSV();
    default:
      return corEsquerda.getHSV();
	}
}

HSV robo_hardware::getHSVDireito(){
  switch(tipoSensorCor){
    case TCS34:
      return corDireita34.getHSV();
    default:
      return corDireita.getHSV();
  }
}

RGB robo_hardware::getRGBEsquerdo(){
  switch(tipoSensorCor){
    case TCS34:
      return corEsquerda34.getRGB();
    default:
      return corEsquerda.getRGB();
  }
}

RGB robo_hardware::getRGBDireito(){
  switch(tipoSensorCor){
    case TCS34:
      return corDireita34.getRGB();
    default:
      return corDireita.getRGB();
  }
}

void  robo_hardware::salvarCalibracao(calibracao_dados calibraca_val){
	EEPROM.put(ENDERECO_EEPROM, calibraca_val);
}

void robo_hardware::lerCalibracao(calibracao_dados &cal){
	EEPROM.get(ENDERECO_EEPROM, cal);
}

void robo_hardware::ligarLed(const int led)const{
	switch(led){
		case 1:
			led1.ligar();
		break;
		case 2:
			led2.ligar();
		break;
		case 3:
			led3.ligar();
		break;
		default:
		break;	
	}
}

void robo_hardware::desligarLed(const int led)const{
	switch(led){
		case 1:
			led1.desligar();
		break;
		case 2:
			led2.desligar();
		break;
		case 3:
			led3.desligar();
		break;
		default:
		break;	
	}
}

void robo_hardware::ligarTodosLeds()const{
	led1.ligar();
	led2.ligar();
	led3.ligar();
}

void robo_hardware::desligarTodosLeds()const{
	led1.desligar();
	led2.desligar();
	led3.desligar();
}

const float robo_hardware::lerDadosSensorDeLinha(const int sensor){
	float valorLedDesligado = 0;
	float valorLedLigado    = 0;

	valorLedDesligado = lerSensorDeLinha(sensor, OFF);
	valorLedLigado    = lerSensorDeLinha(sensor);
	

	return valorLedLigado -  valorLedDesligado;
}

