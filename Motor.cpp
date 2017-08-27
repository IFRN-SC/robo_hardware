#include "Motor.h"

Motor::Motor(byte pino_pwm, byte pino_direcao):
encoder(0,0),
PINO_PWM(pino_pwm), 
PINO_DIRECAO(pino_direcao)
{
	encoder_habilitado=false;
}

Motor::Motor(byte pino_pwm, byte pino_direcao, Encoder e):
encoder(e),
PINO_PWM(pino_pwm), 
PINO_DIRECAO(pino_direcao)
{
	encoder_habilitado=true;
}

void Motor::configurar(){
	if(encoder_habilitado){
		encoder.configurar();
		contrPos.configurar();
		contrVel.configurar();
	}
	pinMode(PINO_PWM, OUTPUT); 
  pinMode(PINO_DIRECAO, OUTPUT);
}

void Motor::tensao(float valor_por_cento,int pino){
  float k = 255/100.0;

  if(valor_por_cento < -100) 
    valor_por_cento = -100;	//se o valor passado em valor_por_cento for menor que -100 obriga-se o mmotor a ficar em -100
  if(valor_por_cento >  100) 
    valor_por_cento =  100;	//se o valor passado em valor_por_cento for maior que 100 obriga-se o mmotor a ficar em 100

  float valor_ate_255 = valor_por_cento * k;
  
  analogWrite(pino, abs(valor_ate_255)); 
}

void Motor::acionarMotor(float motor1){
 
  if(motor1 < 0){
    digitalWrite(PINO_DIRECAO, false);//Define aqui o sentido de rotacao
    tensao(motor1,PINO_PWM);  				//Chama a funcao que mudara a intensidade do sinal aplicado
  }else{
    digitalWrite(PINO_DIRECAO, true); //Define aqui o sentido de rotacao
    motor1 = 100 - motor1;			
    tensao(motor1,PINO_PWM);					//Chama a funcao que mudara a intensidade do sinal aplicado
  }    
}

void Motor::acionarMotorVel(float velMotor){
	float tensao=0;

	if(encoder_habilitado){
		encoder.calculaVelocidade();
		contrVel.executa(encoder.getVelocidade(), velMotor);
		tensao = contrVel.getOutput();
	}

	acionarMotor(tensao);
}

void Motor::acionarMotorPos(float anguloRef){
	float tensao=0;

	if(encoder_habilitado){
		contrPos.executa(encoder.getAnguloAbsoluto(), anguloRef);
		tensao = contrPos.getOutput();
	}
	//acionar motor
	acionarMotor(tensao);

}

void Motor::calculaPulso(){
	if(encoder_habilitado)
		encoder.calculaPulso();
}

const long Motor::getTempoAmostragemContr()const
{
	if(contrVel.getTempoAmostragem() < contrPos.getTempoAmostragem()){
		return contrVel.getTempoAmostragem();
	}
	return contrPos.getTempoAmostragem();
}

