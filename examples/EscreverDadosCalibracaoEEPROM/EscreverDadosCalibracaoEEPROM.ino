//exemplo para escrever valores de calibracao que estao salvos na memoria persistente do arduino a eeprom

#include <robo_hardware.h>
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


void setup(){
  
  //Modificando os valores de calibracao
  val.refletancia_dir=1;
  val.branco.s=2.2;
  val.branco.v=3;  
  val.refletancia_esq=2;
  val.refletancia_mais_dir=5;
}

void loop(){
    //Salvando os dados na memoria persistente
   robo.salvarCalibracao(val);
}

