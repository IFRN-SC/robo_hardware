#ifndef COR_H
#define COR_H

#include <Arduino.h>
#include "CorHardware.h"

class SensorCor{
public:
  //construtor parametrizado -> s2 e s3 são os pinos de controle, e o out é o pino que recebera o valor
  //s0 e s1 não inicializados, pois vão ficar com valores lógicos permanentes (s0 -> HIGH, s1 -> LOW)	
  SensorCor(int s2_dado, int s3_dado, int out_dado);
  //metodo para receber o valor atual do sensor RGB	
  void atualizarRGB();
	
  int getVerde();
  int getVermelho();
  int getAzul();
       
  RGB getRGB();
  HSV getHSV();
  
private:
  int calculeMaximo(int vermelho, int verde, int azul);     
  int calculeMinimo(int vermelho, int verde, int azul);
  
  RGB rgb;
  HSV hsv;
  int s2 = 0;
  int s3 = 0; 
  int out = 0;
};


#endif
