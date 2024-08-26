#include "uart1.h"

/**
 * Baud rate register loaded with the value calculated for 9600 baud rate.
 */
void initUART1(void)
{
    U1MODE = 0;
    U1BRG = 25; // 9600 baud at 8Mhz Fosc

    U1STA = 0;

    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
    U1STAbits.URXEN = 1;
}

void UART1WriteByte(const uint8_t data)
{
    while (U1STAbits.UTXBF); //wait until the transmit buffer is full
    U1TXREG = data; //load data to buffer register
}

void UART1WriteString(const char* data)
{
    while (*data != '\0')
    {
        UART1WriteByte(*data);
        data++;
    }
}

void UART1WriteData(const uint8_t *data, uint16_t iLength)
{
    while (iLength--)
    {
        UART1WriteByte(*data);
        data++;
    }
}
