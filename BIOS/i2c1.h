/* 
 * File:   i2c1.h
 * Author: tushar.mali
 *
 * Created on 2 June, 2021, 12:59 PM
 */

#ifndef I2C1_H
#define	I2C1_H

#include "../projectdefines.h"

#define I2C_MASTER_ACK      0
#define I2C_MASTER_NOTACK   1

#ifdef	__cplusplus
extern "C" {
#endif

    void initializeI2C1();
    void I2C1_open();
    void I2C1_close();
    void I2C1_generateStart();
    void I2C1_generateStop(void);
    void I2C1_generateRepeatedStart(void);
    unsigned char I2C1_checkACKSlave(void);
    void I2C1_generateACK(unsigned char acknowledge);

    void I2C1_Write(unsigned char data);
    unsigned char I2C1_Read(void);



#ifdef	__cplusplus
}
#endif

#endif	/* I2C1_H */

