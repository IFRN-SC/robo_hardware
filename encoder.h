#ifndef ENCODER_H
#define ENCODER_H

#include <Arduino.h>

class Encoder{
  #define VEL_MAX_ENCODER_POR_MILI_SEGUNDOS 1.9
  #define NUM_MAX_PULSOS_POR_ROTACAO 482.0
  #define _360_GRAUS 360
  
  const byte pino_interrupcao;
  const byte pino2;
  byte Encoder_C1Last;
   //Variaveis modificadas na interrupcao 
   //Volatile indica ao compilador que o mesmo nao pode fazer otimizacoes nessa variavel que atrapalhariam a interrupcao 
  volatile long numPulsos;
  volatile boolean Direcao;
  
  double velocidade; //velocidade em pusos/segundo
  unsigned long tempo_ant;
  long numPulsos_ant;
  const int amostragem_vel; //tempo de amostragem em milesegundos 
  
  float angulo_absoluto_anterior;
  float angulo_relativo;
  
  
  public:
  void configurar();
  Encoder(byte pino_interrupcao, byte pino2);
  void calculaPulso();
  
  inline void resetNumPulsos(){numPulsos=0;}
  inline long getNumPulsos()const{return numPulsos;}
  inline boolean getDirecao()const{return Direcao;}
  //inline void setAmostragemVel(int amostragem){amostragem_vel = amostragem;}
  inline int getPinoInterrupcao()const{return pino_interrupcao;}
  
  inline float getAnguloAbsoluto()const {return (numPulsos/NUM_MAX_PULSOS_POR_ROTACAO) * _360_GRAUS; }
  float getAnguloRelativo();
  void CalculaAnguloRelativo();
  
  inline double getVelocidade()const{return velocidade;}
  
  void calculaVelocidade();

};

#endif
