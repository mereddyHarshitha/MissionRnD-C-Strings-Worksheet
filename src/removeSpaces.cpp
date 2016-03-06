/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

#include <stdio.h>

char removeSpaces(char *str) {
	
	int i = 0, j = 0;

	if (str == "")
		return '\0';
	else if (str == NULL)
		return '\0';
	else{

		while (str[i] != '\0'){

			if (str[i] == ' '){
				i++;
			}
			else{
				str[j] = str[i];
				j++;
				i++;
			}
		}
		str[j] = '\0';
	}

}