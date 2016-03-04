/*
 * Command Line.cpp
 *
 * Created: 3/3/2016 7:06:16 PM
 * Author : Gayfi_000
 */ 

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
//--------------------------------------------------------------------------
// Send a char
void serial328::rx(unsigned char value)		//Transmit Char
{
	while ((UCSR0A & (1<<UDRE0))==0);		// Wait for transmit ready
	UDR0 = value;
	return;
}

//---------------------------------------------------------------------------

int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

