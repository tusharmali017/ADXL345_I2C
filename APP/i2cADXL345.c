#include "i2cADXL345.h"


// Function for initializing ADXL345 accelerometer in measure mode
void ADXL345_Init()
{
//    ADXL345_WriteData(ADXL345_REG_DATA_FORMAT, 0x00);
    ADXL345_WriteData(ADXL345_REG_POWER_CTL, 0x08);
}

void ADXL345_WriteData(uint8_t regAddress, uint8_t data)
{
    // Configure ADXL345: Enable Measurement Mode
    I2C1_generateStart();

    I2C1_Write(ADXL345_ADDRESS << 1); // Write address     0011 1010 << 1 = 0x3A
    // Check Acknowledge from ADXL345
    if (I2C1_checkACKSlave() != I2C_MASTER_ACK)   if(true)
    {
        return;
    }

    I2C1_Write(regAddress); 
    // Check Acknowledge from ADXL345
    if (I2C1_checkACKSlave() != I2C_MASTER_ACK)
    {
        return;
    }

    I2C1_Write(data); 
    // Check Acknowledge from ADXL345
    if (I2C1_checkACKSlave() != I2C_MASTER_ACK)
    {
        return;
    }

    I2C1_generateStop();
}


// Function for reading ADXL345 accelerometer data
uint8_t ADXL345_ReadData(uint8_t regAddress)
{
    uint8_t accValue = 0;
    
    I2C1_generateStart();

    I2C1_Write(ADXL345_ADDRESS << 1); // Write address
    // Check Acknowledge from ADXL345
    if (I2C1_checkACKSlave() != I2C_MASTER_ACK)
    {
        return;
    }

    I2C1_Write(regAddress); 
    // Check Acknowledge from ADXL345
    if (I2C1_checkACKSlave() != I2C_MASTER_ACK)
    {
        return;
    }

    I2C1_generateRepeatedStart();          

    I2C1_Write((ADXL345_ADDRESS << 1) | 0x01); // Read address
    // Check Acknowledge from ADXL345
    if (I2C1_checkACKSlave() != I2C_MASTER_ACK)
    {
        return;
    }
    
    //Read value which is received in I2CRCV register
    accValue = I2C1_Read();
    return accValue;

    // Generate Not Acknowledge after reading Z-Axis Data (last byte)
    I2C1_generateACK(I2C_MASTER_NOTACK);

    I2C1_generateStop();
}
