/*
 * SPI.c
 *
 *  Created on: 26 jan. 2021
 *      Author: Michiel
 */

#include "SPI.h"

void delay(int counter)
{
    volatile int i = 0;
    while (i < counter) {
        i++;
    }
}
void SPIinit(int baudspeed)
{


	SPI1fctrl =0x0;
	SPI1fmt &= (0<<0)| (0<<1) | (0<<2) | (0<<3) | (8<<16);

	SPI1csdef=0xFFFFFFFF;
	SPI1csmode=0x0;
	rxmarkIP =0x02;
	SPI1sckdiv=(CPU_FREQ / (2 * baudspeed)) - 1;
	delay(3000000);

	IOF_EN |= (1<<SPI1_DQ0_MOSI) |(1<<SPI1_DQ1_MISO) |(1<<SPI1_SCK) | (1<<SPI1_CS1);

	delay(5000000);



}

int spi_rxdata_read(void)
{
    int c;

    while (1) {
        c = SPI1rxdata;
        if ((c &(1<<31)) == 0x0) {    // empty bit was not set, return the data
            return (int)c;
        }
    }
}
int SPISend(int data)
{
		int answer=0;

		while (SPI1txdata > 0xFF) {} //
		SPI1txdata = data;

		answer =spi_rxdata_read();
		return answer;
}

int SPISendAndReadValue(int data)
{
	int answer=0;
	SPISend(data);//which register do we want to read
	delay(10000);
	answer=SPISend(0xFA);
	return answer;// now we get the value of the register after slave put it in their register to send

}


