#include <robo_hardware2.h>

void setup(){
  robo.configurar(false);
  Serial.begin(9600);
}

void loop(){

  Ypr ypr;

  ypr = robo.lerSensorImu();

  Serial.print("ypr\t");
  Serial.print(ypr.y * 180/M_PI);
  Serial.print("\t");
  Serial.print(ypr.p * 180/M_PI);
  Serial.print("\t");
  Serial.println(ypr.r * 180/M_PI);

  delay(200);
}
