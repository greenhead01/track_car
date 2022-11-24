#ifndef __dir_h__
#define __dir_h__
#include "sys.h"

#define	AIN1 PAout(7)		//×óÂÖPA3(time3_ch4)
#define	AIN2 PAout(5)
#define	BIN1 PBout(2)		//ÓÒÂÖPA1(time3_ch1)
#define	BIN2 PBout(10)

void AIN_Init();
void BIN_Init();
void tureleft();
void tureleft2();
void tureright();
void tureright2();
void stop();
void straight();
#endif