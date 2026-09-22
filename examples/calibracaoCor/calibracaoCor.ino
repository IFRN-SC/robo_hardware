#include "robo_hardware2.h"

void setup() {
  Serial.begin(115200);
  robo.configurar();
  delay(200);
  robo.carregarCalibracao(); // tenta carregar calibração da EEPROM

  // Caso queira calibrar agora, desconente comentario:
  // Serial.println("Pressione ENTER para iniciar calibração");
  // while(!Serial.available()) delay(50);
  // while(Serial.available()) Serial.read();
  // robo.calibrarCoresConjunta();
}

void loop() {
  String esq = robo.lerNomeCorEsq();
  String dir = robo.lerNomeCorDir();
  Serial.print("Esq: "); Serial.print(esq);
  Serial.print("  |  Dir: "); Serial.println(dir);
  delay(400);
}
