#include <robo_hardware2.h>
#include <Servo.h>

char c='0';
float ref=0, errEsq=0, errDir=0;

void setup() {
  robo.configurar(false);  
  Serial.begin(9600);
}


void loop() {
  float angEsq=0, angDir=0;
  
  
  angEsq = robo.getAngEncoderEsq();
  angDir = robo.getAngEncoderDir();

  errEsq= ref-angEsq;
  errDir= ref-angDir;

  if(errEsq>  100)errEsq  =  100;
  if(errEsq< -100)errEsq  = -100;

  if(errDir> 100)errDir =  100;
  if(errDir<-100)errDir = -100;

  robo.acionarMotores(errEsq, errDir);

  Serial.print("angEsq; angDir; errEsq; errDir: ");
  Serial.print(angEsq);
  Serial.print("; ");
  Serial.print(angDir);
  Serial.print("; ");
  Serial.print(errEsq);
  Serial.print("; ");
  Serial.println(errDir);

  delay(100);

  ref=ler();
}

float ler(){

  if(Serial.available()){
    c = Serial.read();
  }
  //Serial.println(c);
  switch(c){
    case '0':
    return 0;
    break;
    case '1':
    return 90;
    break;
    case '2':
    return 180;
    break;
    default:
    return 270;
    break;
  }
  return 0;
  
}
