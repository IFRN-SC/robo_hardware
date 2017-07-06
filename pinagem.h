#ifndef PINAGEM_H
#define PINAGEM_H

class pinagem{

  //***PARA ARDUINO UNO E PRO MINI DEVE-SE UTILIZAR PARA MOTORES DC O PWM SOMENTE NAS PORTAS 5 E 6 ***/// 
  #define PWM_RODA_ESQUERDA 		5		//Define o pino que ligara o motor esquerdo para mudar a velocidade de rotacao 
  #define SENTIDO_RODA_ESQUERDA 7		//Define o pino que ligara o motor esquerdo para mudar o sentido de rotacao
  
	//***PARA ARDUINO UNO E PRO MINI DEVE-SE UTILIZAR PARA MOTORES DC O PWM SOMENTE NAS PORTAS 5 E 6 ***///
  #define PWM_RODA_DIREITA 			6		//Define o pino que ligara o motor direito para mudar a velocidade de rotacao 
  #define SENTIDO_RODA_DIREITA 	8		//Define o pino que ligara o motor direito para mudar o sentido de rotacao

	//A presente biblioteca pode controlar dois servomotores  
  #define SERVO_GARRA_1 				13	//Define o pino para "controlar" o servo motor 1
  #define SERVO_GARRA_2 				12	//Define o pino para "controlar" o servo motor 2

	//A presente biblioteca pode utilizar um botao para comunicao
  #define BOTAO 								45

	//A presente biblioteca utiliza dois sensores de refletancia ou sensores de linha
	#define SENSOR_LINHA_ESQUERDO	A0	//Define o pino do sensor de refletancia esquerdo 
  #define SENSOR_LINHA_DIREITO	A1	//Define o pino do sensor de refletancia direito

	//A biblioteca possui dois sensores de cor: um esquerdo e outro direito.
	//cada sensor de cor precisa de 3 pinos para configuracao e leitura da cor
	#define SENSOR_COR_ESQ_S2			15
	#define SENSOR_COR_ESQ_S3			16
	#define SENSOR_COR_ESQ_OUT		17

	#define SENSOR_COR_DIR_S2			19
	#define SENSOR_COR_DIR_S3			20
	#define SENSOR_COR_DIR_OUT		21
 

};

#endif
