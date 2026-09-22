#include "robo_hardware2.h"
#include <math.h>
#include <EEPROM.h>

int robo_hardware::tipoSensorCor;
VL53L0X robo_hardware::sensor;

//----- construtor -----//
robo_hardware::robo_hardware():
	sonarFrontal(SONAR_TRIGGER_FRONTAL, SONAR_ECHO_FRONTAL),
	tcsD(TCS34725_INTEGRATIONTIME_614MS,TCS34725_GAIN_1X),
	tcsE(TCS34725_INTEGRATIONTIME_614MS,TCS34725_GAIN_1X){
}

//----- funções de controle dos motores -----//
void robo_hardware::tensao(float valor_por_cento,int pino){
  float k = 255/100.0;

  if(valor_por_cento < -100) 
    valor_por_cento = -100;	//se o valor passado em valor_por_cento for menor que -100 obriga-se o mmotor a ficar em -100
  if(valor_por_cento >  100) 
    valor_por_cento =  100;	//se o valor passado em valor_por_cento for maior que 100 obriga-se o mmotor a ficar em 100

  float valor_ate_255 = valor_por_cento * k;
  
  analogWrite(pino, abs(valor_ate_255)); 
}

void robo_hardware::acionarMotores(float motor1, float motor2){
 
  if(motor1 < 0){
    digitalWrite(SENTIDO_RODA_ESQUERDA, false);
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }else{
    digitalWrite(SENTIDO_RODA_ESQUERDA, true);
    motor1 = 100 - motor1;
    tensao(motor1,PWM_RODA_ESQUERDA);  
  }
  
  if(motor2 < 0){
    digitalWrite(SENTIDO_RODA_DIREITA, false);
    tensao(motor2,PWM_RODA_DIREITA);  
  }else{
    digitalWrite(SENTIDO_RODA_DIREITA, true);
    motor2 = 100 - motor2;
    tensao(motor2,PWM_RODA_DIREITA);  
  }
    
}

//----- função de inicialização -----//
void robo_hardware::configurar(bool distanciaHabilitada, bool corHabilitada){
	//Com essas funcoes os sonares sao calibrados 
	sonarFrontal.setDivisor(CALIBRACAO_SONAR, Ultrasonic::CM);  

	//Configura pinos da ponte H
  pinMode(PWM_RODA_ESQUERDA, OUTPUT); 
  pinMode(PWM_RODA_DIREITA, OUTPUT); 
	pinMode(SENTIDO_RODA_ESQUERDA, OUTPUT); 
	pinMode(SENTIDO_RODA_DIREITA, OUTPUT);

	//Configura pinos para ligar o sensor de linha
	pinMode(LED_SENSOR_LINHA_MAIS_ESQUERDO, OUTPUT);
	pinMode(LED_SENSOR_LINHA_ESQUERDO, OUTPUT);
	pinMode(LED_SENSOR_LINHA_DIREITO, OUTPUT);
	pinMode(LED_SENSOR_LINHA_MAIS_DIREITO, OUTPUT);
	pinMode(LED_SENSOR_LINHA_CENTRAL, OUTPUT);
	pinMode(LED_SENSOR_LINHA_FRONTAL, OUTPUT);

	//Configura pinos para ligar o sensor de linha
	pinMode(SENSOR_LINHA_MAIS_ESQUERDO, INPUT);
	pinMode(SENSOR_LINHA_ESQUERDO, INPUT);
	pinMode(SENSOR_LINHA_DIREITO, INPUT);
	pinMode(SENSOR_LINHA_MAIS_DIREITO, INPUT);
	pinMode(SENSOR_LINHA_CENTRAL, INPUT);
	pinMode(SENSOR_LINHA_FRONTAL, INPUT);

	//Configura pinos para ligar os LEDS
	pinMode(LED_SMD_VERDE, OUTPUT);
	pinMode(LED_SMD_VERMELHO, OUTPUT);

	pinMode(LED_AMARELO, OUTPUT);
	pinMode(LED_AZUL, OUTPUT);
	pinMode(LED_VERMELHO, OUTPUT);
	pinMode(LED_VERDE, OUTPUT);

  if (corHabilitada) {
    //Configura o sensor de cor
    Wire.begin();
    tcsD.begin();
    tcsE.begin();
  }

	pinMode(SEL_A, OUTPUT);
	pinMode(SEL_B, OUTPUT);
	
	digitalWrite(SEL_A, LOW);
	digitalWrite(SEL_B, HIGH);
	
  if(distanciaHabilitada){
    //configura sensor frontal de distância a laiser
    sensor.init();
    sensor.setTimeout(500);
  }

	//configurar o servo do braço
	servoBraco.attach(SERVO_BRACO); // pino do braço
  servoGarra.attach(SERVO_GARRA); // pino da garra

	servoGarra.write(0);  // fecha a garra
  servoBraco.write(0);
}

