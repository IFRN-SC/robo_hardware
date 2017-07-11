
//nesse arquivo as funcoes devem ser somente declaradas
#ifndef ROBO_HARDWARE_H
#define ROBO_HARDWARE_H


#include <Arduino.h>
#include <Servo.h>

#include "cor.h"
#include "pinagem.h"
#include "Ultrasonic.h"

class robo_hardware:private pinagem{
private:

  #define AJUSTE_MOTOR 0.65
public: 


  robo_hardware();
  void configurar(bool habilitar_garra=true);
  boolean lerSensorFimDeCurso();

	//As funcoes retornam o valor lido do sensor refletancia
  int lerSensorDeLinha(int sensor); //recebe um pino analogico (A0, A1, A2 e etc) e retorna um valor de 0 a 1023 
	inline float lerSensorLinhaEsq(){return 100.0 * (lerSensorDeLinha(SENSOR_LINHA_ESQUERDO))	/1013.0;} //retorna um valor de 0 a 100 
	inline float lerSensorLinhaDir(){return 100.0 * (lerSensorDeLinha(SENSOR_LINHA_DIREITO))	/1023.0;} //retorna um valor de 0 a 100

	//A funcao para acionar os motores de locomocao do robo
	//A funcao recebe um percentual de tensao do motor esquerdo e direito
	//A funcao so recebe valores que variem de 100 ate -100
  void acionarMotores(float percetualMotorEsquerdo, float percetualMotorDireito);

	//funcao para acionar os servomotores
  void acionarServoGarra1(float angulo);
  void acionarServoGarra2(float angulo);

	float lerSensorSonarFrontal();
	float lerSensorSonarLateral();
  
  
	//funcoes para trabalhar com os sensores de Cor
  HSV getHSVEsquerdo(); //realiza a leitura do sensor de cor esquerdo e retorna uma estrutura HSV. Ver cor.h
  RGB getRGBEsquerdo(); //realiza a leitura do sensor de cor esquerdo e retorna uma estrutura RGB. Ver cor.h
  HSV getHSVDireito(); 	//realiza a leitura do sensor de cor direito e retorna uma estrutura HSV. Ver cor.h
  RGB getRGBDireito(); 	//realiza a leitura do sensor de cor direito e retorna uma estrutura RGB. Ver cor.h
  

private:
  static Servo servoGarra1;
  static Servo servoGarra2;
  void tensao(float valor_por_cento,int pino);
  //SensorCor cor_direita(s2,s3, out);  
  SensorCor corDireita;
  SensorCor corEsquerda;

	Ultrasonic sonarFrontal;
	Ultrasonic sonarLateral;  

};

static robo_hardware robo;

#endif
