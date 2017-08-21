
//nesse arquivo as funcoes devem ser somente declaradas
#ifndef ROBO_HARDWARE_H
#define ROBO_HARDWARE_H


#include <Arduino.h>
#include <Servo.h>

#include "cor.h"
#include "pinagem.h"
#include "Ultrasonic.h"

#include "encoder.h"
#include "contr_motor.h"
#include "EEPROM2.h"

struct calibracao_dados{
	HSV branco;
	HSV preto;
	HSV verde;
	HSV cinza;

	int refletancia_dir;
	int refletancia_mais_dir;
	int refletancia_esq;
	int refletancia_mais_esq;
	

};

class robo_hardware:private pinagem{
private:

  #define AJUSTE_MOTOR 0.65
	#define MAX_10_BITS 1023.0				//Maior valor que um numero de 10 bits pode obter
	
	#define CALIBRACAO_SONAR  40.4	//Valor para calibrar os sonares. Quanto maior esse valor menor a inclinação da reta de calibracao

	#define ENDERECO_EEPROM 0
public: 


  robo_hardware();
  void configurar(bool habilitar_garra=true);
  boolean lerSensorFimDeCurso();

	//As funcoes retornam o valor lido do sensor refletancia
  int lerSensorDeLinha(int sensor); //recebe um pino analogico (A0, A1, A2 e etc) e retorna um valor de 0 a 1023 
	inline float lerSensorLinhaEsq(){return (100 - 100.0 * (lerSensorDeLinha(SENSOR_LINHA_ESQUERDO))/1023.0);} //retorna um valor de 0 a 100 
	inline float lerSensorLinhaDir(){return (100 - 100.0 * (lerSensorDeLinha(SENSOR_LINHA_DIREITO) )/1023.0);} //retorna um valor de 0 a 100

	//A funcao para acionar os motores de locomocao do robo
	//A funcao recebe um percentual de tensao do motor esquerdo e direito
	//A funcao so recebe valores que variem de 100 ate -100
  void acionarMotores(float percetualMotorEsquerdo, float percetualMotorDireito);
  void acionarMotoresVel(float velMotorEsquerdo, float velMotorDireito);
	void acionarMotoresPos(float angMotorEsquerdo, float angMotorDireito);

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

	void salvarCalibracao(calibracao_dados cal);  
	void lerCalibracao(calibracao_dados &cal);

private:


  static Servo servoGarra1;
  static Servo servoGarra2;
  void tensao(float valor_por_cento,int pino);
  //SensorCor cor_direita(s2,s3, out);  
  SensorCor corDireita;
  SensorCor corEsquerda;

	Ultrasonic sonarFrontal;
	Ultrasonic sonarLateral;  

	Encoder encoderDir, encoderEsq;

	contr_motor motorEsq, motorDir;
};

static robo_hardware robo;

#endif
