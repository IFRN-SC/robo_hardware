#include "contr_motor.h"

#include <math.h>


#define GO_AHEAD 0
#define GO_BACK  1

// O tempo entre a execucao de dois lacos de controle
#define TEMPO_AMOSTRAGEM_CONTR 50 //o tempo em milisegundos

contr_motor::contr_motor():
Kp(5.0), Ki(50.0), Kd(0), sampleRate(TEMPO_AMOSTRAGEM_CONTR),
myPID(&Input, &Output, &Setpoint,Kp,Ki,Kd, DIRECT)
//,encoder(e)
{
  Setpoint=0;
}

void contr_motor::configurar(){
//  encoder.config();    
  
  
  myPID.SetOutputLimits(-100, 100);
  myPID.SetMode(AUTOMATIC); // Turn on the PID loop as automatic control
  myPID.SetSampleTime(sampleRate); // Sets the sample rate  
}

void contr_motor::executa(){
  //Input = ler_entrada();
  //Setpoint = ler_setPoint();
  myPID.Compute(); // Run the PID loop
  //escr_analogico(outputPin, Output);  
}

void contr_motor::executa(double in, double sp){
	setSetPoint(sp);
	setInput(in);
	executa();
}

void contr_motor::escr_analogico(int pino, double valor){
  
  double Output_temp = 255*(valor/100.0);

  analogWrite(outputPin, fabs(Output_temp));  // Write out the output from the PID loop to our get out pin
  if (Output_temp >= 0){
    digitalWrite(signalPin, GO_AHEAD);
  }
  else{
    digitalWrite(signalPin, GO_BACK);       
  }
}

void contr_motor::setPinos(int pwm_setpoint, int direcao_setpoint, int pwm_output, int direcao_output){
  outputPin = pwm_output;
  signalPin = direcao_output;
  direcaoSetpointPin = direcao_setpoint;
  pwmSetpointPin = pwm_setpoint;
}
