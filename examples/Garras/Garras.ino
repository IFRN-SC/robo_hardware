#include <robo_hardware2.h>

void setup() {
  // put your setup code here, to run once:
  robo.configurar(true);
}

void loop() {
  //*********************************************SERVO 1****************************************************************
  robo.acionarServoGarra1(0); // seta o servo 1 para 0 graus
  delay(1000); // para por um segundo
  robo.acionarServoGarra1(90); // seta o servo 1 para 90 graus
  delay(1000); // para por um segundo

  robo.acionarServoGarra1(0, 90, 20); // leva o servo 1 de 0 para 90 graus com um delay de 20 segundos entre cada grau
  delay(1000); // para por um segundo
  
  robo.acionarServoGarra1(90, 0, 20); // leva o servo 1 de 90 para 0 graus com um delay de 20 segundos entre cada grau
  delay(1000); // para por um segundo

  //*********************************************SERVO 2****************************************************************

  robo.acionarServoGarra2(0); // seta o servo 2 para 0 graus
  delay(1000); // para por um segundo
  robo.acionarServoGarra2(90); // seta o servo 2 para 90 graus
  delay(1000); // para por um segundo

  robo.acionarServoGarra2(0, 90, 20); // leva o servo 2 de 0 para 90 graus com um delay de 20 segundos entre cada grau
  delay(1000); // para por um segundo
  
  robo.acionarServoGarra2(90, 0, 20); // leva o servo 2 de 90 para 0 graus com um delay de 20 segundos entre cada grau
  delay(1000); // para por um segundo

}
