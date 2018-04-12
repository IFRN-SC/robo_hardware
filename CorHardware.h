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
  int calculeMaximo(int vermelho, int verde, int azul);     
  int calculeMinimo(int vermelho, int verde, int azul);

	protected:
  RGB rgb;

	public:
	virtual void atualizarRGB();
	
	inline int getVerde(){return rgb.verde;}
	inline int getVermelho(){return rgb.vermelho;}
	inline int getAzul(){return rgb.azul;}
		     
	RGB getRGB();
	HSV getHSV();


};

#endif
