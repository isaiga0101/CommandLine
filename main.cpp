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
int counter = 0;

void error(bool receive);
void menuMsg(bool receive);

class serial328 thello;


int main(void)
{
	thello.init_tx(BAUD9600);                       // Initialize transmit uart to 9600 baud rate
	while(counter <= 4)
	{
		thello.tx(hello[counter]);                    // Transmit hello
		counter ++;
	};
	thello.tx(cr);                                  // Transmit Carriage Return
	counter = 0;

	//Transmit the beginning message.
	while(counter <= 27)
	{
		thello.tx(prompt[counter]);
		counter ++;
	};

    while (1)
    {
        counter = 0;                                  // Reset count to 0
        thello.init_rx(BAUD9600);                   // Initialize receive for serial communication

        // Save input to variable
        while (counter <= max && endloop == false)
        {
            input[counter] = thello.rx();
            if (input[counter] == 13) endloop = true;
            counter ++;
        };

        // Was the command entered the menu command?
        counter = 0;                          // The letter that were comparing
        endloop = false;                    // When true the while loop ends
        // This loop checks every letter to see if it matches the menu string
        while (endloop == false)
        {
            if (input[counter] == menu[counter]){
                thello.init_tx(BAUD9600);
                cmRecog = true;
                endloop = false;
            }
            else {
                endloop = true;
                cmRecog = false;
            }

            // Check to see if we are done comparing strings
            if ((input[counter] == 0 || input[counter] == 13) && cmRecog == true){
                endloop = true;                                                         // End the loop with no error if each character was
                               menuMsg(true);                                                         // recognized and the string has ended.
            }
            else if((input[counter] == 0 || input[counter] == 13) && cmRecog == false)                              // Else if a character wasn't recognized than end
            {                                                                           // with error msg.
                error(true); endloop = true;
            }
            else counter ++;                                                              // If were not done comparing add 1 to count.
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

void menuMsg(bool recieve)
{
    char menu[5] = {"Menu"};
    char dash[8] = {" ----- "};

    class serial328 tmenu;
    tmenu.init_tx(BAUD9600);
    for (int x = 0; menu[x] == 0; x++){
        tmenu.tx(menu[x]);
    }

    for (int x = 0; dash[x] == 0; x++){
        tmenu.tx(dash[x]);
    }
    tmenu.tx(cr);

    if (recieve == false) return;
    else
    {
        tmenu.init_rx(BAUD9600);
        return;
    }
}
