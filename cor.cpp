#include "cor.h"


SensorCor::SensorCor(int pino_sensor_cor_esquerdo, int pino_sensor_cor_direito):PINO_SENSOR_COR_ESQUERDO(pino_sensor_cor_esquerdo), PINO_SENSOR_COR_DIREITO(pino_sensor_cor_direito){ 

  tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);
  pinMode(pino_sensor_cor_esquerdo, OUTPUT);  
  pinMode(pino_sensor_cor_direito, OUTPUT);    
  
}
void SensorCor::ligar_sensor1 (){
  
  digitalWrite(PINO_SENSOR_COR_ESQUERDO, LOW);
  digitalWrite(PINO_SENSOR_COR_DIREITO, HIGH);
  delay(4);
  tcs.begin(); 
  
}

void SensorCor::ligar_sensor2 (){
  digitalWrite(PINO_SENSOR_COR_DIREITO, LOW);
  digitalWrite(PINO_SENSOR_COR_ESQUERDO, HIGH);
  delay(4);
  tcs.begin();  
}

void SensorCor::ler_sensor (){
  
  delay(60);  
  tcs.getRawData(&red, &green, &blue, &clear);
  
}


void SensorCor::atualizarRGB_esquerdo(){
  ligar_sensor1();
  ler_sensor();
  
  rgb_esquerdo.vermelho = red; 
  rgb_esquerdo.verde = green;
  rgb_esquerdo.azul = blue;

}

void SensorCor::atualizarRGB_direito(){
  ligar_sensor2();
  ler_sensor();
  
  rgb_direito.vermelho = red; 
  rgb_direito.verde = green;
  rgb_direito.azul = blue;

}

RGB SensorCor::getRGB_esquerdo(){
  atualizarRGB_esquerdo();
 return rgb_esquerdo;
}

RGB SensorCor::getRGB_direito(){
  atualizarRGB_direito();
  return rgb_direito;
}

int SensorCor::calculeMaximo(int vermelho, int verde, int azul){
  int Maximo = 0; 
  if(verde >= vermelho && verde >= azul){
    Maximo = verde;
  }else if(vermelho >= verde && vermelho >= azul){
    Maximo = vermelho;
  }else if(azul >= verde && azul >= vermelho){
    Maximo = azul;
  }
  return Maximo;
}

int SensorCor::calculeMinimo(int vermelho, int verde, int azul){
  int Minimo = 0;
  if(verde <= vermelho && verde <= azul){
    Minimo = verde;
  }else if(vermelho <= verde && vermelho <= azul){
    Minimo = vermelho;
  }else if(azul <= verde && azul <= vermelho){
    Minimo = azul;
  }
  return Minimo;
}

HSV SensorCor::getHSV_esquerdo(){
	atualizarRGB_esquerdo();
	return getHSV(rgb_esquerdo);
	
}

HSV SensorCor::getHSV_direito(){
	atualizarRGB_direito();
	return getHSV(rgb_direito);
	
	
} 

HSV SensorCor::getHSV(RGB rgb){
	
  HSV hsv;
		
  double Maximo = 0;
  double Minimo = 0;
  
  int vermelho =  rgb.vermelho;
  int azul = rgb.azul;
  int verde = rgb.verde;
  
  Minimo = calculeMinimo(vermelho,verde,azul);
  Maximo = calculeMaximo(vermelho,verde,azul);
  
  
  if(Maximo == vermelho && verde >= azul){
    hsv.h =  60 * (verde - azul)/ (Maximo - Minimo)  ; 
  }else if(Maximo == vermelho && verde < azul){
    hsv.h =  60 * (verde - azul)/(Maximo - Minimo) + 360;
  }else if(Maximo == verde){
    hsv.h =  60 * (azul - vermelho)/(Maximo - Minimo) + 120;
  }else if(Maximo == azul){
    hsv.h =  60 * (vermelho - verde)/(Maximo - Minimo) + 240;
  }
  
  hsv.s =  (Maximo - Minimo) / Maximo;
  hsv.v = Maximo;
  return hsv;
}

int SensorCor::getVerde_esquerdo(){
  return rgb_esquerdo.verde;
}

int SensorCor::getAzul_esquerdo(){
  return rgb_esquerdo.azul;
}
int SensorCor::getVermelho_esquerdo(){	
  return rgb_esquerdo.vermelho;
}

int SensorCor::getVerde_direito(){
  return rgb_direito.verde;
}

int SensorCor::getAzul_direito(){
  return rgb_direito.azul;
}

int SensorCor::getVermelho_direito(){
  return rgb_direito.vermelho;
}