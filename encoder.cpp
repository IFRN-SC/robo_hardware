#include "encoder.h"
#include <util/atomic.h>

Encoder::Encoder(byte pino_c1, byte pino_c2):
pino_interrupcao(pino_c1), 
pino2(pino_c2), amostragem_vel(10)
{
  numPulsos=0;
	direcao=false;
	velocidade=0;
	tempo_ant=0;
	numPulsos_ant=0;
	angulo_absoluto_anterior=0;
	angulo_relativo=0;
}

Encoder::Encoder(const Encoder &e):
pino_interrupcao(e.pino_interrupcao),
pino2(e.pino2), amostragem_vel(e.amostragem_vel)
{
  numPulsos=e.numPulsos;
	direcao=e.direcao;
	velocidade=e.velocidade;
	tempo_ant=e.tempo_ant;
	numPulsos_ant=e.numPulsos_ant;
	angulo_absoluto_anterior=e.angulo_absoluto_anterior;
	angulo_relativo=e.angulo_relativo;
}

void Encoder::configurar(){
	pinMode(pino2, INPUT);
	pinMode(pino_interrupcao, INPUT);
}

void Encoder::calculaPulso(){
  int Lstate = digitalRead(pino_interrupcao);
  if ((Encoder_C1Last == LOW) && Lstate == HIGH){
    
    int val = digitalRead(pino2);
//    Serial.println(val);
    if (val == LOW && direcao)    {
      direcao = false; //Reverse
      
    }
    else if (val == HIGH && !direcao)    {
           
      direcao = true;  //Forward
    }
  }
  Encoder_C1Last = Lstate;
 
  if (!direcao)  numPulsos--;
  else  numPulsos++;
}

void Encoder::calculaVelocidade(){
  
  unsigned long tempo_atual = millis();
  unsigned long timeChange = (tempo_atual - tempo_ant);
	long numPulsosLocal = getNumPulsos();

  if(timeChange>=amostragem_vel){
    velocidade = (numPulsosLocal - numPulsos_ant)/((double)(timeChange));
    velocidade = 100*velocidade/VEL_MAX_ENCODER_POR_MILI_SEGUNDOS;
    numPulsos_ant = numPulsosLocal;
    tempo_ant = tempo_atual;

  }
  
}

//esta função modifica uma variavel alterada em uma interrupcao
void Encoder::resetNumPulsos(){
	//obriga que tudo que estiver dentro do block seja executado de forma atomica
	//ou seja, desabilita a interrupcao enquanto estiver dentro desse bloco
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){ //chamada de um macro
		numPulsos=0;
	}
}

//esta função le uma variavel alterada em uma interrupcao
const long Encoder::getNumPulsos()const{
	long pulsos;
	//obriga que tudo que estiver dentro do block seja executado de forma atomica
	//ou seja, desabilita a interrupcao enquanto estiver dentro desse bloco
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){ //chamada de um macro
		pulsos = numPulsos;
	}
	return pulsos;
}

const boolean Encoder::getDirecao()const{
	bool direcao_temp;
	//obriga que tudo que estiver dentro do block seja executado de forma atomica
	//ou seja, desabilita a interrupcao enquanto estiver dentro desse bloco
	ATOMIC_BLOCK(ATOMIC_RESTORESTATE){ //chamada de um macro
		direcao_temp = direcao;
	}
	return direcao_temp;
}
