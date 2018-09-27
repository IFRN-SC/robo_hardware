#include <Wire.h>
#include <EncoderI2C.h>

EncoderI2C encoder(ENDERECO_ENCODER_DIR);

void setup(){
    Serial.begin(9600);
    encoder.setPulsosPorRevolucao(224.4);//muda de acordo com o tipo de motor
}

void loop(){
  long l=0;
  float a=0;

  Serial.print("AngRelativo e AngAbsoluto: ");
  l=encoder.getAnguloRelativo();
  a=encoder.getAngulo();
  Serial.print(l);
  Serial.print("; ");
  Serial.println(a);

  delay(500);
}
