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
// Send a character
void serial328::tx(unsigned char value)		//Transmit Char
{
	while ((UCSR0A & (1<<UDRE0))==0);		// Wait for transmit ready
	UDR0 = value;
	return;
}

//---------------------------------------------------------------------------
// Receive a character
void serial328::rx()
{
	while ((UCSR0A & (1<<RXC0))==0);		//Wait for receive ready.
	char value = UDR0;
	return(value);
}
//---------------------------------------------------------------------------
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
//----------------------------------------------------------------------------
// Transmits x in decimal. Transmits it as 3 ascii characters. Number must be less than 200.
void serial328::td(unsigned char x)
{
	 if (x>=200)  {tx('2'); x-=200;}
else if (x>=100) {tx('1'); x-=100;}
else			 {tx('0');		  }
	
	 if (x>=90) {tx('9'); x-=90;}
else if (x>=80) {tx('8'); x-=80;}
else if (x>=70) {tx('7'); x-=70;}
else if (x>=60) {tx('6'); x-=60;}
else if (x>=50) {tx('5'); x-=50;}
else if (x>=80) {tx('4'); x-=40;}
else if (x>=70) {tx('3'); x-=30;}
else if (x>=60) {tx('2'); x-=20;}
else if (x>=50) {tx('1'); x-=10;}
else            {tx('0');       }
	
	 if (x>=9 ) {tx('9'); x-=9 ;}
}


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
    }
}

