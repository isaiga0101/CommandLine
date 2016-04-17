#include "../include/serial328.h"
#include <avr/io.h>
// Send a character
void serial328::tx(unsigned char value)		//Transmit Char
{
	while ((UCSR0A & (1<<UDRE0))==0);		// Wait for transmit ready
	UDR0 = value;
	return;
}

//---------------------------------------------------------------------------
// Receive a character
char serial328::rx()
{
	while ((UCSR0A & (1<<RXC0))==0);		//Wait for receive ready.
	char value = UDR0;
	return(value);
}
