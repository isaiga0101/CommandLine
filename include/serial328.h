#ifndef SERIAL328_H
#define SERIAL328_H

#include <avr/io.h>

class serial328
{//Pin 3 (pd1) is TX. Pin 2 (pd0) is RX.
 // UBRR0 = n_clock = frequency/(8*Baud) -1 (Using double clock speed)
 private:
 public:
		#define BAUD9600 12
		#define BAUD4800 25
		#define BAUD2400 51
		#define BAUD1200 103
		#define BAUD0600 207

	void init_rx (unsigned char n_clock); //Init USART to receive
	void init_tx (unsigned char n_clock); // Init USART to transmit
	void tx (unsigned char value);		  // Transmit char
	char rx ();							  // Recieve char
	void td (unsigned char x);			  // Transmit char as a decimal
};

#endif // SERIAL328_H
