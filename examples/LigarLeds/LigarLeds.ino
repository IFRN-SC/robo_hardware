#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA LEDS***********//
//
// LED_AMARELO        25
// LED_AZUL           35
// LED_VERMELHO       45
// LED_VERDE          53
//
//*********PINOS PARA LEDS*********//

void setup(){
	robo.configurar();
}

void loop(){
	robo.ligarTodosLeds();
	delay(500);
	robo.desligarTodosLeds();
	delay(500);
}

