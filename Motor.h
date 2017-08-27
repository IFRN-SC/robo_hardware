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
	
	private:

	void tensao(float valor_por_cento, int pino);

	Encoder encoder;
	contr_motor contrVel, contrPos;
	bool encoder_habilitado;
	const byte PINO_PWM, PINO_DIRECAO;
};

#endif
