#include "bios.h"


void initBIOS()
{
    initPinmap();
    initTimer1();
    initUART1();
    init_SPI();
    initializeI2C1();
    initializeI2C2();
}
