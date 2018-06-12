#include "CorHardware.h"

int CorHardware::calculeMaximo(int vermelho, int verde, int azul){
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

int CorHardware::calculeMinimo(int vermelho, int verde, int azul){
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

RGB CorHardware::getRGB(){
  atualizarRGB();
  return rgb;
}

HSV CorHardware::getHSV(){
  atualizarRGB();

  float Maximo = 0;
  float Minimo = 0;
	HSV hsv;
  
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
