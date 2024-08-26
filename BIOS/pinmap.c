#include <p24FJ1024GB610.h>

#include "pinmap.h"

static void setPeripheralMap(void);

void initPinmap(void)
{
    LATA = 0x0000;
    LATB = 0x0000;
    LATC = 0x0000;
    LATD = 0x0000;
    LATE = 0x0000;
    LATF = 0x0000;
    LATG = 0x0000;

    TRISA = 0xFFFF;
    TRISB = 0xFFFF;
    TRISC = 0xFFFF;
    TRISD = 0xFFFF;
    TRISE = 0xFFFF;
    TRISF = 0xFFFF;
    TRISG = 0xFFFF;

    ANSELA = 0x0000;
    ANSELB = 0x0000;
    ANSELC = 0x0000;
    ANSELD = 0x0000;
    ANSELE = 0x0000;
    ANSELF = 0x0000;
    ANSELG = 0x0000;

    setPeripheralMap();
}

/**
 * Tx and Rx pins of UART2 are configured here as RP17 and RP10 pins.
 * Tx and Rx pins of UART2 are configured here as RP16 and RP30 pins.
 */
static void setPeripheralMap(void)
{
    __builtin_write_OSCCONL(OSCCON & 0xbf);
    
    // Assign U1RX To Pin RP10
    RPINR18bits.U1RXR = 10;
    // Assign U1TX To Pin RP17
    RPOR8bits.RP17R = 3;

    RPINR20bits.SDI1R = 26; // Assign SPI1 MISO to RP26
    _RP19R = _RPOUT_SDO1; //Assign SPI1 MOSI To Pin RP19
    _RP21R = _RPOUT_SCK1OUT; //Assign SPI1 Clock To Pin RP21
  
    __builtin_write_OSCCONL(OSCCON | 0x40);
}

