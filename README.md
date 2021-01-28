# HiFive-BareMetal-SPI
Bare metal SPI master for SiFi Hifi rev1 B board

To initliaze the spi use the function SPIinit(int baudspeed) with the speed to your desire.

To send date use the function SPISend(int data) the return value is also the recieved FIFO value.

To send a command and wait for the right data use the function SPISendAndReadValue(int data)
this will send a command to the slave wait for the slave to put the data in their FIFO. Than the master send an other packet to recieve the value from the slave in the FIFO
