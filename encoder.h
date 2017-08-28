#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>
#include "VariavelCompartilhada.h"

class Encoder{
  #define VEL_MAX_ENCODER_POR_MILI_SEGUNDOS 1.9
  #define NUM_MAX_PULSOS_POR_ROTACAO 482.0
  #define _360_GRAUS 360
  
  const byte pino_interrupcao;
  const byte pino2;
  byte Encoder_C1Last;
   //Variaveis modificadas na interrupcao 
   //Volatile indica ao compilador que o mesmo nao pode fazer otimizacoes nessa variavel que atrapalhariam a interrupcao 
  VarCompartilhada <volatile long> numPulsos;  //variavel compartilhada entre thread da interrupcao externa e as outras threads
  VarCompartilhada <volatile boolean> direcao;

  //velocidade em pusos/segundo
  VarCompartilhada <double> velocidade;	//variável compartilhada com a thread de controle e a thread principal
  unsigned long tempo_ant;
  long numPulsos_ant;
  const int amostragem_vel; //tempo de amostragem em milesegundos 
  
  float angulo_absoluto_anterior;
  float angulo_relativo;
  
  
  public:
  void configurar();
  Encoder(byte pino_interrupcao, byte pino2);
	Encoder(const Encoder &e);
  void calculaPulso();
  
  void resetNumPulsos();
	//esta função retornar uma variavel compartilhada com a thread da interrupcao externa
  inline const long  getNumPulsos()const{ return numPulsos.get(); }
  //	inline const boolean getDirecao()const{ return direcao.get(); }
  //inline void setAmostragemVel(int amostragem){amostragem_vel = amostragem;}
  inline int getPinoInterrupcao()const{return pino_interrupcao;}
  
  inline float getAnguloAbsoluto()const {return (getNumPulsos()/NUM_MAX_PULSOS_POR_ROTACAO) * _360_GRAUS; }
  
  inline double getVelocidade()const{return velocidade.get();}
  
  void calculaVelocidade();

};

#endif
