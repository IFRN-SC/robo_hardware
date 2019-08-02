#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA SENSORES DE COR ANALÓGICO***********//
//********SENSOR DIREITO***********************//
//  S0	5V  nivel logico baixo
//  S1  0V  nivel logico alto
//  S2  uno-2;	mega-28
//  S3  uno-3;	mega-30  
//  OUT uno-8;	mega-32
//********SENSOR ESQUERDO**********************//
//  S0	5V  nivel logico baixo
//  S1  0V  nivel logico alto
//  S2  uno-11;	mega-38
//  S3  uno-12;	mega-40
//  OUT uno-13;	mega-42
//*********PINOS PARA SENSORES DE COR ANALÓGICO*********//

//********PINOS PARA SENSORES DE COR I2C***********//
//********SENSOR DIREITO***********************//
//  SDA	        uno-A4;	mega-21
//  SCL	        uno-A5;	mega-20  
//  VIN	OU 3V3  uno-3;	mega-38
//********SENSOR ESQUERDO**********************//
//  SDA	        uno-A4;	mega-21
//  SCL	        uno-A5;	mega-20
//  VIN	OU 3V3  uno-2;	mega-50
//*********PINOS PARA SENSORES DE COR I2C*********//


//  O tipo HSV e formado por tres valores: 
//  float h   //valor varia de 0 ate 359
//  float s   //valor varia de 0 ate 1. Isso inclui: 0.1 0.34 0.73
//  int v     //valor vaira de 0 ate 255
HSV leituraSensorCor; //Declaração de uma variável do tipo RGB

void setup(){
  Serial.begin(9600);
  robo.configurar(false);
  //robo.habilitaTCS34();
  // ********* DESCOMENTE A LINHA ACIMA SE ESTIVER USANDO O SENSOR DE COR DIGITAL (TCS 34725) ***********
}

void loop(){
  leituraSensorCor = robo.getHSVEsquerdo(); //FUNCAO PARA LER VALOR DO SENSOR DE COR ESQUERDO


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
