/* 
 * File:   manage_interrupt.h
 * Author: ah427
 *
 * Created on 10 ??????, 2024, 02:39 ?
 */

#ifndef MANAGE_INTERRUPT_H
#define	MANAGE_INTERRUPT_H

/* SECTION: Include */
#include "interrupt_config.h"


/* SECTION: Interface Function Declarations */
void ISR_INT0(void);
void ISR_INT1(void);
void ISR_INT2(void);

void ISR_RB4(uint8 source);
void ISR_RB5(uint8 source);
void ISR_RB6(uint8 source);
void ISR_RB7(uint8 source);
#endif	/* MANAGE_INTERRUPT_H */

