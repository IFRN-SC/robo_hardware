#include <robo_hardware2.h>
#include <Servo.h>

void setup() {
  robo.configurar(false);  
  Serial.begin(9600);
}


void loop() {
  float angEsq=0, angDir=0;
  
  angEsq = robo.getAngEncoderEsq();
  angDir = robo.getAngEncoderDir();

  Serial.print("Angulo esquerdo e direito: ");
  Serial.print(angEsq);
  Serial.print("; ");
  Serial.println(angDir);

  delay(1000);
}
