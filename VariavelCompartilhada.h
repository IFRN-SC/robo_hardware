#ifndef VARIAVEL_COMPARTILHADA_H
#define VARIAVEL_COMPARTILHADA_H

#include <util/atomic.h>

template <class T> class VarCompartilhada{
	T variavel;

	public:
	
	VarCompartilhada(){
	}
	
	VarCompartilhada(const VarCompartilhada &c){
		//obriga que tudo que estiver dentro do block seja executado de forma atomica
		//ou seja, desabilita a interrupcao enquanto estiver dentro desse bloco
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE){ //chamada de um macro
			variavel = c.variavel;
		}
	}

	VarCompartilhada(T v){
		set(v);
	}
	

	void set(T v){
		//obriga que tudo que estiver dentro do block seja executado de forma atomica
		//ou seja, desabilita a interrupcao enquanto estiver dentro desse bloco
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE){ //chamada de um macro
			variavel = v;
		}
	}

	T get()const{
		T v;
		//obriga que tudo que estiver dentro do block seja executado de forma atomica
		//ou seja, desabilita a interrupcao enquanto estiver dentro desse bloco
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE){ //chamada de um macro
			v = variavel;
		}
		return v;		
	}
	
	T operator=(const T v){
		set(v);
		return v;
	}

	VarCompartilhada operator ++ (int i){
		//obriga que tudo que estiver dentro do block seja executado de forma atomica
		//ou seja, desabilita a interrupcao enquanto estiver dentro desse bloco
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE){ //chamada de um macro
			variavel++;
		}
		return *this;
	}

	VarCompartilhada operator -- (int i){
		//obriga que tudo que estiver dentro do block seja executado de forma atomica
		//ou seja, desabilita a interrupcao enquanto estiver dentro desse bloco
		ATOMIC_BLOCK(ATOMIC_RESTORESTATE){ //chamada de um macro
			variavel--;
		}
		return *this;
	}

	bool operator == (T v)const{
		return (get() == v);
	}

	bool operator != (T v)const{
		return (get() != v);
	}

	T operator * (T v)const{
		return (get() * v);
	}
};

#endif
