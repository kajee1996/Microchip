/*
 * GccApplication19.c
 *
 * Created: 05.11.2022 14:08:48
 * Author : kajeepan
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define F_CPU 8000000UL
#include "PINMODE.h"


int main(void)
{
	
	//DDRA = 0x00; // used for the purpose of debugging when setting output
	DDRC = 0x00;
	
	DDRA = 0xff; // used for the purpose of debugging when setting INPUT
	//DDRC = 0xff;
	
	while (1)
	{
		
		PIN_SETTER('A',5,INPUT);
		//PIN_SETTER('A',0,INPUT);
		//PIN_SETTER('A',3,INPUT);
		//
		//PIN_SETTER('C',7,INPUT);
		//PIN_SETTER('C',0,OUTPUT);
		//PIN_SETTER('C',3,OUTPUT);
		
		PIN_WRITE('A',5,HIGH);
		//PORTA |= (1<<7);
		//PIN_WRITE('A',7,LOW);
	    PIN_READ('A',5);
		
	}

}

