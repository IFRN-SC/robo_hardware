#include "cor.h"

SensorCor::SensorCor(int s2_dado, int s3_dado, int out_dado){
  s2 = s2_dado;
  s3 = s3_dado;
  out = out_dado;

  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);   
  	 
}

void SensorCor::atualizarRGB(){
  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  rgb.vermelho = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  

  digitalWrite(s3, HIGH);  
  rgb.azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  


  digitalWrite(s2, HIGH);    
  rgb.verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 

}

RGB SensorCor::getRGB(){
  atualizarRGB();
  return rgb;
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

HSV SensorCor::getHSV(){
  atualizarRGB();
  float Maximo = 0;
  float Minimo = 0;
  
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

int SensorCor::getVerde(){
  return rgb.verde;
}

int SensorCor::getVermelho(){
  return rgb.vermelho;
}

int SensorCor::getAzul(){
  return rgb.azul;
}
