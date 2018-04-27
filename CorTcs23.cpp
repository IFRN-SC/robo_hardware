#include "CorTcs23.h"

CorTcs23::CorTcs23(int s2_dado, int s3_dado, int out_dado){
  s2 = s2_dado;
  s3 = s3_dado;
  out = out_dado;

  pinMode(s2, OUTPUT);  
  pinMode(s3, OUTPUT);  
  pinMode(out, INPUT);   
  	 
}

void CorTcs23::atualizarRGB(){

  digitalWrite(s2, LOW);  
  digitalWrite(s3, LOW);  
  rgb.vermelho = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  

  digitalWrite(s3, HIGH);  
  rgb.azul = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);  


  digitalWrite(s2, HIGH);    
  rgb.verde = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH); 

}