#ifndef PINAGEM_H
#define PINAGEM_H

class pinagem{

  //********PINOS PARA MOTOR ESQUERDO***********//
  #define PWM_RODA_ESQUERDA 		5		//Define o pino que ligara o motor esquerdo para mudar a velocidade de rotacao/amarelo 
  #define SENTIDO_RODA_ESQUERDA 	4		//Define o pino que ligara o motor esquerdo para mudar o sentido de rotacao/verde
  
  //********PINOS PARA MOTOR DIREITO***********//
  #define PWM_RODA_DIREITA 		6		//Define o pino que ligara o motor direito para mudar a velocidade de rotacao/amarelo 
  #define SENTIDO_RODA_DIREITA 		7		//Define o pino que ligara o motor direito para mudar o sentido de rotacao/azul

  //A presente biblioteca pode controlar dois servomotores  
  #define SERVO_GARRA_1 		10		//Define o pino para "controlar" o servo motor 1
  #define SERVO_GARRA_2 		9		//Define o pino para "controlar" o servo motor 2


  //*********PINOS PARA SENSORES DE REFLETANCIA*********//
  #define SENSOR_LINHA_ESQUERDO		A5		//Define o pino do sensor de refletancia esquerdo 
  #define SENSOR_LINHA_DIREITO		A4		//Define o pino do sensor de refletancia direito
  #define SENSOR_LINHA_MAIS_ESQUERDO	A0		//Define o pino do sensor de refletancia mais esquerdo
  #define SENSOR_LINHA_MAIS_DIREITO	A1		//Define o pino do sensor de refletancia mais direito

  //A biblioteca possui dois sensores de cor: um esquerdo e outro direito.
  //cada sensor de cor precisa de 3 pinos para configuracao e leitura da cor
  //Os pinos dos sensores de cor são específicos para o arduino UNO e podem ser modificados para o arduino mega

  //**********PINOS PARA SENSORES DE COR*************//
  #define SENSOR_COR_ESQ_S2		50		//Define o pino do sensor de cor S2 esquerdo 
  #define SENSOR_COR_ESQ_S3		52		//Define o pino do sensor de cor S3 esquerdo
  #define SENSOR_COR_ESQ_OUT		48		//Define o pino do sensor de cor OUT esquerdo

  #define SENSOR_COR_DIR_S2		36		//Define o pino do sensor de cor S2 direito
  #define SENSOR_COR_DIR_S3		34		//Define o pino do sensor de cor S3 direito
  #define SENSOR_COR_DIR_OUT		38		//Define o pino do sensor de cor OUT esquerdo

  //*******A biblioteca possui dois sensores de distancia(Sonares)*******//
  #define SONAR_TRIGGER_FRONTAL		A9 		//Define o pino do sensor sonar Trigger frontal
  #define SONAR_ECHO_FRONTAL		A8		//Define o pino do sensor sonar Echo frontal

  #define SONAR_TRIGGER_LADO_ESQUERDO	A7 		//Define o pino do sensor sonar Trigger lateral esquerdo
  #define SONAR_ECHO_LADO_ESQUERDO	A6 		//Define o pino do sensor sonar Echo lateral esquerdo

  #define SONAR_TRIGGER_LADO_DIREITO	A4 		//Define o pino do sensor sonar Trigger lateral direito
  #define SONAR_ECHO_LADO_DIREITO	A5 		//Define o pino do sensor sonar Echo lateral direito
	
};

#endif
