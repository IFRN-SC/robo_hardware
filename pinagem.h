#ifndef PINAGEM_H
#define PINAGEM_H

/*
Arduino UNO pinout

13-									SENSOR_COR_ESQ_OUT
12-									SENSOR_COR_ESQ_S3
11-	PWM (Timer 2)		SENSOR_COR_ESQ_S2
10-	PWM	(Timer 1)		SERVO_GARRA_1
09-	PWM	(Timer 1)		SERVO_GARRA_2
08-									SENSOR_COR_DIR_OUT
07-									SENTIDO_RODA_DIREITA
06-	PWM (TIMER 0)		PWM_RODA_DIREITA
05- PWM (TIMER 0)		PWM_RODA_ESQUERDA
04-									SENTIDO_RODA_ESQUERDA
03-	PWM	(Timer 2)		SENSOR_COR_DIR_S3
02-									SENSOR_COR_DIR_S2
01-	Tx
00-	Rx

A0- 								SENSOR_LINHA_ESQUERDO
A1-									SENSOR_LINHA_DIREITO
A2-									SONAR_TRIGGER_LATERAL
A3-									SONAR_ECHO_LATERAL
A4-	SDA							SONAR_TRIGGER_FRONTAL
A5-	SCL							SONAR_ECHO_FRONTAL


*/


class pinagem{

  //***PARA ARDUINO UNO E PRO MINI DEVE-SE UTILIZAR PARA MOTORES DC O PWM SOMENTE NAS PORTAS 5 E 6 ***/// 
  #define PWM_RODA_ESQUERDA 		5		//Define o pino que ligara o motor esquerdo para mudar a velocidade de rotacao 
  #define SENTIDO_RODA_ESQUERDA 4		//Define o pino que ligara o motor esquerdo para mudar o sentido de rotacao
  
	//***PARA ARDUINO UNO E PRO MINI DEVE-SE UTILIZAR PARA MOTORES DC O PWM SOMENTE NAS PORTAS 5 E 6 ***///
  #define PWM_RODA_DIREITA 			6		//Define o pino que ligara o motor direito para mudar a velocidade de rotacao 
  #define SENTIDO_RODA_DIREITA 	7		//Define o pino que ligara o motor direito para mudar o sentido de rotacao

	//A presente biblioteca pode controlar dois servomotores  
  #define SERVO_GARRA_1 				10	//Define o pino para "controlar" o servo motor 1
  #define SERVO_GARRA_2 				9		//Define o pino para "controlar" o servo motor 2


	//A presente biblioteca utiliza dois sensores de refletancia ou sensores de linha
	#define SENSOR_LINHA_ESQUERDO	A0	//Define o pino do sensor de refletancia esquerdo 
  #define SENSOR_LINHA_DIREITO	A1	//Define o pino do sensor de refletancia direito

	//A biblioteca possui dois sensores de cor: um esquerdo e outro direito.
	//cada sensor de cor precisa de 3 pinos para configuracao e leitura da cor
	//Os pinos dos sensores de cor são específicos para o arduino UNO e podem ser modificados para o arduino mega
	#define SENSOR_COR_ESQ_S2			11	
	#define SENSOR_COR_ESQ_S3			A2	//Pino analogico A2
	#define SENSOR_COR_ESQ_OUT		A3	//Pino analogico A3

	#define SENSOR_COR_DIR_S2			2
	#define SENSOR_COR_DIR_S3			3
	#define SENSOR_COR_DIR_OUT		8

	//A biblioteca possui dois sensores de distancia (Sonares)
	#define SONAR_TRIGGER_FRONTAL	2
	#define SONAR_ECHO_FRONTAL		3

	#define SONAR_TRIGGER_LATERAL	13
	#define SONAR_ECHO_LATERAL		12


	#if defined(__AVR_ATmega2560__)
		#define ENCODER1_INTERRUPCAO 	18
    #define ENCODER2_INTERRUPCAO 	19
		#define ENCODER1_DIRECAO			17
		#define ENCODER2_DIRECAO			16
	#endif
 

};

#endif
