/*
 * Project_Name    :   ISR_Example
 * File_Name       :   main.c
 * Author          :   Mohamed Akram JABALLAH
 * Target          :   Atmega324p
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


ISR(PCINT3_vect);

void Init_PCINT (void);

int main (void) {

	DDRB = 0xFF;
	DDRD = 0x00;
	PORTD |= (1 << 7);

	Init_PCINT();

	for (;;) {

		PORTB = 0x80;
		_delay_ms (100);
		PORTB = 0x00;
		_delay_ms (100);
	}

	return 0;
}


ISR (PCINT3_vect) {

	while (PIND & 0x80) {

		PORTB = 0x03;
		_delay_ms (250);
		PORTB = 0x00;
		_delay_ms (250);
	}
}


void Init_PCINT (void) {

	PCMSK3 |= (1 << 7);
	PCICR  |= (1 << PCIE3);
	sei ();
}


