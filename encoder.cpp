#include "encoder.h"

Encoder::Encoder(byte pino_c1, byte pino_c2):
pino_interrupcao(pino_c1), 
pino2(pino_c2), amostragem_vel(10)
{
  numPulsos=0;
	velocidade=0;
	tempo_ant=0;
	numPulsos_ant=0;
	angulo_absoluto_anterior=0;
	angulo_relativo=0;
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
    if (val == LOW && Direcao)    {
      Direcao = false; //Reverse
      
    }
    else if (val == HIGH && !Direcao)    {
           
      Direcao = true;  //Forward
    }
  }
  Encoder_C1Last = Lstate;
 
  if (!Direcao)  numPulsos--;
  else  numPulsos++;
}

void Encoder::calculaVelocidade(){
  
  unsigned long tempo_atual = millis();
  unsigned long timeChange = (tempo_atual - tempo_ant);
  if(timeChange>=amostragem_vel){
    velocidade = (numPulsos - numPulsos_ant)/((double)(timeChange));
    velocidade = 100*velocidade/VEL_MAX_ENCODER_POR_MILI_SEGUNDOS;
    //Serial.println(numPulsos);// - numPulsos_ant);
    numPulsos_ant = numPulsos;
    tempo_ant = tempo_atual;

  }
  
}

float Encoder::getAnguloRelativo(){
  CalculaAnguloRelativo();
  return  angulo_relativo; 
}

void Encoder::CalculaAnguloRelativo(){
  float angulo_absoluto_atual = getAnguloAbsoluto();
  
  angulo_relativo = angulo_absoluto_atual - angulo_absoluto_anterior;  
  angulo_absoluto_anterior = angulo_absoluto_atual;
  
}
