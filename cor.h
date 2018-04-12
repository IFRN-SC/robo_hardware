#ifndef COR_H
#define COR_H

#include <Arduino.h>
#include "Adafruit_TCS34725.h"

struct RGB{   // Struct com valores de verde, vermelho e azul.
  int verde;
  int vermelho;
  int azul;

};

struct HSV{ // Struct com valores do HSV.
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
  void atualizarRGB_esquerdo(); // Liga o sensor em questão e o lê
  void atualizarRGB_direito();  // Liga o sensor em questão e o lê
	
  int getVerdeEsquerdo(); // Retorna o valor do Verde em RGB
  int getVermelhoEsquerdo(); // Retorna o valor do Vermelho em RGB
  int getAzulEsquerdo();      // Retorna o valor do Azul em RGB
  
  int getVerdeDireito(); // Retorna o valor do Verde em RGB
  int getVermelhoDireito(); // Retorna o valor do Vermelho em RGB
  int getAzulDireito();     // Retorna o valor do Azul em RGB
  
  RGB getRGB_esquerdo(); // Atualiza o valor do sensor (o lê) e retorna os 3 valores: R, G e B.
  HSV getHSV_esquerdo(); // Atualiza os valores do RGB, os converte para HSV e os retornam.
  
  RGB getRGB_direito(); // Atualiza o valor do sensor (o lê) e retorna os 3 valores: R, G e B.
  HSV getHSV_direito(); // Atualiza os valores do RGB, os converte para HSV e os retornam.
  
  
    
private:
  int calculeMaximo(int vermelho, int verde, int azul);  // Calcula o maior valor entre vermelho, verde e azul   
  int calculeMinimo(int vermelho, int verde, int azul);   // Calcula o menor valor entre vermelho, verde e azul
  
  RGB rgbDireito;  // Struct para os valores do sensor direito
  RGB rgbEsquerdo; // Struct para os valores do sensor esquerdo 
 
  Adafruit_TCS34725 tcsCorHardware; // Objeto tcsCorHardware da classe Adafruit

  uint16_t clear, red, green, blue; // Variáveis de leitura para a classe da Adafruit.
  
  void ligarSensorEsquerdo(); // Função que liga o sensor1 e desliga o sensor2
  void ligarSensorDireito(); // Função que liga o sensor2 e desliga o sensor1
  void lerSensor(); // Função para ler os valores de R, G e B.
  HSV getHSV(RGB rgb); // Converte os valores de RGB para HSV.
  
  const int PINO_SENSOR_COR_ESQUERDO; // Constante do pino que vai para o arduino
  const int PINO_SENSOR_COR_DIREITO;  // Constante do pino que vai para o arduino
  
  
  
};


#endif
