#include <Log.h>
#include <Servo.h>

Log debug;

void setup(){
	debug.lerLog(); //Faz a leitura dos dados presentes na eeprom e atualiza as variáveis do próprio objeto
	debug.printDados(); //Envia pela porta serial os dados armazenados no objeto
}

void loop(){

}
