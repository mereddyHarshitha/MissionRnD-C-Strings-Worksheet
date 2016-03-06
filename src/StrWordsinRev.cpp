/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	
	int i, k = 0, j, temp;
	for (i = 0, j = 0; j<len; j++){

		if ((input[j] == ' ') || (j == len - 1)){
			if (j<len - 1)
				k = j - 1;
			else
				k = j;

			while (i<k){
				temp = input[i];
				input[i] = input[k];
				input[k] = temp;
				i++;
				k--;
			}
			i = j + 1;
		}
	}

	for (i = 0, j = 0; j<len; j++){

		if (j == len - 1){
			k = j;

			while (i<k){
				temp = input[i];
				input[i] = input[k];
				input[k] = temp;
				i++;
				k--;
			}
			i = j + 1;
		}
	}
}
