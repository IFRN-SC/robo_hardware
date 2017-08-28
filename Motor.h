#ifndef MOTOR_H
#define MOTOR_H

#include "encoder.h"
#include "contr_motor.h"
#include "pinagem.h"


class Motor{
	public:
	
	Motor(byte pino_pwm, byte pino_direcao);
	Motor(byte pino_pwm, byte pino_direcao, Encoder e);

	void configurar();
	
	void acionarMotor(float percetualMotor);
  void acionarMotorVel(float velMotor);
	void acionarMotorPos(float angMotor);

	void calculaPulso();

	const long getTempoAmostragemContr()const;

	void loopControle();

	const double getTensaoContr()const  {return ( (contrPosHabilitado==true)? contrPos.getOutput():contrVel.getOutput() ); }
	const double getInputContr ()const  {return ( (contrPosHabilitado==true)? contrPos.getInput():contrVel.getInput() ); }
	const double getSetPointContr()const{return ( (contrPosHabilitado==true)? contrPos.getSetPoint():contrVel.getSetPoint() ); }

	
	private:

	void tensao(float valor_por_cento, int pino);
	void habilitaControlePosicao();
	void habilitaControleVelocidade();
	void desabilitaControle();

	Encoder encoder;
	contr_motor contrVel, contrPos;
	const bool ENCODER_HABILITADO;
	VarCompartilhada <bool> contrPosHabilitado;
	VarCompartilhada <bool> contrVelHabilitado;
	VarCompartilhada <double> angulo;
	VarCompartilhada <double> velocidade;
	const byte PINO_PWM, PINO_DIRECAO;
	
};

#endif
