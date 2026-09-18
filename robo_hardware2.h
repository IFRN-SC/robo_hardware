#ifndef ROBO_HARDWARE_H
#define ROBO_HARDWARE_H


#include <Arduino.h>
#include <Servo.h>
#include <EEPROM.h>

#include "pinagem.h"
#include "Ultrasonic.h"
#include "Adafruit_TCS34725.h"
#include <VL53L0X.h>

struct refletancia_dados{
	float valorLedLigado;
	float valorLedDesligado;
	float valorDiferenca;
};
struct RGBC{
	float red;
	float green;
	float blue;
	float clear;
};
struct SensorCal {
  uint16_t rBlack;
  uint16_t gBlack;
  uint16_t bBlack;
  uint16_t rWhite;
  uint16_t gWhite;
  uint16_t bWhite;
  bool valido;
};
struct CalibracaoCor {
  SensorCal esquerda;
  SensorCal direita;
};
class robo_hardware:private pinagem{
private:

	#define AJUSTE_PINO_SENSOR 36
	#define OFF 0
	#define AJUSTE_MOTOR 0.65
	#define MAX_10_BITS 1023.0				//Maior valor que um numero de 10 bits pode obter
	
	#define CALIBRACAO_SONAR  40.4	       //Valor para calibrar os sonares. Quanto maior esse valor menor a inclinação da reta de calibracao

	#define ENDERECO_EEPROM 0

public: 
	//construtor 
	robo_hardware();

  	void configurar(bool corHabilitada=false);

	//A função para acionar os motores de locomoção do robô
  	void acionarMotores(float percetualMotorEsquerdo, float percetualMotorDireito);

	//As funções retornam o valor lido do sensor refletância
    const float lerSensorDeLinha(const int sensor, bool ledLigado=true); //recebe um pino analogico (A0, A1, A2 e etc) e retorna um valor de 0 a 100 
	
	inline const float lerSensorLinhaEsq(){			return lerSensorDeLinha(SENSOR_LINHA_ESQUERDO);}      //retorna um valor de 0 a 100 
	inline const float lerSensorLinhaMaisEsq(){	    return lerSensorDeLinha(SENSOR_LINHA_MAIS_ESQUERDO);} //retorna um valor de 0 a 100 
	inline const float lerSensorLinhaDir(){			return lerSensorDeLinha(SENSOR_LINHA_DIREITO);}       //retorna um valor de 0 a 100
	inline const float lerSensorLinhaMaisDir(){	    return lerSensorDeLinha(SENSOR_LINHA_MAIS_DIREITO);}  //retorna um valor de 0 a 100
	inline const float lerSensorLinhaCentral(){	    return lerSensorDeLinha(SENSOR_LINHA_CENTRAL);}       //retorna um valor de 0 a 100
	inline const float lerSensorLinhaFrontal(){	    return lerSensorDeLinha(SENSOR_LINHA_FRONTAL);}       //retorna um valor de 0 a 100

	const float lerDadosSensorDeLinha(const int sensor);

  	inline const float lerSensorLinhaEsqSemRuido(){			return lerDadosSensorDeLinha(SENSOR_LINHA_ESQUERDO);}      //retorna um valor de 0 a 100  
	inline const float lerSensorLinhaMaisEsqSemRuido(){     return lerDadosSensorDeLinha(SENSOR_LINHA_MAIS_ESQUERDO);} //retorna um valor de 0 a 100 
	inline const float lerSensorLinhaDirSemRuido(){			return lerDadosSensorDeLinha(SENSOR_LINHA_DIREITO);}       //retorna um valor de 0 a 100
	inline const float lerSensorLinhaMaisDirSemRuido(){	    return lerDadosSensorDeLinha(SENSOR_LINHA_MAIS_DIREITO);}  //retorna um valor de 0 a 100
	inline const float lerSensorLinhaCentralSemRuido(){	    return lerDadosSensorDeLinha(SENSOR_LINHA_CENTRAL);}       //retorna um valor de 0 a 100
	inline const float lerSensorLinhaFrontalSemRuido(){	    return lerDadosSensorDeLinha(SENSOR_LINHA_FRONTAL);}       //retorna um valor de 0 a 100

	//A função retorna o valor lido do sensor sonar
	float lerSensorSonarFrontal();

	// A função que retorna valor do sensor Laiser
	int lerSensorLaserFrontal()const;
  
	//funcoes para trabalhar com os sensores de Cor
	RGBC getRGBSensorDir() const;
    RGBC getRGBSensorEsq() const;

	void canal00() const;
	void canal01() const;
	void canal10() const;

	RGBC lerSensorDeCorDir();
	RGBC lerSensorDeCorEsq();

	RGBC lerSensorDeCorDirNormatizado();
	RGBC lerSensorDeCorEsqNormatizado();

  	//funcoes para o controle dos leds
	void ligarLed(const int led)const;
	void desligarLed(const int led)const;

    inline void ligarLedSmdVerde()    {ligarLed(LED_SMD_VERDE);}const;
    inline void ligarLedSmdVermelho() {ligarLed(LED_SMD_VERMELHO);}const;

	inline void desligarLedSmdVerde()    {desligarLed(LED_SMD_VERDE);}const;
    inline void desligarLedSmdVermelho() {desligarLed(LED_SMD_VERMELHO);}const;

    inline void ligarLedAmarelo()  {ligarLed(LED_AMARELO);}const;
	inline void ligarLedAzul()     {ligarLed(LED_AZUL);}const;
 	inline void ligarLedVermelho() {ligarLed(LED_VERMELHO);}const;
	inline void ligarLedVerde()    {ligarLed(LED_VERDE);}const;

	inline void desligarLedAmarelo()  {desligarLed(LED_AMARELO);}const;
	inline void desligarLedAzul()     {desligarLed(LED_AZUL);}const;
 	inline void desligarLedVermelho() {desligarLed(LED_VERMELHO);}const;
	inline void desligarLedVerde()    {desligarLed(LED_VERDE);}const;

	void ligarTodosLeds()const;
	void desligarTodosLeds()const;

	// --- funções de calibração e EEPROM ---
  void calibrarCoresConjunta();   
  void salvarCalibracao();        
  void carregarCalibracao();      
  String lerNomeCorEsq();         
  String lerNomeCorDir();         

private:
  	static int tipoSensorCor;

  	void tensao(float valor_por_cento,int pino);


	Ultrasonic sonarFrontal;

	Adafruit_TCS34725 tcsD;// = Adafruit_TCS34725softi2c(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X, SDA_SENSOR_COR_ESQUERDO, SCL_SENSOR_COR_ESQUERDO);
	Adafruit_TCS34725 tcsE;
    
	Servo servoBraco;
	Servo servoGarra;

	static VL53L0X sensor;// = Adafruit_VL53L0X();
	
	static CalibracaoCor calib;
	void lerMediaRGBdoSensor(bool esquerda, RGBC &out, uint8_t amostras = 10);
  	void normalizarRGBComCal(const RGBC &raw, const SensorCal &sc, int &rNorm, int &gNorm, int &bNorm);
  	String identificarCorPorRGB(int r, int g, int b);
};

static robo_hardware robo;

#endif
