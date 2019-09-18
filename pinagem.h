#ifndef PINAGEM_H
#define PINAGEM_H

/*
Arduino UNO pinout

13-						SENSOR_COR_ESQ_OUT
12-						SENSOR_COR_ESQ_S3
11-	PWM (Timer 2)		SENSOR_COR_ESQ_S2
10-	PWM	(Timer 1)		SERVO_GARRA_1
09-	PWM	(Timer 1)		SERVO_GARRA_2
08-					    SENSOR_COR_DIR_OUT
07-					    SENTIDO_RODA_DIREITA
06-	PWM (TIMER 0)		PWM_RODA_DIREITA
05- PWM (TIMER 0)		PWM_RODA_ESQUERDA
04-						SENTIDO_RODA_ESQUERDA
03-	PWM	(Timer 2)		SENSOR_COR_DIR_S3
02-						SENSOR_COR_DIR_S2
01-	Tx					SONAR_TRIGGER_LATERAL
00-	Rx					SONAR_ECHO_LATERAL

A0- 					SENSOR_LINHA_MAIS_ESQUERDO
A1-						SENSOR_LINHA_ESQUERDO
A2-						SENSOR_LINHA_DIREITO
A3-						SENSOR_LINHA_MAIS_DIREITO
A4-	SDA					SONAR_TRIGGER_FRONTAL
A5-	SCL				    SONAR_ECHO_FRONTAL


*/


class pinagem{

	#define PINO_PASSO_DIR_1 28
	#define PINO_PASSO_DIR_2 30
	#define PINO_PASSO_DIR_3 32
	#define PINO_PASSO_DIR_4 21

	#define PINO_PASSO_ESQ_1 13
	#define PINO_PASSO_ESQ_2 12
	#define PINO_PASSO_ESQ_3 11
	#define PINO_PASSO_ESQ_4 10

  //***PARA ARDUINO UNO E PRO MINI DEVE-SE UTILIZAR PARA MOTORES DC O PWM SOMENTE NAS PORTAS 5 E 6 ***/// 
  #define PWM_RODA_ESQUERDA 		4		//Define o pino que ligara o motor esquerdo para mudar a velocidade de rotacao 
  #define SENTIDO_RODA_ESQUERDA 5		//Define o pino que ligara o motor esquerdo para mudar o sentido de rotacao
  
	//***PARA ARDUINO UNO E PRO MINI DEVE-SE UTILIZAR PARA MOTORES DC O PWM SOMENTE NAS PORTAS 5 E 6 ***///
  #define PWM_RODA_DIREITA 			6		//Define o pino que ligara o motor direito para mudar a velocidade de rotacao 
  #define SENTIDO_RODA_DIREITA 	7		//Define o pino que ligara o motor direito para mudar o sentido de rotacao

	//A presente biblioteca pode controlar dois servomotores  
  #define SERVO_GARRA_1 				10	//Define o pino para "controlar" o servo motor 1
  #define SERVO_GARRA_2 				9		//Define o pino para "controlar" o servo motor 2
  
    //A presenta biblioteca para utilizar fim de cursos para diversas funções (gambiarras HAHA)
  #define FIM_DO_CURSO_1                50
  #define FIM_DO_CURSO_2                99
  #define FIM_DO_CURSO_3                99
  
	//A presente biblioteca utiliza 5 sensores de refletancia ou sensores de linha
  #define SENSOR_LINHA_MAIS_ESQUERDO	A0	//Define o pino do sensor de refletancia esquerdo 
  #define SENSOR_LINHA_ESQUERDO	A1	//Define o pino do sensor de refletancia esquerdo 
  #define SENSOR_LINHA_DIREITO	A2	//Define o pino do sensor de refletancia direito
  #define SENSOR_LINHA_MAIS_DIREITO	A3	//Define o pino do sensor de refletancia direito
  #define SENSOR_LINHA_MEIO A14 //Define o pino do sensor de refletancia do centro (MEIO)
   
  #define LED_SENSOR_LINHA_MAIS_ESQUERDO 38
  #define LED_SENSOR_LINHA_ESQUERDO 50
  #define LED_SENSOR_LINHA_DIREITO 21
  #define LED_SENSOR_LINHA_MAIS_DIREITO 20
  #define LED_SENSOR_LINHA_MEIO 99 //#MEIO

	//A biblioteca possui dois sensores de cor: um esquerdo e outro direito.
	//cada sensor de cor precisa de 3 pinos para configuracao e leitura da cor
	//Os pinos dos sensores de cor são específicos para o arduino UNO e podem ser modificados para o arduino mega
  #define SENSOR_COR_ESQ_S2			48	
  #define SENSOR_COR_ESQ_S3			50	
  #define SENSOR_COR_ESQ_OUT		52	

  #define SENSOR_COR_DIR_S2			28
  #define SENSOR_COR_DIR_S3			30
  #define SENSOR_COR_DIR_OUT		32

  #define SENSOR_COR_DIR_TCS34	99
  #define SENSOR_COR_ESQ_TCS34	99

	//A biblioteca possui dois sensores de distancia (Sonares)
  #define SONAR_TRIGGER_FRONTAL	16 //Pino analogico A4
  #define SONAR_ECHO_FRONTAL		17 //Pino analogico A5

  #define SONAR_TRIGGER_ESQ	22 
  #define SONAR_ECHO_ESQ		24 

  #define SONAR_TRIGGER_DIR	23 
  #define SONAR_ECHO_DIR		25 
	
//Pinos exclusivo para arduino mega

	#define BOTAO_1	29
	#define BOTAO_2	33
	#define BOTAO_3	41

	#define LED_1		53
	#define LED_2		51
	#define LED_3		49

};

#endif
