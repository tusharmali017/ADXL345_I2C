/* 
 * File:   pinmap.h
 * Author: tushar.mali
 *
 * Created on 21 February, 2024, 12:42 PM
 */

#ifndef PINMAP_H
#define	PINMAP_H

#include "../projectdefines.h"

//MACROS DEFINITIONS
#define DO_ADXL345_CS LATGbits.LATG9

#ifdef	__cplusplus
extern "C" {
#endif

void initPinmap();


#ifdef	__cplusplus
}
#endif

#endif	/* PINMAP_H */

