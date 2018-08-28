#include "MotorPasso.h"

MotorPasso::MotorPasso(const int passosPorRotacaoEsq,
				   	   const int passosPorRotacaoDir): 
		PASSOS_POR_ROTACAO_ESQ(passosPorRotacaoEsq), PASSOS_POR_ROTACAO_DIR(passosPorRotacaoDir),
		
		passoEsq(PASSOS_POR_ROTACAO_ESQ, PINO_PASSO_ESQ_1, PINO_PASSO_ESQ_3, PINO_PASSO_ESQ_2, PINO_PASSO_ESQ_4, 17, false),
		passoDir(PASSOS_POR_ROTACAO_DIR, PINO_PASSO_DIR_1, PINO_PASSO_DIR_3, PINO_PASSO_DIR_2, PINO_PASSO_DIR_4, 15, false)

{}

MotorPasso::MotorPasso():
		PASSOS_POR_ROTACAO_ESQ(PASSOS_POR_ROTACAO_ESQ_DEFAULT), PASSOS_POR_ROTACAO_DIR(PASSOS_POR_ROTACAO_DIR_DEFAULT),
		
		passoEsq(PASSOS_POR_ROTACAO_ESQ, PINO_PASSO_ESQ_1, PINO_PASSO_ESQ_3, PINO_PASSO_ESQ_2, PINO_PASSO_ESQ_4, 17, false),
		passoDir(PASSOS_POR_ROTACAO_DIR, PINO_PASSO_DIR_1, PINO_PASSO_DIR_3, PINO_PASSO_DIR_2, PINO_PASSO_DIR_4, 15, false)
{}

void MotorPasso::acionarMotorPasso(int velEsq, int velDir){
	this->velEsq = converteRPM(velEsq);
	this->velDir = converteRPM(velDir);

	passoDir.setSpeed(this->velDir);
	passoEsq.setSpeed(this->velEsq);

	int nPassoEsq = N_PASSOS_ESQ;
	int nPassoDir = N_PASSOS_DIR;

	if(velEsq < 0) nPassoEsq *= -1;
	if(velDir < 0) nPassoDir *= -1;
	
	if(this->velEsq == 0) nPassoEsq = 0;
	if(this->velDir == 0) nPassoDir = 0;
		
	passoDir.step(nPassoDir);
	passoEsq.step(nPassoEsq);
}

void MotorPasso::acionarMotoresEmGraus(int vel, double graus){
	if (graus < 0) vel *= -1;
	graus = map(abs(graus), 0, 360, 0, PASSOS_POR_ROTACAO_ESQ*32);

	for(int i = 0; i < graus ; i++)
		acionarMotorPasso(vel, vel);
}


void MotorPasso::acionarAngEsq(int ang, int vel=50){
	this->velEsq = converteRPM(vel);
	passoEsq.setSpeed(this->velEsq);

	int nPassos = map(abs(ang), 0, 360, 0, PASSOS_POR_ROTACAO_ESQ*32);
	
	if(ang < 0) nPassos *= -1;
	passoEsq.step(nPassos);
}

void MotorPasso::acionarAngDir(int ang, int vel=50){
	this->velDir = converteRPM(vel);
	passoDir.setSpeed(this->velDir);

	int nPassos = map(abs(ang), 0, 360, 0, PASSOS_POR_ROTACAO_DIR*32);
	
	if(ang < 0) nPassos *= -1;
	passoDir.step(nPassos);
}

