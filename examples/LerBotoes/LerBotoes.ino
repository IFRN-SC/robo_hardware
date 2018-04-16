#include <robo_hardware2.h>
#include <string.h>

//********PINOS PARA BOTAO***********//
//
//BOTAO1			uno-;	mega-29
//BOTAO2			uno-;	mega-33
//BOTAO3			uno-;	mega-41
//
//*********PINOS PARA BOTAO*********//

#define DELAY_TIME 500

void setup(){
	Serial.begin(9600);
	//Configura o robo.
	robo.configurar(false);
}

void loop(){
	robo.botao1Pressionado() ? robo.ligarLed(1) : robo.desligarLed(1); //Liga o LED1 se o botão 1 for pressionado
	printBotao("Botao 1:", robo.botao1Pressionado());									 //exibe sim se o botão 1 for pressionado e senão exibe não
	Serial.print("; ");
	robo.botao2Pressionado() ? robo.ligarLed(2) : robo.desligarLed(2); //Liga o LED2 se o botão 2 for pressionado
	printBotao("Botao 2:", robo.botao2Pressionado());									 //exibe sim se o botão 2 for pressionado e senão exibe não
	Serial.print("; ");
	robo.botao3Pressionado() ? robo.ligarLed(3) : robo.desligarLed(3); //Liga o LED3 se o botão 3 for pressionado
	printBotao("Botao 3:", robo.botao3Pressionado());									 //exibe sim se o botão 3 for pressionado e senão exibe não
	Serial.println("");

	delay(DELAY_TIME);
}

void printBotao(const String &s, bool press){
	Serial.print(s);
	if(press){
		Serial.print(" sim");
	}
	else{
		Serial.print(" não");		
	}
}
