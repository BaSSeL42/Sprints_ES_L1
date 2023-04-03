/*
 * TIMER_Private.h
 *
 *  Created on: Apr 3, 2023
 *      Author: hp
 */

#ifndef MCAL_TIMER_TIMER_PRIVATE_H_
#define MCAL_TIMER_TIMER_PRIVATE_H_

/********************************* TIMER0 REGISTERS ******************************************/
#define TCCR0_REG 	(*(volatile Uint8_t*)(0x53))
#define TCNT0_REG 	(*(volatile Uint8_t*)(0x52))
#define OCR0_REG 	(*(volatile Uint8_t*)(0x5C))

/********************************* TIMER1 REGISTERS ******************************************/
#define TCCR1A_REG 	(*(volatile Uint8_t*)(0x4F))
#define TCCR1B_REG 	(*(volatile Uint8_t*)(0x4E))
#define TCNT1H_REG 	(*(volatile Uint8_t*)(0x4D))
#define TCNT1L_REG 	(*(volatile Uint8_t*)(0x4C))
#define TCNT1_REG 	(*(volatile Uint16_t*)(0x4C))
#define OCR1AH_REG 	(*(volatile Uint8_t*)(0x4B))
#define OCR1AL_REG 	(*(volatile Uint8_t*)(0x4A))
#define OCR1A_REG 	(*(volatile Uint16_t*)(0x4A))

#define OCR1BH_REG 	(*(volatile Uint8_t*)(0x49))
#define OCR1BL_REG 	(*(volatile Uint8_t*)(0x48))
#define ICR1H_REG 	(*(volatile Uint8_t*)(0x47))
#define ICR1L_REG 	(*(volatile Uint8_t*)(0x46))
#define ICR1_REG 	(*(volatile Uint16_t*)(0x46))

/********************************* TIMER2 REGISTERS ******************************************/
#define TCCR2_REG 	(*(volatile Uint8_t*)(0x45))
#define TCNT2_REG 	(*(volatile Uint8_t*)(0x44))
#define OCR2_REG 	(*(volatile Uint8_t*)(0x43))

/********************************* TIMER_ALL REGISTERS ******************************************/
#define TIFR_REG 	(*(volatile Uint8_t*)(0x58))
#define TIMSK_REG 	(*(volatile Uint8_t*)(0x59))

#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
