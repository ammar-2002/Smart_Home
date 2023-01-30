/*
 * REG.h
 *
 * Created: 8/29/2021 12:50:48 PM
 *  Author: dell
 */ 


#ifndef REG_H_
#define REG_H_

#include "APP/LIB/STD_TYPES.h"

/*************** DIO_REGISTERS *************/

#define PORTA      (*((volatile u8*)0x3B))
#define DDRA       (*((volatile u8*)0x3A))
#define PINA       (*((volatile u8*)0x39))

#define PORTB      (*((volatile u8*)0x38))
#define DDRB       (*((volatile u8*)0x37))
#define PINB       (*((volatile u8*)0x36))

#define PORTC      (*((volatile u8*)0x35))
#define DDRC       (*((volatile u8*)0x34))
#define PINC       (*((volatile u8*)0x33))

#define PORTD      (*((volatile u8*)0x32))
#define DDRD       (*((volatile u8*)0x31))
#define PIND       (*((volatile u8*)0x30))

/*************** _EXT_INT_REG_ *************/

#define SREG       (*((volatile u8*)0x5F))
#define MCUCR      (*((volatile u8*)0x55))
#define GICR       (*((volatile u8*)0x5B))

/*************** _ADC_REG_ *************/

#define ADMUX       (*((volatile u8*)0x27))
#define ADCSRA      (*((volatile u8*)0x26))
#define ADCL        (*((volatile u16*)0x24))

/*************** _TIMER_0_REG_ *************/

#define TCNT0        (*((volatile u8*)0x52))
#define TIMSK        (*((volatile u8*)0x59))
#define TCCR0        (*((volatile u8*)0x53))
#define OCR0         (*((volatile u8*)0x5C))

/*************** _TIMER_1_REG_ *************/

#define TCCR1A        (*((volatile u8*)0x4F))
#define TCCR1B        (*((volatile u8*)0x4E))
#define OCR1A         (*((volatile u16*)0x4A))
#define OCR1B         (*((volatile u16*)0x48))
#define ICR1          (*((volatile u16*)0x46))

/*************** _WATCH_DOG_TIMER_REG_ *************/

#define WDTCR         (*((volatile u8*)0x41))

/*************** _UART_REG_ *************/

#define UDR           (*((volatile u8*)0x2C))
#define UCSRA         (*((volatile u8*)0x2B))
#define UCSRB         (*((volatile u8*)0x2A))
#define UCSRC         (*((volatile u8*)0x40))
#define UBRRL         (*((volatile u8*)0x29))

/*************** _SPI_REG_ *************/

#define SPDR           (*((volatile u8*)0x2F))
#define SPCR           (*((volatile u8*)0x2D))
#define SPSR           (*((volatile u8*)0x2E))

/*************** _I2C_REG_ *************/

#define TWAR           (*((volatile u8*)0x22))
#define TWBR           (*((volatile u8*)0x20))
#define TWCR           (*((volatile u8*)0x56))
#define TWDR           (*((volatile u8*)0x23))
#define TWSR           (*((volatile u8*)0x21))

/*************** _TIMER_2_REG_ *************/

#define TCCR2          (*((volatile u8*)0x45))
#define OCR2          (*((volatile u8*)0x43))

#endif /* REG_H_ */