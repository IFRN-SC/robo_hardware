#include <robo_hardware2.h>

int const LED_COR = 7;                // porta digital para o sensor de cor no pino LED
int const SENSOR_COR_DIR_TCS34 = 38;  // porta digital para pegarmos a cor que o sensor esta lendo

void setup() {
    Serial.begin (9600);
    robo.configurar(false); 
    robo.habilitaTCS34();
    pinMode (LED_COR, OUTPUT);
    pinMode(SENSOR_COR_DIR_TCS34, OUTPUT);          
    digitalWrite(SENSOR_COR_DIR_TCS34, HIGH);
}

void loop() { 
    digitalWrite (LED_COR, HIGH);                        // ascendemos o led do sensor de cor
    HSV leituraSensorCor = robo.getHSVDireito ();        // pegamos os valos HSV com a interferencia
    
    // vamos mostrar os valores com interferencia
    // imprime os 3 valores retornardos pelo sensor cor
    Serial.print("Valor do sensor de cor com inteferencia: ");
    Serial.print(leituraSensorCor.h);
    Serial.print(", ");
    Serial.print(leituraSensorCor.s);
    Serial.print(", ");
    Serial.println(leituraSensorCor.v);
    delay (500);

    digitalWrite (LED_COR, LOW);                               // desligamos o led do sensor de cor
    HSV leituraSensorCorLedDesligado = robo.getHSVDireito ();  // pegamos os valos HSV com o led do sensor desligado

    // vamos mostrar os valores sem a interferencia do led
    // imprime os 3 valores retornardos pelo sensor cor
    Serial.print("Valor do sensor de cor com led desligado: ");
    Serial.print(leituraSensorCorLedDesligado.h);
    Serial.print(", ");
    Serial.print(leituraSensorCorLedDesligado.s);
    Serial.print(", ");
    Serial.println(leituraSensorCorLedDesligado.v);
    delay (500);


    // vamos realizar a operação para pegarmos os valores sem inteferencia
    int h = leituraSensorCor.h - leituraSensorCorLedDesligado.h;
    float s = leituraSensorCor.s - leituraSensorCorLedDesligado.s;
    int v = leituraSensorCor.v - leituraSensorCorLedDesligado.v;

    // vamos mostrar os valores sem a interferencia
    // imprime os 3 valores retornardos pelo sensor cor
    Serial.print("Valor do sensor de cor sem inteferencia: ");
    Serial.print(h);
    Serial.print(", ");
    Serial.print(s);
    Serial.print(", ");
    Serial.println(v);
    delay (500);

    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
    Serial.println();
   
}
