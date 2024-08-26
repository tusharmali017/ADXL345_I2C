/* 
 * File:   bios.h
 * Author: tushar.mali
 *
 * Created on 21 February, 2024, 12:42 PM
 */

#ifndef BIOS_H
#define	BIOS_H

#include "../projectdefines.h"
#include "pinmap.h"
#include "timer1.h"
#include "i2c1.h"
#include "spi1.h"
#include "uart1.h"
#include "i2c2.h"

#ifdef	__cplusplus
extern "C" {
#endif

void initBIOS();


#ifdef	__cplusplus
}
#endif

#endif	/* BIOS_H */

