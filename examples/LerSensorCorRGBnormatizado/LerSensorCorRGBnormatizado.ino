#include <robo_hardware2.h> 
#include <Servo.h>

//-----PINOS PARA SENS/ORES DE COR I2C-----//
//  SDA_SENSOR_COR_DIREITO  42
//  SCL_SENSOR_COR_DIREITO  40
//  LED_SENSOR_COR_DIREITO  38

//  SDA_SENSOR_COR_ESQUERDO  32
//  SCL_SENSOR_COR_ESQUERDO  34
//  LED_SENSOR_COR_ESQUERDO  36
//-----PINOS PARA SENSORES DE COR I2C-----//


//O tipo RGB e formado por quatro valores: vermelho, verde, azul, claridade
RGBC leituraSensorCorDir; 
RGBC leituraSensorCorEsq; 

 void setup(){
  Serial.begin(9600);
  robo.configurar();
  delay(200);
  robo.carregarCalibracao();
}

void loop(){
  leituraSensorCorDir = robo.lerSensorDeCorDirNormatizado(); //FUNCAO PARA LER VALOR DO SENSOR DE COR DIREITO

  //imprime os 3 valores retornardos pelo sensor cor
  Serial.print("Valor do sensor de cor DIR: ");
  Serial.print(leituraSensorCorDir.red);
  Serial.print(", ");
  Serial.print(leituraSensorCorDir.green);
  Serial.print(", ");
  Serial.print(leituraSensorCorDir.blue);
   Serial.print(", ");
  Serial.print(leituraSensorCorDir.clear);
  
  Serial.print( " " );
  
  leituraSensorCorEsq = robo.lerSensorDeCorEsqNormatizado(); //FUNCAO PARA LER VALOR DO SENSOR DE COR ESQUERDO

  //imprime os 3 valores retornardos pelo sensor cor
  Serial.print("Valor do sensor de cor ESQ: ");
  Serial.print(leituraSensorCorEsq.red);
  Serial.print(", ");
  Serial.print(leituraSensorCorEsq.green);
  Serial.print(", ");
  Serial.print(leituraSensorCorEsq.blue);
   Serial.print(", ");
  Serial.print(leituraSensorCorEsq.clear);
  
  Serial.println();
  delay(500);
}
