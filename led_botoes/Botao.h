#ifndef BOTAO_H
#define BOTAO_H
class Botao{
	private:
	const int pinoBotao;
	
	public:
	Botao(const int pin):pinoBotao(pin){}
	inline void config(){ pinMode(pinoBotao, INPUT_PULLUP); }
	inline const bool estaPressionado()const{return ( digitalRead(pinoBotao)==LOW ? true : false );}

};

#endif
