//exemplo para ler valores de calibracao que estao salvos na memoria persistente do arduino a eeprom

#include <robo_hardware2.h>
#include <Servo.h>

calibracao_dados val; //dados de calibracao para sensores de cor e sensores de refletancia

/*****  Dados existentes na Struct calibracao_dados  *******************

HSV branco;
HSV preto;
HSV verde;
HSV cinza;

int refletancia_dir;
int refletancia_mais_dir;
int refletancia_esq;
int refletancia_mais_esq;

************************/


void setup() {
  //inicializando a porta serial
  Serial.begin(9600);
  while (!Serial) {
    ; 
  }
}

void loop() {
  // Le os dados da EEPROM
  robo.lerCalibracao(val);

  Serial.print(val.branco.h);
  Serial.print("; ");
  Serial.print(val.branco.s);
  Serial.print("; ");
  Serial.print(val.branco.v);  
  Serial.print("; ");
  Serial.print(val.refletancia_dir);  
  Serial.print("; ");
  Serial.print(val.refletancia_esq);    
  Serial.println();

  delay(500);
}
