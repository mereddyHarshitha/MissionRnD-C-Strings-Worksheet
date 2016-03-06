/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include <math.h>

void reverse(char *str, int len){

	int i, j, temp;
	for (i = 0, j = len - 1; i < j; i++, j--){

		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}


int toString(int number, char str[]){

	int i = 0;
	while (number){

		str[i++] = (number % 10) + '0';
		number = number / 10;
	}
	reverse(str, i);
	str[i] = '\0';
	return i;
}

void number_to_str(float number, char *str,int afterdecimal){

	int integer, i;
	float fraction;

	if (number >= 0){

		integer = (int)number;
		i = toString(integer, str);

		fraction = number - (float)integer;

		if (afterdecimal != 0){

			str[i] = '.';
			fraction = fraction * pow((double)10, afterdecimal);
			toString(fraction, str + i + 1);
		}

	}
	else{

		str[0] = '-';

		integer = -((int)number);
		i = toString(integer, str + 1);

		fraction = -(number + integer);

		if (afterdecimal != 0)
		{
			str[i + 1] = '.';
			fraction = fraction * pow((double)10, afterdecimal);
			toString(fraction, str + i + 2);
		}
	}
	
}
