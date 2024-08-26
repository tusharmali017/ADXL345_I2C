#include "i2c1.h"


// Private Functions
static void I2C1_EnableReceive();
static bool isI2C1Busy(void);


void initializeI2C1()
{
    I2C1CONH = 0;
    I2C1STAT = 0;
    I2C1CONL = 0;
    I2C1CONLbits.DISSLW = 1;
    
    I2C1BRG = 18; // 100KHz Baud for 4MHz Fcy

    _MI2C1IF = 0;
}

//Enabling I2C module
void I2C1_open()
{
    I2C1CONLbits.I2CEN = 1;
    _MI2C1IF = 0;
}

//Disabling I2C module
void I2C1_close()
{
    I2C1CONLbits.I2CEN = 0;
    _MI2C1IF = 0;
}


void I2C1_generateStart()
{
    while (isI2C1Busy());
    I2C1CONLbits.SEN = 1;
    while (_MI2C1IF == 0);
    _MI2C1IF = 0;
}


void I2C1_generateStop(void)
{
    while (isI2C1Busy());
    I2C1CONLbits.PEN = 1;
    while (_MI2C1IF == 0);
    _MI2C1IF = 0;
}


void I2C1_generateRepeatedStart(void)
{
    while (isI2C1Busy());
    I2C1CONLbits.RSEN = 1;
    while (_MI2C1IF == 0);
    _MI2C1IF = 0;
}


unsigned char I2C1_checkACKSlave(void)
{
    while (isI2C1Busy());
    return I2C1STATbits.ACKSTAT;
}


void I2C1_generateACK(unsigned char acknowledge)
{
    while (isI2C1Busy());
    I2C1CONLbits.ACKDT = acknowledge;
    I2C1CONLbits.ACKEN = 1;
    while (_MI2C1IF == 0);
    _MI2C1IF = 0;
}


static void I2C1_EnableReceive()
{
    while (isI2C1Busy());
    I2C1CONLbits.RCEN = 1;
    while (_MI2C1IF == 0);
    _MI2C1IF = 0;
}


static bool isI2C1Busy(void)
{
    return (bool) (I2C1CONL & 0x1F & I2C1STATbits.TRSTAT);
}


void I2C1_Write(unsigned char data)
{
    I2C1TRN = data;
    while (_MI2C1IF == 0);
    _MI2C1IF = 0;
}


unsigned char I2C1_Read(void)
{
    I2C1_EnableReceive();
    return I2C1RCV;
}