//----- função para ler o sensor de linha com ruido -----//
const float robo_hardware::lerSensorDeLinha(const int sensor, bool ledLigado=true){
	int pino;
	float val=0;
	switch(sensor){
		case SENSOR_LINHA_MAIS_ESQUERDO:
			pino = LED_SENSOR_LINHA_MAIS_ESQUERDO;
		break;
			
		case SENSOR_LINHA_ESQUERDO:
			pino = LED_SENSOR_LINHA_ESQUERDO;
		break;

		case SENSOR_LINHA_DIREITO:
			pino = LED_SENSOR_LINHA_DIREITO;
		break;

		case SENSOR_LINHA_MAIS_DIREITO:
			pino = LED_SENSOR_LINHA_MAIS_DIREITO;
		break;

		case SENSOR_LINHA_CENTRAL:
			pino = LED_SENSOR_LINHA_CENTRAL;
		break;

		case SENSOR_LINHA_FRONTAL:
			pino = LED_SENSOR_LINHA_FRONTAL;
		break;
	}

	digitalWrite(pino, ledLigado);

	delay(1);
	
	val = ( 100 - 100.0 * ( analogRead(sensor) )/1023.0);

	digitalWrite(pino, LOW);

	return val;
}

//----- função para ler o sensor de linha sem ruido -----//
const float robo_hardware::lerDadosSensorDeLinha(const int sensor){
	float valorLedDesligado = 0;
	float valorLedLigado    = 0;

	valorLedDesligado = lerSensorDeLinha(sensor, LOW);
	valorLedLigado    = lerSensorDeLinha(sensor);
	
	return valorLedLigado -  valorLedDesligado;
	
	
}

//----- função para ler o sensor sonar -----//
float robo_hardware::lerSensorSonarFrontal(){
	long microsec = sonarFrontal.timing();
	return sonarFrontal.convert(microsec, Ultrasonic::CM);  //retorna a distância do sensor ao obstáculo em cm.
}

//----- funções para sensor de cor -----//
RGBC robo_hardware::getRGBSensorEsq() const{
	int red, green, blue, clear;
	tcsE.getRawData(&red, &green, &blue, &clear);
	return {red, green, blue, clear};
}

RGBC robo_hardware::getRGBSensorDir() const{
	int red, green, blue, clear;
	tcsD.getRawData(&red, &green, &blue, &clear);
	return {red, green, blue, clear};
}

void robo_hardware::canal00() const{
	digitalWrite(SEL_A, LOW);
	digitalWrite(SEL_B, LOW);
}

void robo_hardware::canal01() const{
	digitalWrite(SEL_A, LOW);
	digitalWrite(SEL_B, HIGH);
}

void robo_hardware::canal10() const{
	digitalWrite(SEL_A, HIGH);
	digitalWrite(SEL_B, LOW);
}

RGBC robo_hardware::lerSensorDeCorEsq(){
	canal00();
	delay(100);
	return getRGBSensorEsq();
	delay(100);	
}

RGBC robo_hardware::lerSensorDeCorDir(){
	canal10();
	delay(100);
	return getRGBSensorDir();
	delay(100);
}

//----- funções para sensor Laiser-----//
int robo_hardware::lerSensorLaserFrontal() const{
	canal01();
	delay(1);

	int valDist;
	valDist =sensor.readRangeSingleMillimeters();
	return valDist;
}

//----- funções para os leds -----//
void robo_hardware::ligarLed(const int led)const{
	digitalWrite( led, HIGH);
}

void robo_hardware::desligarLed(const int led)const{
	digitalWrite( led, LOW);
}

void robo_hardware::ligarTodosLeds()const{
	ligarLedSmdVerde();
	ligarLedSmdVermelho();
	ligarLedAmarelo(); 
	ligarLedAzul();     
	ligarLedVermelho();
	ligarLedVerde();
}

void robo_hardware::desligarTodosLeds()const{
	desligarLedSmdVerde();
	desligarLedSmdVermelho();
	desligarLedAmarelo(); 
	desligarLedAzul();     
	desligarLedVermelho();
	desligarLedVerde();
}

#include <EEPROM.h> // garantir inclusão no .cpp também

// definição da variável estática
CalibracaoCor robo_hardware::calib = {
  // valores iniciais marcando inválidos
  {0,0,0, 0,0,0, false},
  {0,0,0, 0,0,0, false}
};

