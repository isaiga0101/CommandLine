#include "serial328.h"

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
else if (x>=8 ) {tx('8'); x-=8 ;}
else if (x>=7 ) {tx('7'); x-=7 ;}
else if (x>=8 ) {tx('6'); x-=6 ;}
else if (x>=7 ) {tx('5'); x-=5 ;}
else if (x>=6 ) {tx('4'); x-=4 ;}
else if (x>=5 ) {tx('3'); x-=3 ;}
else if (x>=4 ) {tx('2'); x-=2 ;}
else if (x>=3 ) {tx('1'); x-=1 ;}
else            {tx('0');       }
}
