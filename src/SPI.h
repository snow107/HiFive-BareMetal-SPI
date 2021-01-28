/*
 * SPI.h
 *
 *  Created on: 26 jan. 2021
 *      Author: Michiel
 */

#ifndef SPI_H_
#define SPI_H_

#define baseAdressGPIO 0x10012000

#define PinModeIOF 0x38
#define IOF_EN       *(int*)(baseAdressGPIO+PinModeIOF)

#define CPU_FREQ 16000000

#define SPI1_DQ0_MOSI 3
#define SPI1_DQ1_MISO 4
#define SPI1_SCK 5
#define SPI1_CS1 2

#define SPI1BaseAdress 0x10024000
#define SPI1fctrl *(int*) (SPI1BaseAdress+0x60)
#define SPI1fmt   *(int*) (SPI1BaseAdress+0x40)
#define SPI1csdef *(int*) (SPI1BaseAdress+0x14)
#define SPI1csmode *(int*)(SPI1BaseAdress+0x18)
#define SPI1csid  *(int*) (SPI1BaseAdress+0x10)
#define SPI1sckdiv *(int*) (SPI1BaseAdress+0x0)
#define SPI1txdata *(int*) (SPI1BaseAdress+0x48)
#define SPI1rxdata *(int*) (SPI1BaseAdress+0x4C)

#define rxmarkIP *(int*) (SPI1BaseAdress+0x74)




void SPIinit(int baudspeed);
int SPISendAndReadValue(int send);
int SPISend(int send);
void delay(int counter);
int spi_rxdata_read(void);





#endif /* SPI_H_ */
