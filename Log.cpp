#include "Log.h"

Log::Log(){

	posicaoParaAdicionar=0;
	tamanhoVetorDados=0;
	
}

Log::Log(const Log &l){
	posicaoParaAdicionar =l.posicaoParaAdicionar;
	for (int i=0; i<MAX_TAMANHO_LOG; i++ ){
		dados[i]= l.dados[i];
	}
}

bool Log::configurar(){
	SD.begin(48);
	file = SD.open("WR_TEST2.TXT", O_CREAT | O_WRITE);
	if(file)
		return true;

	return false;
}


void Log::adicionarDados(const DadosLog &entrada){
	dados[posicaoParaAdicionar] = entrada;
	dados[posicaoParaAdicionar].salvarTempo();
	posicaoParaAdicionar++;	

	if(tamanhoVetorDados < MAX_TAMANHO_LOG)
		tamanhoVetorDados++;

	if(posicaoParaAdicionar >= MAX_TAMANHO_LOG) 
		posicaoParaAdicionar=0;
}

void Log::printDados(){
	for (int i=0; i<tamanhoVetorDados; i++){
		dados[i].print();
	}

}

//void Log::salvarLog(){
//	EEPROM.put(ENDERECO_EEPROM_LOG, *this);
//}

void Log::lerLog(){
//	EEPROM.get(ENDERECO_EEPROM_LOG, *this);
}

void Log::salvarLog(){
	tempo_gravacao= micros();

	file.print(dados[0].getMicroSegundos());
	file.print(SEPARADOR_CSV);
	file.print(dados[0].getSegundos());
	file.print(SEPARADOR_CSV);		
	file.print(dados[0].reflet.esq);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].reflet.dir);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].estado);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].motorEsq);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].motorDir);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].hsvEsq.h);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].hsvEsq.s);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].hsvEsq.v);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].hsvDir.h);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].hsvDir.s);
	file.print(SEPARADOR_CSV);
	file.print(dados[0].hsvDir.v);
	file.print(SEPARADOR_CSV);

	tempo_gravacao= micros() - tempo_gravacao;	

	file.println(tempo_gravacao);

	file.flush();
}

