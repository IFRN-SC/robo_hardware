#ifndef BOTAO_H
#define BOTAO_H
class Botao{
	private:
	const int pinoBotao;
	
	public:
	Botao(const int pin):pinoBotao(pin){}
	inline void config(){ pinMode(BOTAO, INPUT_PULLUP); }
	inline const bool estaPressionado(){return ( digitalRead(pinoBotao)==LOW ? true : false );}

};

#endif
