/*
 * Command Line.cpp
 *
 * Created: 3/3/2016 7:06:16 PM
 * Author : Gayfi_000
 */

#include <avr/io.h>
#include "serial328.h"

#include <avr/io.h>

#define	cr	13
#define max 5
char hello[6] = {"Hello"};
char prompt[29] = {"Type hello for me to respond"};
char input[max];
char menu[2] = {"m"};
char Cmenu[2] = {"M"};

bool endloop = false;
int count = 0;
class serial328 thello;

int main(void)
{
	thello.init_tx(BAUD9600);                       // Initialize transmit uart to 9600 baud rate
	while(count <= 4)
	{
		thello.tx(hello[count]);                    // Transmit hello
		count ++;
	};
	thello.tx(cr);                                  // Transmit Cariage Return
	count = 0;

	//Transmit the beginning message.
	while(count <= 27)
	{
		thello.tx(prompt[count]);
		count ++;
	};

    while (1)
    {
        count = 0;                                  // Reset count to 0
        thello.init_rx(BAUD9600);                   // Initialize receive for serial communication

        // Save input to variable
        while (count <= max && endloop == false)
        {
            input[count] = thello.rx();
            if (input[count] == 0) endloop = true;
            count ++;
        };

        // Figure out what command was entered
        count = 0;
        endloop = false;
        while (endloop = false)
        {
            if (input[count] = menu[count]) endloop = false;
            else endloop = true;

            if (input[count] = 0) endloop = true;
        };

    };					// Never end program
}
