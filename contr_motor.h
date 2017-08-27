#ifndef CONTR_MOTOR_H
#define CONTR_MOTOR_H
#include <Arduino.h>
#include "PID.h"
//#include "encoder.h"

class contr_motor{

  double Setpoint, Input, Output; // these are just variables for storing values
  
  //variaveis devem ser configuradas chamando a funcao setPinos()
  int outputPin; // LED output
  int signalPin; // Pin to inform the way of moviment
  int direcaoSetpointPin;
  int pwmSetpointPin;
  
  
  
  // Tuning parameters
  float Kp; //Proportional Gain 
  float Ki; //Integral Gain 
  float Kd; //Differential Gain 
  
  // Specify the links and initial tuning parameters
  PID myPID;
  //Encoder encoder;
  
  const int sampleRate = 1; // Variable that determines how fast our PID loop runs
  
  public:
  contr_motor();
  void configurar();
  void executa();
	void executa(double in, double sp);
  
//  inline double ler_entrada(){
//    encoder.calculaVelocidade(); 
//    return encoder.getVelocidade();
//  }
  inline double ler_setPoint(){return Setpoint;}
  inline double ler_analogico(const int pino){return 100*(analogRead(pino)/1023.0);}
  void escr_analogico(int pino, double valor);
  
  inline void setModePID(int mode){myPID.SetMode(mode);}
  inline void setControllerDirectionPID(int direcao){myPID.SetControllerDirection(direcao);}
  inline void setTuningsPID(float p, float i, float d){myPID.SetTunings(p, i, d);}
  inline float getKpPID(){return myPID.GetKp();}
  inline float getKiPID(){return myPID.GetKi();}
  inline float getKdPID(){return myPID.GetKd();}
  inline int getModePID(){myPID.GetMode();}
  inline int getDirectionPID(){myPID.GetDirection();}
  
  inline void setSetPoint(double sp){Setpoint = sp;}
  inline void setOutput(double op){Output = op;}
	inline void setInput(double in){Input = in;}  
  inline double getSetPoint(){return Setpoint;}
  inline double getOutput(){return Output;}
  inline double getInput(){return Input;}
  
//  inline void calculapulso(){encoder.calculaPulso();}
  void setPinos(int pwm_setpoint, int direcao_setpoint, int pwm_output, int direcao_output);
};

#endif
