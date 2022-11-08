/*
 * PIN_MODE.h
 *
 * Created: 06.11.2022 14:56:28
 *  Author: kajeepan
 */ 


#ifndef PIN_MODE_H_
#define PIN_MODE_H_
//#include "PINMODE.c"

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>#




#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

//enum PIN_NO                /* as in the first example */
//{ 
  //ten=10
//};
//typedef enum PIN_NO; 


char PIN_READ(char PORT_NO,int PIN_NO);
int PIN_WRITE (char PORT_NO,int PIN_NO,char HIGHORLOW);
int PIN_SETTER (char PORT,int PIN_NO,char PIN_MODE);
int ERROR();




#endif /* PIN_MODE_H_ */