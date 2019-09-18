#ifndef MOTORPASSO_H
#define MOTORPASSO_H

#include <Arduino.h>
#include "Stepper.h"

#include "pinagem.h"

class MotorPasso: private pinagem {
	public:
		MotorPasso(const int passosPorRotacaoEsq,
				   const int passosPorRotacaoDir);
		MotorPasso();
		
		void acionarMotorPasso(int velEsq, int velDir);
		void acionarMotoresEmGraus(int vel, double grau);
		void acionarAngEsq(int ang, int vel);
		void acionarAngDir(int ang, int vel);

	private: 
		#define VELMAX 620

		#define N_PASSOS_DIR 1;
		#define N_PASSOS_ESQ 1;
		
		#define PASSOS_POR_ROTACAO_ESQ_DEFAULT 64
		#define PASSOS_POR_ROTACAO_DIR_DEFAULT 64

		const int PASSOS_POR_ROTACAO_DIR;
		const int PASSOS_POR_ROTACAO_ESQ;
		
		Stepper passoEsq, passoDir;

		int velEsq, velDir;
		inline int converteRPM(int velEmPercentual){return map(abs(velEmPercentual), 0, 100, 0, VELMAX);}
};

#endif
