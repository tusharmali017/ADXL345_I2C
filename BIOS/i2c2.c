#include "i2c1.h"

// Private Functions
static void I2C2_EnableReceive();
static bool isI2C2Busy(void);

void initializeI2C2()
{

    I2C2CONL = 0;
    I2C2CONLbits.DISSLW = 1;
    I2C2CONH = 0;
    
    I2C2BRG = 18; // 100KHz Baud for 4MHz Fcy

    _MI2C2IF = 0;
}

void I2C2_open()
{
    I2C2CONLbits.I2CEN = 1;
    _MI2C2IF = 0;
}

void I2C2_close()
{
    I2C2CONLbits.I2CEN = 0;
    _MI2C2IF = 0;
}

void I2C2_generateStart()
{
    while (isI2C2Busy());
    I2C2CONLbits.SEN = 1;
    while (_MI2C2IF == 0);
    _MI2C2IF = 0;
}

void I2C2_generateStop(void)
{
    while (isI2C2Busy());
    I2C2CONLbits.PEN = 1;
    while (_MI2C2IF == 0);
    _MI2C2IF = 0;
}

void I2C2_generateRepeatedStart(void)
{
    while (isI2C2Busy());
    I2C2CONLbits.RSEN = 1;
    while (_MI2C2IF == 0);
    _MI2C2IF = 0;
}

unsigned char I2C2_checkACKSlave(void)
{
    while (isI2C2Busy());
    return I2C2STATbits.ACKSTAT;
}

void I2C2_generateACK(unsigned char acknowledge)
{
    while (isI2C2Busy());
    I2C2CONLbits.ACKDT = acknowledge;
    I2C2CONLbits.ACKEN = 1;
    while (_MI2C2IF == 0);
    _MI2C2IF = 0;
}

static void I2C2_EnableReceive()
{
    while (isI2C2Busy());
    I2C2CONLbits.RCEN = 1;
    while (_MI2C2IF == 0);
    _MI2C2IF = 0;
}

static bool isI2C2Busy(void)
{
    return (bool) (I2C2CONL & 0x1F & I2C2STATbits.TRSTAT);
}

void I2C2_Write(unsigned char data)
{
    I2C2TRN = data;
    while (_MI2C2IF == 0);
    _MI2C2IF = 0;
}

unsigned char I2C2_Read(void)
{
    I2C2_EnableReceive();
    return I2C2RCV;
}


