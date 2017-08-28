#include "Motor.h"

Motor::Motor(byte pino_pwm, byte pino_direcao):
encoder(0,0),
PINO_PWM(pino_pwm), 
PINO_DIRECAO(pino_direcao),
ENCODER_HABILITADO(false)
{
	contrPosHabilitado=false;
	contrVelHabilitado=false;
	angulo=0;
	velocidade=0;
}

Motor::Motor(byte pino_pwm, byte pino_direcao, Encoder e):
encoder(e),
PINO_PWM(pino_pwm), 
PINO_DIRECAO(pino_direcao),
ENCODER_HABILITADO(true)
{
	contrPosHabilitado=false;
	contrVelHabilitado=false;
	angulo=0;
	velocidade=0;
}

void Motor::configurar(){
	if(ENCODER_HABILITADO == true){
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

void Motor::habilitaControlePosicao(){
		//Para habilitar o controle de posicao e necessario desabilitar o controle de velocidade
		contrVelHabilitado=false;
		contrPosHabilitado=true;	
}

void Motor::habilitaControleVelocidade(){
		//Para habilitar o controle de velocidade e necessario desabilitar o controle de posicao
		contrVelHabilitado=true;
		contrPosHabilitado=false;	
}

void Motor::desabilitaControle(){
		contrVelHabilitado=false;
		contrPosHabilitado=false;	
}

void Motor::acionarMotorVel(float velMotor){
	float tensao=0;

	if(ENCODER_HABILITADO == true){
		encoder.calculaVelocidade();
		contrVel.executa(encoder.getVelocidade(), velMotor);
		tensao = contrVel.getOutput();
	}

	acionarMotor(tensao);
}

void Motor::acionarMotorPos(float anguloRef){
	if(ENCODER_HABILITADO == true){
		angulo=anguloRef;	//Atualiza o angulo que sera usado no controlador
		habilitaControlePosicao(); //habilita o controle de posicao
	}
	else{//Quando o encoder nao esta configurado desabilita-se o controle e desliga-se o motor
		desabilitaControle();
		acionarMotor(0); //Desliga o motor
	}
}

void Motor::calculaPulso(){
	if(ENCODER_HABILITADO == true)
		encoder.calculaPulso();
}

const long Motor::getTempoAmostragemContr()const
{
	if(contrVel.getTempoAmostragem() < contrPos.getTempoAmostragem()){
		return contrVel.getTempoAmostragem();
	}
	return contrPos.getTempoAmostragem();
}

//Essa funcao sera chamada somente pela thread de controle
void Motor::loopControle(){
	float tensao=0;
	
	//Somente existe laco de controle se existe encoder
	if(ENCODER_HABILITADO == true){
		//Ao chamar a função acionarMotorVel habilita-se o encoder para funcionar
		//O laco so chamara o controle habilitado
		if(contrVelHabilitado == true){
		
		}
		//Ao chamar a função acionarMotorPos habilita-se o encoder para funcionar
		//O laco so chamara o controle habilitado
		else if (contrPosHabilitado == true) {
			//chama a execucao do controle de posicao
			contrPos.executa(encoder.getAnguloAbsoluto(), angulo.get());
			tensao = contrPos.getOutput();
			Serial.print("\t Angulo: ");
			Serial.print(encoder.getAnguloAbsoluto());
			Serial.print("\t Tensão: ");
			Serial.print(tensao);

			//acionar motor
			acionarMotor(tensao);		
		}
	}

}
