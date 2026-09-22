#ifndef PINAGEM_H
#define PINAGEM_H

#include <Arduino.h>

/*
Arduino MEGA pinout

  0  - Rx (Serial0)
  1  - Tx (Serial0)
  2  - Digital (PWM)
  3  - Digital (PWM)
  4  - Digital         SENTIDO_RODA_ESQUERDA
  5  - Digital (PWM)   PWM_RODA_ESQUERDA
  6  - Digital (PWM)   PWM_RODA_DIREITA
  7  - Digital         SENTIDO_RODA_DIREITA
  8  - Digital
  9  - Digital (PWM)
  10 - Digital (PWM)
  11 - Digital (PWM)
  12 - Digital
  13 - Digital (LED)
  14 - Tx (Serial3)
  15 - Rx (Serial3)
  16 - Tx (Serial2)
  17 - Rx (Serial2)
  18 - Tx (Serial1)
  19 - Rx (Serial1)
  20 - SDA (I²C)
  21 - SCL (I²C)
  22 - Digital
  23 - Digital   LED_SMD_VERDE
  24 - Digital
  25 - Digital   LED_AMARELO
  26 - Digital
  27 - Digital   LED_SMD_VERMELHO
  28 - Digital
  29 - Digital
  30 - Digital
  31 - Digital
  32 - Digital
  33 - Digital
  34 - Digital
  35 - Digital   LED_AZUL
  36 - Digital
  37 - Digital
  38 - Digital
  39 - Digital
  40 - Digital
  41 - Digital
  42 - Digital
  43 - Digital
  44 - Digital (PWM)
  45 - Digital (PWM)   LED_VERMELHO
  46 - Digital (PWM)
  47 - Digital
  48 - Digital
  49 - Digital
  50 - MISO (SPI)
  51 - MOSI (SPI)
  52 - SCK (SPI)
  53 - SS (SPI)   LED_VERDE

  A0  - Analógico   SENSOR_LINHA_MAIS_DIREITO
  A1  - Analógico 	LED_SENSOR_LINHA_MAIS_DIREITO
  A2  - Analógico   SENSOR_LINHA_DIREITO
  A3  - Analógico   LED_SENSOR_LINHA_DIREITO
  A4  - Analógico 	SENSOR_LINHA_ESQUERDO
  A5  - Analógico   LED_SENSOR_LINHA_ESQUERDO
  A6  - Analógico   SENSOR_LINHA_MAIS_ESQUERDO
  A7  - Analógico   LED_SENSOR_LINHA_MAIS_ESQUERDO
  A8  - Analógico 
  A9  - Analógico 
  A10 - Analógico 
  A11 - Analógico 
  A12 - Analógico 
  A13 - Analógico 
  A14 - Analógico 
  A15 - Analógico 
*/



class pinagem{
	#define PWM_RODA_ESQUERDA 		  5		        //Define o pino que ligara o motor esquerdo para mudar a velocidade de rotacao
	#define SENTIDO_RODA_ESQUERDA   4		        //Define o pino que ligara o motor esquerdo para mudar o sentido de rotacao
	#define PWM_RODA_DIREITA 	      6	          //Define o pino que ligara o motor direito para mudar a velocidade de rotacao
	#define SENTIDO_RODA_DIREITA 	  7		        //Define o pino que ligara o motor direito para mudar o sentido de rotacao

  #define SENSOR_LINHA_FRONTAL        A4      //Define o pino do sensor de refletancia frontal
  #define SENSOR_LINHA_CENTRAL        A7      //Define o pino do sensor de refletancia central
	#define SENSOR_LINHA_MAIS_ESQUERDO	A8	    //Define o pino do sensor de refletancia mais esquerdo
	#define SENSOR_LINHA_ESQUERDO	      A11	    //Define o pino do sensor de refletancia esquerdo
	#define SENSOR_LINHA_DIREITO	      A3	    //Define o pino do sensor de refletancia direito
	#define SENSOR_LINHA_MAIS_DIREITO	  A0	    //Define o pino do sensor de refletancia mais direito
  
  #define LED_SENSOR_LINHA_FRONTAL       A5   //Define o pino para ligar o sensor de refletancia frontal
  #define LED_SENSOR_LINHA_CENTRAL       A6   //Define o pino para ligar o sensor de refletancia central
	#define LED_SENSOR_LINHA_MAIS_ESQUERDO A9   //Define o pino para ligar o sensor de refletancia mais esquerdo
	#define LED_SENSOR_LINHA_ESQUERDO      A10  //Define o pino para ligar o sensor de refletancia esquerdo
	#define LED_SENSOR_LINHA_DIREITO       A2   //Define o pino para ligar o sensor de refletancia direito
	#define LED_SENSOR_LINHA_MAIS_DIREITO  A1   //Define o pino para ligar o sensor de refletancia mais direito
                                              
  #define  SEL_A  30
  #define  SEL_B  28

	#define SONAR_TRIGGER_FRONTAL	12            //Define o pino tigger do sensor sonar
	#define SONAR_ECHO_FRONTAL		13            //Define o pino echo do sensor sonar
	
	#define LED_SMD_VERDE      23
	#define LED_SMD_VERMELHO   27

	#define LED_AMARELO        25
	#define LED_AZUL           35
	#define LED_VERMELHO       45
	#define LED_VERDE          53
  
  #define SERVO_BRACO        9            //Define o pino do servo do braço
  #define SERVO_GARRA       11            //Define o pino do servo da
};

#endif
