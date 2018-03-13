#ifndef COR_H
#define COR_H

#include <Arduino.h>
#include "Adafruit_TCS34725.h"

struct RGB{
  int verde;
  int vermelho;
  int azul;

};

struct HSV{
  float h;
  double s;
  float v;
};

class SensorCor{
public:
  //construtor parametrizado -> s2 e s3 são os pinos de controle, e o out é o pino que recebera o valor
  
  //s0 e s1 não inicializados, pois vão ficar com valores lógicos permanentes (s0 -> HIGH, s1 -> LOW)	
  SensorCor(int pino_sensor_cor_esquerdo, int pino_sensor_cor_direito);
  //metodo para receber o valor atual do sensor RGB	
  void atualizarRGB_esquerdo();
  void atualizarRGB_direito();
	
  int getVerde_esquerdo();
  int getVermelho_esquerdo();
  int getAzul_esquerdo();
  
  int getVerde_direito();
  int getVermelho_direito();
  int getAzul_direito();
  
  RGB getRGB_esquerdo();
  HSV getHSV_esquerdo();
  
  RGB getRGB_direito();
  HSV getHSV_direito();
  
  
    
private:
  int calculeMaximo(int vermelho, int verde, int azul);     
  int calculeMinimo(int vermelho, int verde, int azul);

	//float saturar(float val);
  
  RGB rgb_direito;
  RGB rgb_esquerdo;
 
  Adafruit_TCS34725 tcs;

  uint16_t clear, red, green, blue; 
  
  void ligar_sensor1();
  void ligar_sensor2();
  void ler_sensor();
  HSV getHSV(RGB rgb);
  
  const int PINO_SENSOR_COR_ESQUERDO;
  const int PINO_SENSOR_COR_DIREITO;
  
  
  
};


#endif
