/* 
 * File:   uart1.h
 * Author: tushar.mali
 *
 * Created on 2 February, 2023, 4:34 PM
 */

#ifndef UART1_H
#define	UART1_H

#include "../projectdefines.h"
#include "pinmap.h"

#ifdef	__cplusplus
extern "C" {
#endif

    void initUART1(void);
    void UART1WriteByte(const uint8_t data);
    void UART1WriteData(const uint8_t *data, uint16_t iLength);
    void UART1WriteString(const char* data);




#ifdef	__cplusplus
}
#endif

#endif	/* UART1_H */

