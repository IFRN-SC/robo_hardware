#ifndef LOG_H
#define LOG_H

#include "cor.h"

#define MAX_TAMANHO_LOG 100

struct Refletancia{
	float esq;
	float dir;
};

struct DadosLog{
	Refletancia reflet;
//	HSV	hsvDir;
//	HSV hsvEsq;
	int estado;
	long tempo;
	float motorEsq;
	float motorDir;
};

class Log{
	private:	
	DadosLog dados[MAX_TAMANHO_LOG];
	unsigned int posicaoParaAdicionar;
	unsigned int tamanhoVetorDados;
	String saida;

	public:
	Log();
	Log(const Log &l);
	void configurar();
	
	void adicionarDados(const DadosLog &entrada);
	const String& printDados();

};

#endif