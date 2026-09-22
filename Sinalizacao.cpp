#include "Sinalizacao.h"

Sinalizacao::Sinalizacao(){
    intervalo_led_verde     = 500;
    intervalo_led_amarelo   = 500;
    intervalo_led_vermelho  = 500;
}

void Sinalizacao::config(){
    //Configura pinos para ligar os LEDS
	pinMode(LED_SMD_VERDE, OUTPUT);
	pinMode(LED_SMD_VERMELHO, OUTPUT);

	pinMode(LED_AMARELO, OUTPUT);
	pinMode(LED_AZUL, OUTPUT);
	pinMode(LED_VERMELHO, OUTPUT);
	pinMode(LED_VERDE, OUTPUT);
}

void Sinalizacao::piscarLed(const int PINO_LED, const int INTERVALO){
    int tempo_atual = millis();

    if (tempo_atual - tempo_anterior > INTERVALO){
        tempo_anterior = tempo_atual;
        bool estado = !digitalRead(PINO_LED);
        digitalWrite(PINO_LED, estado);
    }
}