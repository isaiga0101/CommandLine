#include "serial328.h"

// Initialize USART to receive
void serial328::init_rx(unsigned char n_clock)
{
	UBRR0H = 0;
	UBRR0L = n_clock;		// Set baud rate to___. See Define List

	UCSR0A |= (1<<U2X0);	//1=double clock speed on
	UCSR0B |= (1<<RXEN0);	//Receive on

	//UCSR0C default will work here also
	//UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);		//8 bits, No parity, 2 stop bits
	return;
}
//----------------------------------------------------------------------------
// Initialize USART to transmit
void serial328::init_tx(unsigned char n_clock)
{
		UBRR0H = 0;
		UBRR0L = n_clock;		// Set baud rate to___. See Define List

		UCSR0A |= (1<<U2X0);	//1=double clock speed on
		UCSR0B |= (1<<TXEN0);	//Transmit on

		//UCSR0C default will work here also
		//UCSR0C |= (1<<UCSZ01) | (1<<UCSZ00);		//8 bits, No parity, 2 stop bits
		return;
}
