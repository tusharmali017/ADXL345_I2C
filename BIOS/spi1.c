#include "spi1.h"

/*
 * This is a SPI initialization function where we are doing following steps-
 * 1. clearing the interrupt bits
 * 2. reseting the SPI1CON1L SPI1CON1H registers where internal clock enabled, 
 * SDO1 pin is controlled by module, 8 bit communication selected, 
 * SMP=0 i/p data is sampled at the middle of data o/p time.  
 * 3. setting BRGL register for 9600 baud rate
 * 4. clearing SPIROV receive overflow flag bit.
 * 5. SPI mode0 selected where SKE=1 and SKP= 0.
 * 6. SPI Master mode enabled using MSTEN bit
 * 7. SPI module enabled using SPIEN bit
 */

void init_SPI() {
    SPI1CON1L = 0;
    SPI1BUFL = 0;
    SPI1BUFH = 0;
    
    SPI1CON1Lbits.SPIEN = 0;

    SPI1BRGL = 3;           //500KHz SPI frequency for 4MHz Fcy 
    SPI1STATLbits.SPIROV = 0;

    //SPI in Master Mode
    SPI1CON1Lbits.MSTEN = 1;
    
    //SPI MODE 
    SPI1CON1Lbits.CKP = 1;
    SPI1CON1Lbits.CKE = 0;
    
    //Enable SPI Module
    SPI1CON1Lbits.SPIEN = 1;
}

/**
 * SPI1 write function where data is transmitted into SPI transmit buffer and
 * SPITBF is set when data is completely written into transmit buffer.
 */
uint8_t SPI1_Write(uint8_t data)
{
    while (SPI1STATLbits.SPITBF);
    SPI1BUFL = data;
    
    while (!SPI1STATLbits.SPIRBF);
    return SPI1BUFL;
}