// --- helper: ler média de N amostras do sensor (esquerda = true, direita = false)
void robo_hardware::lerMediaRGBdoSensor(bool esquerda, RGBC &out, uint8_t amostras) {
  uint32_t rSum = 0, gSum = 0, bSum = 0;
  for (uint8_t i = 0; i < amostras; i++) {
    RGBC tmp = (esquerda ? lerSensorDeCorEsq() : lerSensorDeCorDir());
    rSum += (uint32_t) tmp.red;
    gSum += (uint32_t) tmp.green;
    bSum += (uint32_t) tmp.blue;
    delay(60);
  }
  out.red   = (float)(rSum / amostras);
  out.green = (float)(gSum / amostras);
  out.blue  = (float)(bSum / amostras);
  // clear não usado na média de calibração, mas pode ser adicionado se quiser
}

// --- normaliza raw RGB usando calibração do sensor para 0..255
void robo_hardware::normalizarRGBComCal(const RGBC &raw, const SensorCal &sc, int &rNorm, int &gNorm, int &bNorm) {
  // se calib inválida, apenas escala proporcionalmente (fallback)
  if (!sc.valido) {
    // evita divisão por zero: normaliza por soma
    float soma = raw.red + raw.green + raw.blue;
    if (soma <= 0.0f) { rNorm = gNorm = bNorm = 0; return; }
    rNorm = (int)constrain((raw.red / soma) * 255.0f, 0, 255);
    gNorm = (int)constrain((raw.green / soma) * 255.0f, 0, 255);
    bNorm = (int)constrain((raw.blue / soma) * 255.0f, 0, 255);
    return;
  }

  // map com constrain usando limites calibrados
  uint16_t rClamped = (uint16_t)constrain((uint32_t)raw.red, (uint32_t)sc.rBlack, (uint32_t)sc.rWhite);
  uint16_t gClamped = (uint16_t)constrain((uint32_t)raw.green, (uint32_t)sc.gBlack, (uint32_t)sc.gWhite);
  uint16_t bClamped = (uint16_t)constrain((uint32_t)raw.blue, (uint32_t)sc.bBlack, (uint32_t)sc.bWhite);

  // evita passar limites iguais -> retorna 0/255 direto se limites iguais
  if (sc.rWhite == sc.rBlack) rNorm = 0; else rNorm = map(rClamped, sc.rBlack, sc.rWhite, 0, 255);
  if (sc.gWhite == sc.gBlack) gNorm = 0; else gNorm = map(gClamped, sc.gBlack, sc.gWhite, 0, 255);
  if (sc.bWhite == sc.bBlack) bNorm = 0; else bNorm = map(bClamped, sc.bBlack, sc.bWhite, 0, 255);

  rNorm = constrain(rNorm, 0, 255);
  gNorm = constrain(gNorm, 0, 255);
  bNorm = constrain(bNorm, 0, 255);
}

// --- identifica cor a partir de RGB normalizado 0..255
String robo_hardware::identificarCorPorRGB(int r, int g, int b) {
  int maxVal = max(r, max(g, b));
  int minVal = min(r, min(g, b));
  int diff = maxVal - minVal;

  if (maxVal < 30) return "Preto";
  if (maxVal > 230 && diff < 20) return "Branco";
  if (diff < 20) return "Cinza";

  // lógica simples baseada em dominância e proximidade
  if (r >= g && r >= b) {
    // vermelho dominante
    return "Vermelho";
  }
  if (g >= r && g >= b) {
    return "Verde";
  }
  // b dominante
  if (b >= r && b >= g) {
    return "Azul";
  }
  return "Indefinido";
}

// --- salvar / carregar calibracao na EEPROM
void robo_hardware::salvarCalibracao() {
  EEPROM.put(ENDERECO_EEPROM, calib);
  Serial.println(F("✅ Calibração de cores salva na EEPROM"));
}

