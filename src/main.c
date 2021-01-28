/* Copyright 2019 SiFive, Inc */
/* SPDX-License-Identifier: Apache-2.0 */

#define baseAdress 0x10012000
#define outPutVal 0x0C
#define PinModeOut 0x08
#define PinModeIn  0x04

#define OutputPin *(int*)(baseAdress+outPutVal)
#define InValue *(int*)(baseAdress)
#define PinModeOutput *(int*)(baseAdress+PinModeOut)
#define PinModeInput *(int*)(baseAdress+PinModeIn)



#include "SPI.h"
#include <stdio.h>

void setOutputPin(int welke)
{
	OutputPin |=(1<<welke);
}

void getRGBvalues(int *r,int *g, int*b)
{

	*r=SPISendAndReadValue(0xAA);
	delay(100000);


	*g=SPISendAndReadValue(0x0A);
	delay(100000);


	*b=SPISendAndReadValue(0xA0);
	delay(100000);
}




int main() {

	int r=0,g=0,b=0;


	SPIinit(9600);


	while(1)
	{
		getRGBvalues(&r, &g, &b);
		printf("%i,%i,%i,\n",r,g,b);
		delay(5000000);

	}



	return 0;
}


