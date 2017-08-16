#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA SENSORES DE COR***********//
//********SENSOR DIREITO***********************//
//  S0	5V  nivel logico baixo
//  S1  0V  nivel logico alto
//  S2  2
//  S3  3  
//  OUT 8 
//********SENSOR ESQUERDO**********************//
//  S0	5V  nivel logico baixo
//  S1  0V  nivel logico alto
//  S2  11
//  S3  12  
//  OUT 13  
//*********PINOS PARA SENSORES DE COR*********//


//  O tipo RGB e formado por tres inteiros: vermelho, verde, azul
RGB leituraSensorCor; //Declaração de uma variável do tipo RGB

void setup(){
  Serial.begin(9600);
  robo.configurar(false);
}

void loop(){
  leituraSensorCor = robo.getRGBEsquerdo(); //FUNCAO PARA LER VALOR DO SENSOR LATERAL


  //imprime os 3 valores retornardos pelo sensor cor
  Serial.print("Valor do sensor de cor: ");
  Serial.print(leituraSensorCor.vermelho);
  Serial.print(", ");
  Serial.print(leituraSensorCor.verde);
  Serial.print(", ");
  Serial.print(leituraSensorCor.azul);
  
  Serial.println();
  
  delay(500);
}
