#include <robo_hardware2.h> 
#include <Servo.h>
#include <Log.h>
#include <SD.h>

//*************PINOS PARA LIGAR MOTORES*************//
//   Motor direito:
//pino1 PWM_RODA_DIREITA	6
//pino2 SENTIDO_RODA_DIREITA	7
//   Motor esquerdo:
//pino1 PWM_RODA_ESQUERDA	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//*********PINOS PARA LIGAR MOTORES*********//

//********PINOS PARA SENSORES REFLETANCIA***********//
//
//SENSOR_LINHA_ESQUERDO			A0
//
//SENSOR_LINHA_DIREITO			A1
//
//*********PINOS PARA SENSORES REFLETANCIA*********//

#define DIVISOR_BRANCO_PRETO 50

#define LED_VERMELHO 53
#define LED_AZUL 49

float valor_sensor_dir;
float valor_sensor_esq;

float valor_motor_esq;
float valor_motor_dir;

Log debug;
DadosLog dados;

void setup(){
   pinMode(LED_VERMELHO,OUTPUT);
   pinMode(LED_AZUL,OUTPUT);
   
   digitalWrite(LED_AZUL,HIGH);
   if(debug.configurar()){
     digitalWrite(LED_VERMELHO, LOW);
   }
   else{
     while(true){
       digitalWrite(LED_VERMELHO, HIGH);   // turn the LED on (HIGH is the voltage level)
       delay(1000);               // wait for a second
       digitalWrite(LED_VERMELHO, LOW);    // turn the LED off by making the voltage LOW
       delay(1000);               // wait for a second
     }
   }
	robo.configurar(false);

}

void loop(){
        digitalWrite(LED_AZUL,LOW);
	valor_sensor_esq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valor_sensor_dir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir

	//Identifica se os dois sensores viram branco
	if(valor_sensor_esq > DIVISOR_BRANCO_PRETO && valor_sensor_dir > DIVISOR_BRANCO_PRETO){
		//Aciona os dois motores com a mesma velocidade
		valor_motor_esq=-30;
		valor_motor_dir=-30;
	}
	//Identifica se o sensor da esquerda viu banco e o da direita viu preto
	else if (valor_sensor_esq > DIVISOR_BRANCO_PRETO && valor_sensor_dir < DIVISOR_BRANCO_PRETO){
		//Aciona o motor esquerdo para frente e aciona o motor direito para tras
		valor_motor_esq=50;
		valor_motor_dir=-30;				
	}
	//Identifica se o sensor da direita viu banco e o da esquerda viu preto
	else if (valor_sensor_esq < DIVISOR_BRANCO_PRETO && valor_sensor_dir > DIVISOR_BRANCO_PRETO){
		//Aciona o motor direito para frente e aciona o motor esquerdo para tras
		valor_motor_esq=-30;
		valor_motor_dir=50;
	}
	else{ //Identifica se os dois sensores viram preto
		valor_motor_esq=-30;
		valor_motor_dir=50;				
	}

	robo.acionarMotores(valor_motor_esq, valor_motor_dir);



	dados.salvarTempo();
	dados.motorEsq = valor_motor_esq;
	dados.motorDir = valor_motor_dir;
	dados.reflet.esq = valor_sensor_esq;
	dados.reflet.dir = valor_sensor_dir;

	debug.adicionarDados(dados);

        digitalWrite(LED_AZUL,HIGH);

	debug.salvarLog();


}
