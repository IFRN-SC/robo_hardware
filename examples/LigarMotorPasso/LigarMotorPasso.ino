#include <robo_hardware2.h>

void setup() {
  // put your setup code here, to run once:
  robo.configurar(false); 
}

void loop() {  
  //Liga os dois motores com 50% da valocidade maxima
  robo.acionarMotoresPasso(50, 50);
  delay(1000);

  //Desliga os dois motores
  robo.acionarMotoresPasso(0, 0);
  delay(1000);

  //Liga os dois motores com 50% da velocidade maxima so que no sentido oposto
  robo.acionarMotoresPasso(-50, -50);
  delay(1000);

  //Desliga os dois motores
  robo.acionarMotoresPasso(0, 0);
  delay(1000);

}
