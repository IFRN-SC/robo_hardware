//exemplo para ler valores de calibracao que estao salvos na memoria persistente do arduino a eeprom

#include <robo_hardware2.h>
#include <Servo.h>

calibracao_dados val; //dados de calibracao para sensores de cor e sensores de refletancia

/*****  Dados existentes na Struct calibracao_dados  *******************

  HSV brancoDir;
  HSV brancoEsq;
  HSV pretoDir;
  HSV pretoEsq;
  HSV verdeDir;
  HSV verdeEsq;
  HSV cinzaDir;
  HSV cinzaEsq;

  int refletanciaDir;
  int refletanciaMaisDir;
  int refletanciaEsq;
  int refletanciaMaisEsq;
  



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

  Serial.print(val.brancoEsq.h);
  Serial.print("; ");
  Serial.print(val.brancoDir.s);
  Serial.print("; ");
  Serial.print(val.brancoDir.v);  
  Serial.print("; ");
  Serial.print(val.refletanciaDir);  
  Serial.print("; ");
  Serial.print(val.refletanciaEsq);    
  Serial.println();

  delay(500);
}
