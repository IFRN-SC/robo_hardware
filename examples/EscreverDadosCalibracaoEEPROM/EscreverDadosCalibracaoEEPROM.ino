//exemplo para escrever valores de calibracao que estao salvos na memoria persistente do arduino a eeprom

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


void setup(){
  
  //Modificando os valores de calibracao
  val.refletanciaDir=1;
  val.brancoEsq.s=2.2;
  val.brancoDir.v=3;  
  val.refletanciaEsq=2;
  val.refletanciaMaisDir=5;
}

void loop(){
    //Salvando os dados na memoria persistente
   robo.salvarCalibracao(val);
}

