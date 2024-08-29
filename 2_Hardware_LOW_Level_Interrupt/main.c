/*
 * Project_Name    :   Hardware_LOW_Level_Interrupt
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


unsigned int n = 0;
unsigned char BCD_Conversion (unsigned char x);

ISR (INT0_vect) {
	n++;
}


int main (void) {

	EIMSK = (1 << INT0);
	sei ();
	DDRA = 0xFF;
	DDRD = 0x00;
	PORTD = 0xFF;

	for (;;) {
		
		PORTA = BCD_Conversion (n);

		if (n > 20) {
			n = 0;
		}
	}

	return 0;
}


unsigned char BCD_Conversion (unsigned char x) {

	unsigned char lsd, msd,res;
	lsd = x % 10;
	msd = x / 10;
	res = (msd << 4)| lsd;
	return res;
}





