/* 
 * File:   i2caccelerometer.h
 * Author: tushar.mali
 *
 * Created on 5 March, 2024, 10:38 AM
 */

#ifndef I2CACCELEROMETER_H
#define	I2CACCELEROMETER_H

#include "../BIOS/bios.h"


// ADXL345 I2C Address when SDO is High
//#define ADXL345_ADDRESS       0x1D

// ADXL345 I2C Address when SDO is Low
#define ADXL345_ADDRESS         0x53


// ADXL345 Register Addresses
#define ADXL345_REG_POWER_CTL   0x2D
#define ADXL345_REG_DATA_FORMAT 0x31
#define ADXL345_REG_DATAX0      0x32
#define ADXL345_REG_DATAX1      0x33
#define ADXL345_REG_DATAY0      0x34
#define ADXL345_REG_DATAY1      0x35
#define ADXL345_REG_DATAZ0      0x36
#define ADXL345_REG_DATAZ1      0x37


#ifdef	__cplusplus
extern "C" {
#endif

    // Function Prototypes
    void ADXL345_Init();
    uint8_t ADXL345_ReadData(uint8_t regAddress);    

#ifdef	__cplusplus
}
#endif

#endif	/* I2CACCELEROMETER_H */

