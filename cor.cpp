#include "cor.h"


SensorCor::SensorCor(int pino_sensor_cor_esquerdo, int pino_sensor_cor_direito):PINO_SENSOR_COR_ESQUERDO(pino_sensor_cor_esquerdo), PINO_SENSOR_COR_DIREITO(pino_sensor_cor_direito){ 

  tcsCorHardware = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X); // Instancia o objeto tcsCorHardware da classe Adafruit
  pinMode(pino_sensor_cor_esquerdo, OUTPUT);  // 
  pinMode(pino_sensor_cor_direito, OUTPUT);   // Define os pinos do sensor de cor como OUTPUT
  
}
void SensorCor::ligarSensorEsquerdo (){   // Função que liga o sensor1 e desliga o sensor2
  
  digitalWrite(PINO_SENSOR_COR_ESQUERDO, LOW);
  digitalWrite(PINO_SENSOR_COR_DIREITO, HIGH);
  delay(4);    // Delay para pode inicializar o sensor (se diminuido ou retirado, o sensor não conseguira inicializar).
  tcsCorHardware.begin(); // Método "begin" (começo) da classe do Adafruit. Inicializa o sensor. 
  
}

void SensorCor::ligarSensorDireito (){  // Função que liga o sensor2 e desliga o sensor1
  digitalWrite(PINO_SENSOR_COR_DIREITO, LOW);
  digitalWrite(PINO_SENSOR_COR_ESQUERDO, HIGH);
  delay(4);
  tcsCorHardware.begin();  
}

void SensorCor::lerSensor (){ // Função para ler os valores de R, G e B.
  
  delay(60);  
  tcsCorHardware.getRawData(&red, &green, &blue, &clear); // Método da classe Adafruit que lê os dados "brutos" do sensor.
  
}


void SensorCor::atualizarRGB_esquerdo(){ // Liga o sensor em questão e o lê
  ligarSensorEsquerdo();
  lerSensor();
  
  rgbEsquerdo.vermelho = red; //
  rgbEsquerdo.verde = green;  //
  rgbEsquerdo.azul = blue;    // Coloca os valores lidos em sua respectivas variáveis da struct RGB

}

void SensorCor::atualizarRGB_direito(){  // Liga o sensor em questão e o lê
  ligarSensorDireito();
  lerSensor();
  
  rgbDireito.vermelho = red;  // 
  rgbDireito.verde = green;   //
  rgbDireito.azul = blue;     // Coloca os valores lidos em sua respectivas variáveis da struct RGB

}

RGB SensorCor::getRGB_esquerdo(){ // Atualiza o valor do sensor (o lê) e retorna os 3 valores: R, G e B.
  atualizarRGB_esquerdo();
 return rgbEsquerdo;
}

RGB SensorCor::getRGB_direito(){ // Atualiza o valor do sensor (o lê) e retorna os 3 valores: R, G e B.
  atualizarRGB_direito();
  return rgbDireito;
}

int SensorCor::calculeMaximo(int vermelho, int verde, int azul){ // Calcula o maior valor entre vermelho, verde e azul
  int maximo = 0; // Armazena o menor valor entre os 3.
  if(verde >= vermelho && verde >= azul){
    maximo = verde;
  }else if(vermelho >= verde && vermelho >= azul){
    maximo = vermelho;
  }else if(azul >= verde && azul >= vermelho){
    maximo = azul;
  }
  return maximo;
}

int SensorCor::calculeMinimo(int vermelho, int verde, int azul){ // Calcula o menor valor entre vermelho, verde e azul
  int minimo = 0; // Armazena o menor valor entre os 3.
  if(verde <= vermelho && verde <= azul){
    minimo = verde;
  }else if(vermelho <= verde && vermelho <= azul){
    minimo = vermelho;
  }else if(azul <= verde && azul <= vermelho){
    minimo = azul;
  }
  return minimo;
} 

HSV SensorCor::getHSV(RGB rgb){ // Converte os valores de RGB para HSV. 
	
  HSV valorHsv;
		
  double maximo = 0; // 
  double minimo = 0; // variávels que armazenaram o maior e o menor valores entre o vermelho, verde e azul
  
  int vermelhoRGB =  rgb.vermelho; //
  int azulRGB = rgb.azul;          //
  int verdeRGB = rgb.verde;        // Variável que recebem os valores de suas respectivas cores em RGB
  
  minimo= calculeMinimo(vermelhoRGB,verdeRGB,azulRGB); //
  maximo = calculeMaximo(vermelhoRGB,verdeRGB,azulRGB);// Recebem o maior e o menor valores entre o vermelho, verde e azul   
  
  
  if(maximo == vermelhoRGB && verdeRGB >= azulRGB){
    valorHsv.h =  60 * (verdeRGB - azulRGB)/ (maximo - minimo); 
  }else if(maximo == vermelhoRGB && verdeRGB < azulRGB){
    valorHsv.h =  60 * (verdeRGB - azulRGB)/(maximo - minimo) + 360;
  }else if(maximo == verdeRGB){
    valorHsv.h =  60 * (azulRGB - vermelhoRGB)/(maximo - minimo) + 120;
  }else if(maximo == azulRGB){
    valorHsv.h =  60 * (vermelhoRGB - verdeRGB)/(maximo - minimo) + 240;
  } // Lógica que define o valor do H com base em cálculos
  
  valorHsv.s =  (maximo - minimo) / maximo; // 
  valorHsv.v = maximo;                      // Definem o S e V da struct HSV
  return valorHsv;     // Retorna os valores H, S e V.
}

HSV SensorCor::getHSV_esquerdo(){         //
  atualizarRGB_esquerdo();                //
  return getHSV(rgbEsquerdo);             // Atualiza os valores do RGB, os converte para HSV e os retornam.  
  
}

HSV SensorCor::getHSV_direito(){         //
  atualizarRGB_direito();                //
  return getHSV(rgbDireito);             // Atualiza os valores do RGB, os converte para HSV e os retornam.
}

int SensorCor::getVerdeEsquerdo(){ // Retorna o valor do Verde em RGB               
  return rgbEsquerdo.verde;                      
}                                                 
                                                
int SensorCor::getAzulEsquerdo(){ // Retorna o valor do Azul em RGB              
  return rgbEsquerdo.azul;
}
int SensorCor::getVermelhoEsquerdo(){ // Retorna o valor do Vermelho em RGB	
  return rgbEsquerdo.vermelho;
}

int SensorCor::getVerdeDireito(){ // Retorna o valor do Verde em RGB
  return rgbDireito.verde;
}

int SensorCor::getAzulDireito(){ // Retorna o valor do Azul em RGB
  return rgbDireito.azul;
}

int SensorCor::getVermelhoDireito(){ // Retorna o valor do Vermelho em RGB
  return rgbDireito.vermelho;
}