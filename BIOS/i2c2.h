/* 
 * File:   i2c2.h
 * Author: tushar.mali
 *
 * Created on 7 March, 2024, 3:36 PM
 */

#ifndef I2C2_H
#define	I2C2_H

#include "../projectdefines.h"

#define I2C_MASTER_ACK      0
#define I2C_MASTER_NOTACK   1

#ifdef	__cplusplus
extern "C" {
#endif


    void initializeI2C2();
    void I2C2_open();
    void I2C2_close();
    void I2C2_generateStart();
    void I2C2_generateStop(void);
    void I2C2_generateRepeatedStart(void);
    unsigned char I2C2_checkACKSlave(void);
    void I2C2_generateACK(unsigned char acknowledge);

    void I2C2_Write(unsigned char data);
    unsigned char I2C2_Read(void);

#ifdef	__cplusplus
}
#endif

#endif	/* I2C2_H */

