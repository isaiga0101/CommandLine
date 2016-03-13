/*
 * Command Line.cpp
 *
 * Created: 3/3/2016 7:06:16 PM
 * Author : Gayfi_000
 */

#include <avr/io.h>
#include "serial328.h"

#define	cr	13
char hello[6] = {"Hello"};
char prompt[29] = {"Type hello for me to respond"};

int count = 0;
class serial328 thello;
int main(void)
{
	thello.init_tx(BAUD9600);
	while(count <= 4)
	{
		thello.tx(hello[count]);
		count ++;
	}
	thello.tx(cr);
	count = 0;
	while(count <= 27)
	{
		thello.tx(prompt[count]);
		count ++;
	}

    while (1);					// Never end program
}

