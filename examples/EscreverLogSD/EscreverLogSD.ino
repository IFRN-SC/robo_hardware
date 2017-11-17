#include <robo_hardware2.h>
#include <SD.h>
#include <Servo.h>

DadosLog dl;

void setup(){
  Log l;
  l.configurar();
  
  for(int i=0; i<100; i++){
    delay(100);
    
    dl.reflet.esq=1*i;
    dl.reflet.dir=2*i;
    dl.estado = 3*i;
    dl.tempo = 4*i;
    dl.motorEsq = 5*i;
    dl.motorDir = 6*i;
    
    l.adicionarDados(dl);
    
    l.write();
  }
}

void loop(){
  
}
