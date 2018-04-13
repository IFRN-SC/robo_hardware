#ifndef COR_TCS23_H
#define COR_TCS23_H

#include <Arduino.h>
#include "CorHardware.h"

class CorTcs23 : public CorHardware{
	public:
		CorTcs23(int s2_dado, int s3_dado, int out_dado);

	private:
		void atualizarRGB();
		int s2 = 0;
  		int s3 = 0; 
  		int out = 0;
};

#endif