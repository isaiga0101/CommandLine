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
	thello.init_tx(BAUD9600);
	while(count <= 4)
	{
		thello.tx(hello[count]);
		count ++;
	};
	thello.tx(cr);
	count = 0;
	while(count <= 27)
	{
		thello.tx(prompt[count]);
		count ++;
	};

    while (1)
    {
            count = 0;
            thello.init_rx(BAUD9600);
            while (count <= max && endloop == false)
            {
                input[count] = thello.rx();
                if (input[count] == 0) endloop = true;
                count ++;
            };

    };					// Never end program
}
