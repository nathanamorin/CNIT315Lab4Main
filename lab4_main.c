#include "lab4_lib.h"
#include <stdio.h>
#include "console.h"

int wordCount_handler(char *array);

int wordRemove_handler(char *array);

int vowelCheck_handler(char *array);

int subString_handler(char *array);

int concatStrings_handler(char *array);

int printHandler(char *array);

int isAlpha_handler(char *array);

/**
 * Calls the functions implemented in lab4_lib.c and implements a menu system
 * for them.
 *
 * 	@return 	0 - Successful completion of the program.
 * 				1 - An error during execution.
 */
int main(){
	/* Initialize */
	
	//Get art
	FILE *file = fopen("ascii_art","r");

	if (file)
	{
	char c = fgetc(file);
	while(c != EOF)
	{
		printf("%c", c);
		c = fgetc(file);
	}
	fclose(file);

	}


	//Print art

	//Vars
	int numFunctions = 7, response, arrayElements = 0;
	
	// //Array users input
	// int *array = (int*)malloc(arrayElements*sizeof(int));
	char array[100];
	askQuestionString(array,"Please enter a string to start : ");
	
	//Define function pointer for handling each item that can be called
	typedef int (*item_handler)(char *array);
	
	//Define two parallel arrays, first with name of functions, second with
	//pointers to corresponding functions
	char *items[7] = {"Word Count","Word Remove","VowelCheck", 
		"SubString", "Concat Strings", "Print", "Is Alpha Numeric"};
	item_handler funcs[7] = {&wordCount_handler, &wordRemove_handler, 
		&vowelCheck_handler, &subString_handler, &concatStrings_handler, 
		&printHandler, &isAlpha_handler};

	
	//Iterate through menu.
	for(;;)
	{
		//Print Menu providing
		printMenu(items,numFunctions);
		askQuestionInt(&response, "Select Option");

		if (response == -1)
		{
			return 0;
		}
		else if (response >= 0 && response < numFunctions)
		{
			(item_handler)funcs[response](array);
		}

	}
}






int wordCount_handler(char *array)
{
	int numWords = 0;
	wordCount(array, &numWords);
	//printf("Number of Words %d\n", numWords);

	return 0;
}

int wordRemove_handler(char *array)
{
	char wordToRemove[1000];
	char sentence[1000];
	askQuestionString(sentence,"Enter a sentence");
	askQuestionString(wordToRemove,"Enter a word to remove");
	// printf("Enter Sentence : \n");
	// scanf("%[^\n]s", sentence);
	// printf("Enter Word : \n");
	// scanf("%[^\n]s", wordToRemove);
	//printf("Sentence - %s Word - %s\n", sentence,wordToRemove);
	wordRemove(sentence, wordToRemove);
	printf("Sentence after '%s' removed -- %s\n",wordToRemove, sentence);

	return 0;
}

int vowelCheck_handler(char *array)
{
	int vowels = 0;
	vowelCheck(array, &vowels);
	//printf("Number of vowels %d\n", vowels);

	return 0;
}

int subString_handler(char *array)
{

	int start = 0, end = 0;
	if (askQuestionInt(&start,"Input start of substring") == 1 || 
			askQuestionInt(&end,"Input end of substring") == 1)
	{
		return 1;
	}
	
	subString(array, start, end);
	printf("String has been modified -- new string -- %s\n", array);

	return 0;
}

int concatStrings_handler(char *array)
{

	char one[100], two[100];
	if (askQuestionString(one,"Input first of string") == 1 || 
		askQuestionString(two,"Input second of string") == 1)
	{
		return 1;
	}

	//printf("%s -- %s\n", one, two);
	concatenateStrings(one, two);
	printf("Concatenated Strings -- %s\n", one);

	return 0;
}

int printHandler(char *array)
{
	// printf("Print first 100 chars -- ");
	// printStringWLen(array, 100);

	printf("%s\n", array);
	return 0;
}

int isAlpha_handler(char *array)
{
	char c;
	printf("\nEnter a Char :: ");
	scanf(" %c", &c);
	int isAlphaNum = alphaNumeric(c);
	//printf("%c is %d (0 passed 1 did not pass)\n",c, isAlphaNum);
	return 0;
}




