#include <robo_hardware.h> 
#include <Servo.h>

//********PINOS PARA SENSORES DE COR***********//
//  S0	GND
//  S1  VCC
//  S2  11
//  S3  16  A2
//  OUT 17  A3
//*********PINOS PARA SENSORES DE COR*********//


//  O tipo HSV e formado por tres valores: 
//  float h   //valor varia de 0 ate 359
//  float s   //valor varia de 0 ate 1. Isso inclui: 0.1 0.34 0.73
//  int v     //valor vaira de 0 ate 255
HSV leituraSensorCor; //Declaração de uma variável do tipo RGB

void setup(){
  Serial.begin(9600);
  robo.configurar(false);
}

void loop(){
  leituraSensorCor = robo.getHSVEsquerdo(); //FUNCAO PARA LER VALOR DO SENSOR LATERAL


  //imprime os 3 valores retornardos pelo sensor cor
  Serial.print("Valor do sensor de cor: ");
  Serial.print(leituraSensorCor.h);
  Serial.print(", ");
  Serial.print(leituraSensorCor.s);
  Serial.print(", ");
  Serial.print(leituraSensorCor.v);
  
  Serial.println();
  
  delay(500);
}
