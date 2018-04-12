#ifndef COR_HARDWARE_H
#define COR_HARDWARE_H

struct RGB{   // Struct com valores de verde, vermelho e azul.
  int verde;
  int vermelho;
  int azul;

};

struct HSV{ // Struct com valores do HSV.
  float h;
  double s;
  float v;
};


class CorHardware{
	private:
  RGB rgb;

	public:
	virtual void atualizarRGB();
	
	virtual int getVerde();
	virtual int getVermelho();
	virtual int getAzul();
		     
	virtual RGB getRGB();
	HSV getHSV();

	

};

#endif
