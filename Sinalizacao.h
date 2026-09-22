#ifndef SINALIZACAO_H
#define SINALIZACAO_H

#include "pinagem.h"

class Sinalizacao{
    private:
    int tempo_anterior;
    int intervalo_led_verde;
    int intervalo_led_amarelo;
    int intervalo_led_vermelho;

    void piscarLed(const int PINO_LED, const int INTERVALO);

    public:

    Sinalizacao();
    
    void config();

    inline void ligarLedVerde(){ digitalWrite(LED_VERDE, HIGH);}
    inline void ligarLedAmarelo(){ digitalWrite(LED_AMARELO, HIGH);}
    inline void ligarLedVermelho(){ digitalWrite(LED_VERMELHO, HIGH);}

    inline void desligarLedVerde(){ digitalWrite(LED_VERDE, LOW);}
    inline void desligarAmarelo(){ digitalWrite(LED_AMARELO, LOW);}
    inline void desligarLedVermelho(){ digitalWrite(LED_VERMELHO, LOW);}

    inline void piscarLedVerde(){ piscarLed(LED_VERDE, intervalo_led_verde);}
    inline void piscarLedAmarelo(){ piscarLed(LED_AMARELO, intervalo_led_amarelo);}
    inline void piscarLedVermelho(){ piscarLed(LED_VERMELHO, intervalo_led_vermelho);}

    
};

#endif