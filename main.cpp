/*
 * Command Line.cpp
 *
 * Created: 3/3/2016 7:06:16 PM
 * Author : Gayfi_000
 */

#include <avr/io.h>
#include "include/serial328.h"

#define	cr	13
#define max 7

char hello[6] = {"Hello"};
char prompt[29] = {"Type hello for me to respond"};
char menuPr[13] = {"Menu ----- m"};
char input[max];
char menu[2] = {"m"};
char Cmenu[2] = {"M"};

bool endloop = false;
bool cmRecog = false;
int count = 0;
void error(bool receive);
class serial328 thello;


int main(void)
{
	thello.init_tx(BAUD9600);                       // Initialize transmit uart to 9600 baud rate
	while(count <= 4)
	{
		thello.tx(hello[count]);                    // Transmit hello
		count ++;
	};
	thello.tx(cr);                                  // Transmit Carriage Return
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
            if (input[count] == 13) endloop = true;
            count ++;
        };

        // Was the command Entered the menu command?
        count = 0;
        endloop = false;
        while (endloop == false)
        {
            if (input[count] == menu[count]){
                thello.init_tx(BAUD9600);
                cmRecog = true;
                endloop = false;
            }
            else {
                endloop = true;
                cmRecog = false;
            }

            if (input[count] == 0 && cmRecog == true) endloop = true;
            else if(input[count] == 0 && cmRecog == false)
            {
                error(true); endloop = true;
            }
        };

    };					// Never end program
}

void error(bool recieve)
{
    char error[6] = {"Error"};
    class serial328 terror;
    terror.init_tx(BAUD9600);

    for (int x = 0; error[x] == 0; x++){
    terror.tx(error[x]);
    }

    terror.tx(cr);

    if (recieve == false) return;
    else
    {
        terror.init_rx(BAUD9600);
        return;
    }
}
