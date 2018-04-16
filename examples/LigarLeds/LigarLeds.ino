#include <robo_hardware2.h> 
#include <Servo.h>

//********PINOS PARA LEDS***********//
//
//LED1			uno-;	mega-53
//LED2			uno-;	mega-51
//LED3			uno-;	mega-49
//
//*********PINOS PARA LEDS*********//

#define DELAY_TIME 500

void setup(){
	//Configura o robo.
	robo.configurar(false);
}

void loop(){
	for(int led=1; led<=3; led++){
		robo.ligarLed(led);
		delay(DELAY_TIME);
	}
	for(int led=1; led<=3; led++){
		robo.desligarLed(led);
		delay(DELAY_TIME);
	}
	for(int led=3; led<=1; led--){
		robo.ligarLed(led);
		delay(DELAY_TIME);
	}
	for(int led=3; led<=1; led--){
		robo.desligarLed(led);
		delay(DELAY_TIME);
	}

	for(int i=0; i<2; i++){	
	robo.ligarTodosLeds();
	delay(DELAY_TIME/2);

	robo.desligarTodosLeds();
	delay(DELAY_TIME/2);
	}
}

