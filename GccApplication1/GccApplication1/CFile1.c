/*
 * PIN_MODE.c
 *
 * Created: 06.11.2022 14:54:05
 *  Author: kajeepan
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "IncFile1.h"








char PIN_READ(char PORT_NO,int PIN_NO)

{
	switch(PORT_NO) {
		case 'A':
		if((DDRA &= (1<<PIN_NO)) == 0 && (PORTA &=(1<<PIN_NO )) !=0)
		{
			
			if( (PINA &= (1<<PIN_NO))!=0 )
			{
				DDRD=0xff;
				PORTD |= (1<<0);
				
				
				
			}
			
			if((PINA &= (1<<PIN_NO))==0 )
			{
				
				DDRD=0xff;
				PORTD |= (1<<1);
				
			}
			break;
		}
		
		
		
		
		case 'C':
		if( (DDRC &= (1<<PIN_NO)) ==0 &&  (PORTC &=(1<<PIN_NO ))!=0)
		{
			if( !(PINC &= (1<<PIN_NO)) )
			{
				DDRD=0xff;
				PORTD |= (1<<0);
				return 1;
				
				
			}
			
			else
			{
				
				return 0;
			}
			
			
		}
		
		break;
	}
}

int PIN_WRITE (char PORT_NO,int PIN_NO,char HIGHORLOW){
	switch(PORT_NO){
		
		case 'A' :
		if(DDRA &= (1<<PIN_NO)){
			
			if(HIGHORLOW==1){
				PORTA |= (1<<PIN_NO);
			}
			
			else if(HIGHORLOW==0){
				
				PORTA &=~ (1<<PIN_NO);
			}
			
			else{
				return 0;
				
			}
		}
		break;
		
		case 'C' :
		if(DDRC &= (1<<PIN_NO))
		{
			if(HIGHORLOW==1)
			{
				PORTC |= (1<<PIN_NO);
			}
			
			
			else if(HIGHORLOW==0)
			{
				
				PORTC &=~ (1<<PIN_NO);
			}
		}
		
		
		break;
		
		
	}

}

int PIN_SETTER (char PORT,int PIN_NO,char PIN_MODE){
	
	
	switch (PIN_MODE)
	{
		case 0 :        //Setting PORTA OR PORTB as input
		if(PORT == 'A'){
			
			DDRA  &=~ (1<<PIN_NO); // Setting PORTA PINMODE AS INPUT
			PORTA |= (1<<PIN_NO);
			PINA |= (1<<PIN_NO);
		}
		else if(PORT == 'C'){
			DDRC &=~ (1<<PIN_NO);  // Setting PORTB PINMODE AS INPUT
			PORTC |= (1<<PIN_NO);
			
		}
		else{
			return 0;
		}
		
		break;
		
		case 1 :
		if(PORT == 'A'){
			DDRA  |= (1<<PIN_NO);    // Setting PORTA PINMODE AS OUTPUT
			
			
		}
		else if(PORT == 'C') {
			DDRC |= (1<<PIN_NO);  // Setting PORTC PINMODE AS OUTPUT
			
		}
		else {
			return ERROR();
		}
		break;
	}
	
}

int ERROR()

{
	
	DDRD = 0xff;
	PORTD = 0xff;
	
	
}
