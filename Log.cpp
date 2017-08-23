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

void Log::configurar(){
	
}


void Log::adicionarDados(const DadosLog &entrada){
	dados[posicaoParaAdicionar] = entrada;
	dados[posicaoParaAdicionar].tempo = millis();
	posicaoParaAdicionar++;	

	if(tamanhoVetorDados < MAX_TAMANHO_LOG)
		tamanhoVetorDados++;

	if(posicaoParaAdicionar >= MAX_TAMANHO_LOG) 
		posicaoParaAdicionar=0;
}

const String& Log::printDados(){
	for (int i=0; i<tamanhoVetorDados; i++){
		saida += String(dados[i].tempo) + " "; 
		//saida += String(dados[i].motorEsq);// + " " + String(dados[i].motorDir) + " ";	
		//saida += dados[i].reflet.esq + " " + dados[i].reflet.dir;
		saida += "\n";
	}



}
