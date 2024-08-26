/* 
 * File:   spi1.h
 * Author: tushar.mali
 *
 * Created on 24 February, 2023, 1:51 PM
 */

#ifndef SPI1_H
#define	SPI1_H

#include "../BIOS/bios.h"

#define DUMMY 0x0

#ifdef	__cplusplus
extern "C" {
#endif

    void init_SPI();
    uint8_t SPI1_Write(uint8_t data);

    



#ifdef	__cplusplus
}
#endif

#endif	/* SPI1_H */

