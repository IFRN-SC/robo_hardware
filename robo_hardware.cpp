#include "robo_hardware.h"
#include <math.h>

Servo robo_hardware::servoGarra1;
Servo robo_hardware::servoGarra2;


robo_hardware::robo_hardware():	corDireita	(SENSOR_COR_DIR_S2,SENSOR_COR_DIR_S3,SENSOR_COR_DIR_OUT),
																corEsquerda	(SENSOR_COR_ESQ_S2,SENSOR_COR_ESQ_S3,SENSOR_COR_ESQ_OUT)
{

}

void robo_hardware::tensao(float valor_por_cento,int pino){
  float k = 255/100;
  float valor_ate_255 = valor_por_cento * k;
  analogWrite(pino, abs(valor_ate_255)); 
}

void robo_hardware::configurar(bool habilitar_garra){
  Serial.begin(9600);
  
	if(habilitar_garra){
  	servoGarra1.attach(SERVO_GARRA_1);
  	servoGarra2.attach(SERVO_GARRA_2);
	}
/* 
  pinMode(2, OUTPUT);  
  digitalWrite(2, HIGH);
  
  pinMode(3, OUTPUT);  
  digitalWrite(3, HIGH);
*/
  pinMode(PWM_RODA_ESQUERDA, OUTPUT); 
  pinMode(PWM_RODA_DIREITA, OUTPUT); 
  pinMode(SENTIDO_RODA_ESQUERDA, OUTPUT); 
  pinMode(SENTIDO_RODA_DIREITA, OUTPUT);

  pinMode(BOTAO, INPUT_PULLUP);
}

boolean robo_hardware::lerSensorFimDeCurso(){
  return digitalRead(BOTAO); 
}

int robo_hardware::lerSensorDeLinha(int sensor){
  return analogRead(sensor);
}

void robo_hardware::acionarMotores(float motor1, float motor2){
 
  if(motor1 < 0){
		if(motor1 < -100) motor1 = -100;	//se o valor passado em motor1 for menor que -100 obriga-se o mmotor a ficar em -100
    digitalWrite(SENTIDO_RODA_ESQUERDA, false);
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }else{
		if(motor1 > 100) motor1 = 100; 		//se o valor passado em motor1 for maior que 100 obriga-se o mmotor a ficar em 100
    digitalWrite(SENTIDO_RODA_ESQUERDA, true);
    motor1 = 100 - motor1;
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }
  
  if(motor2 < 0){
		if(motor1 < -100) motor1 = -100;	//se o valor passado em motor1 for menor que -100 obriga-se o mmotor a ficar em -100
    digitalWrite(SENTIDO_RODA_DIREITA, false);
    tensao(motor2,PWM_RODA_DIREITA);  
  }else{
		if(motor1 > 100) motor1 = 100; 		//se o valor passado em motor1 for maior que 100 obriga-se o mmotor a ficar em 100
    digitalWrite(SENTIDO_RODA_DIREITA, true);
    motor2 = 100 - motor2;
    tensao(motor2,PWM_RODA_DIREITA);  
  }
    
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