void robo_hardware::carregarCalibracao() {
  EEPROM.get(ENDERECO_EEPROM, calib);
  // validação básica: verifica se pelo menos uma das flags está true e limites coerentes
  bool okE = calib.esquerda.valido &&
             (calib.esquerda.rWhite > calib.esquerda.rBlack) &&
             (calib.esquerda.gWhite > calib.esquerda.gBlack) &&
             (calib.esquerda.bWhite > calib.esquerda.bBlack);

  bool okD = calib.direita.valido &&
             (calib.direita.rWhite > calib.direita.rBlack) &&
             (calib.direita.gWhite > calib.direita.gBlack) &&
             (calib.direita.bWhite > calib.direita.bBlack);

  if (okE || okD) {
    Serial.println(F("📥 Carregada calibração da EEPROM:"));
    if (okE) {
      Serial.println(F(" - Esquerda válida"));
    } else Serial.println(F(" - Esquerda inválida"));
    if (okD) {
      Serial.println(F(" - Direita válida"));
    } else Serial.println(F(" - Direita inválida"));
  } else {
    Serial.println(F("⚠️ Nenhuma calibração válida na EEPROM"));
    // marca inválidos para evitar uso incorreto
    calib.esquerda.valido = false;
    calib.direita.valido  = false;
  }
}

// --- rotina de calibração conjunta (GUI via Serial) ---
void robo_hardware::calibrarCoresConjunta() {
  Serial.println(F("=== Calibracao conjunta dos sensores (esquerdo+direito) ==="));
  delay(700);

  // Função lambda para calibrar um sensor específico
  auto calibrarSensor = [&](bool esquerda, SensorCal &sc, const char* nomeSensor) {
    RGBC raw;
    Serial.print(F("> Preparar para calibrar PRETO ("));
    Serial.print(nomeSensor);
    Serial.println(F("). Posicione e pressione ENTER no Serial Monitor."));
    // espera ENTER
    while (!Serial.available()) { delay(50); }
    while (Serial.available()) Serial.read(); // limpa buffer

    // lê média
    lerMediaRGBdoSensor(esquerda, raw, 12);
    sc.rBlack = (uint16_t) raw.red;
    sc.gBlack = (uint16_t) raw.green;
    sc.bBlack = (uint16_t) raw.blue;
    Serial.print(F("  PRETO lido -> R:")); Serial.print(sc.rBlack);
    Serial.print(F(" G:")); Serial.print(sc.gBlack);
    Serial.print(F(" B:")); Serial.println(sc.bBlack);
    delay(400);

    Serial.print(F("> Agora calibrar BRANCO ("));
    Serial.print(nomeSensor);
    Serial.println(F("). Posicione e pressione ENTER no Serial Monitor."));
    while (!Serial.available()) { delay(50); }
    while (Serial.available()) Serial.read(); // limpa buffer

    lerMediaRGBdoSensor(esquerda, raw, 12);
    sc.rWhite = (uint16_t) raw.red;
    sc.gWhite = (uint16_t) raw.green;
    sc.bWhite = (uint16_t) raw.blue;
    Serial.print(F("  BRANCO lido -> R:")); Serial.print(sc.rWhite);
    Serial.print(F(" G:")); Serial.print(sc.gWhite);
    Serial.print(F(" B:")); Serial.println(sc.bWhite);
    delay(200);

    // valida e marca
    bool valido = (sc.rWhite > sc.rBlack) && (sc.gWhite > sc.gBlack) && (sc.bWhite > sc.bBlack);
    sc.valido = valido;
    if (valido) Serial.println(F("  OK: calibração válida."));
    else Serial.println(F("  ERRO: limites inválidos, repita calibração."));
    delay(300);
  };

  // calibrar esquerda
  calibrarSensor(true, calib.esquerda, "Esquerdo");

  // calibrar direita
  calibrarSensor(false, calib.direita, "Direito");

  // salvar
  salvarCalibracao();
  Serial.println(F("=== FIM calibração conjunta ==="));
}

// --- funções públicas para ler nome da cor (usa calibração correspondente) ---
String robo_hardware::lerNomeCorEsq() {
  RGBC raw = lerSensorDeCorEsq();
  int rN, gN, bN;
  normalizarRGBComCal(raw, calib.esquerda, rN, gN, bN);
  return identificarCorPorRGB(rN, gN, bN);
}

String robo_hardware::lerNomeCorDir() {
  RGBC raw = lerSensorDeCorDir();
  int rN, gN, bN;
  normalizarRGBComCal(raw, calib.direita, rN, gN, bN);
  return identificarCorPorRGB(rN, gN, bN);
}

RGBC robo_hardware::lerSensorDeCorEsqNormatizado() {
  RGBC raw = lerSensorDeCorEsq();
  int rN, gN, bN;
  normalizarRGBComCal(raw, calib.esquerda, rN, gN, bN);
  return { (float)rN, (float)gN, (float)bN };
}

RGBC robo_hardware::lerSensorDeCorDirNormatizado() {
  RGBC raw = lerSensorDeCorDir();
  int rN, gN, bN;
  normalizarRGBComCal(raw, calib.direita, rN, gN, bN);
  return { (float)rN, (float)gN, (float)bN };
}