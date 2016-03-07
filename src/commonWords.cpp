/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31


void words_compare(char *str1, char *str2, char **result){

	int i, j, k;
	char temp[50];
	int count;
	int m = 0, n = 0;

	for (i = 0; str1[i] != '\0'; i++){
		k = 0;
		while (str1[i] != ' '&&str1[i] != '\0'){

			temp[k] = str1[i];
			k++;
			i++;
		}
		temp[k] = '\0';

		k = 0;
		j = 0;
		while (str2[j] != '\0'&&temp[k] != '\0'){

			if (str2[j] == temp[k]){
				count = 1;
				k++;

				if (temp[k] == '\0')
					break;
			}
			else{
				if (str2[j - 1] == temp[k - 1] && k != 0){
					k = 0;
				}
				count = 0;
			}
			j++;
		}

		if (count == 1 && temp[k] == '\0'){
			n = 0;
			for (k = 0; temp[k] != '\0'; k++){
				result[m][n] = temp[k];
				n++;
			}
			result[m][n] = '\0';
			m++;
		}
	}
}

char ** commonWords(char *str1, char *str2) {
	

	if (str1 == NULL || str2 == NULL)
		return NULL;

	int i;
	char **res = (char **)calloc(30,sizeof(char*));

	for (i = 0; i < 30; i++)
		res[i] = (char *)calloc(SIZE,sizeof(char));

	words_compare(str1, str2, res);

	if (res[0][0] == NULL)
		return NULL;
	else
		return res;
}