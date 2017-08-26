#ifndef LOG_H
#define LOG_H

#include "cor.h"
#include "EEPROM2.h"

#define MAX_TAMANHO_LOG 100

#define SEPARADOR_CSV ';'

struct Refletancia{
	float esq;
	float dir;
};

struct DadosLog{
	Refletancia reflet;
//	HSV	hsvDir;
//	HSV hsvEsq;
//	int estado;
	unsigned long tempo;
	float motorEsq;
	float motorDir;

	void print(){
		Serial.print(tempo); 
		Serial.print(SEPARADOR_CSV);
		Serial.print(motorEsq);
		Serial.print(SEPARADOR_CSV);
		Serial.print(motorDir);	
		Serial.print(SEPARADOR_CSV);
		Serial.print(reflet.esq);
		Serial.print(SEPARADOR_CSV);
 		Serial.print(reflet.dir);
		Serial.println("");
	}
};

class Log{
	private:	
	DadosLog dados[MAX_TAMANHO_LOG];
	unsigned int posicaoParaAdicionar;
	unsigned int tamanhoVetorDados;
	String saida;

	#define ENDERECO_EEPROM_LOG 100

	public:
	Log();
	Log(const Log &l);
	void configurar();
	
	void adicionarDados(const DadosLog &entrada);
	void printDados();

	void salvarLog();
	void lerLog();


};

#endif
