#ifndef PINAGEM_H
#define PINAGEM_H

/*
Arduino UNO pinout

13-									SONAR_TRIGGER_LATERAL
12-									SONAR_ECHO_LATERAL
11-	PWM (Timer 2)
10-	PWM	(Timer 1)		SERVO_GARRA_1
09-	PWM	(Timer 1)		SERVO_GARRA_2
08-									
07-									SENTIDO_RODA_DIREITA
06-	PWM (TIMER 0)		PWM_RODA_DIREITA
05- PWM (TIMER 0)		PWM_RODA_ESQUERDA
04-									SENTIDO_RODA_ESQUERDA
03-	PWM	(Timer 2)		SONAR_ECHO_FRONTAL
02-									SONAR_TRIGGER_FRONTAL
01-	Tx
00-	Rx

A0- 								SENSOR_LINHA_ESQUERDO
A1-									SENSOR_LINHA_DIREITO
A2-									SENSOR_LINHA_DIREITO2
A3-									SENSOR_LINHA_ESQUERDO2
A4-	SDA
A5-	SCL


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
  #define SERVO_GARRA_2 				11		//Define o pino para "controlar" o servo motor 2

	//A presente biblioteca pode utilizar um botao para comunicao
  #define BOTAO 								45

	//A presente biblioteca utiliza dois sensores de refletancia ou sensores de linha
	#define SENSOR_LINHA_DIREITO2	A3	//Define o pino do sensor de refletancia esquerdo 
	#define SENSOR_LINHA_ESQUERDO2  A2
	#define SENSOR_LINHA_DIREITO	A1	//Define o pino do sensor de refletancia direito
	#define SENSOR_LINHA_ESQUERDO  	A0
	
	//A biblioteca possui dois sensores de cor: um esquerdo e outro direito.
	//cada sensor de cor precisa de 3 pinos para configuracao e leitura da cor
	//Os pinos dos sensores de cor são específicos para o arduino UNO e podem ser modificados para o arduino mega
	#define SENSOR_COR_ESQ_POWER			2	//Pino analogico A4
	#define SENSOR_COR_DIR_POWER		3	//Pino analogico A5

	

	//A biblioteca possui dois sensores de distancia (Sonares)
	#define SONAR_TRIGGER_FRONTAL	8
	#define SONAR_ECHO_FRONTAL		9

	#define SONAR_TRIGGER_LATERAL	12
	#define SONAR_ECHO_LATERAL		13
	
 

};

#endif
