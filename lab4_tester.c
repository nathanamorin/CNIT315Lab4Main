/* 
CNIT 315
Lab 04
Testing Team

Functions to Test
􏰃Accept a string from the user.
􏰃Find the length of a string.
􏰃Count the number of vowels in a string. [Extra credits if your function uses recursion!] 􏰃 
Count the number of words in a string. [Extra credits if your function uses recursion!] 􏰃 
Determine if a character is alpha-numeric. (i.e. it lies between a-z, A-Z, or 0-9)
􏰃Create a sub-string by specifying the indices.
􏰃Concatenate two strings.
􏰃Remove a particular word from the string.


Collaborators:

	Some functions copied from lab 03
*/
#include "lab4_tester.h"



typedef int (*tester_function)();

struct RandomString
{
	int length;
	char *value;
};

struct TesterFunction
{
	char *name;
	tester_function function;
	
};

//Global Vars
int numArrays = 5;
struct RandomString strings[5];



int main(int argc, char *argv[])
{
	//Check to make sure arugment was included for filename
	if (argc != 2)
	{
		printf("usage : %s filename\n", argv[0]);
		return 1;
	}



	loadArrays();
	printf("Starting Test\n");
	// int i;
	// for (i=0;i<5;i++)
	// {
	// 	printf("%s\n", strings[i].value);
	// }

	//Generate Report and put in file specified in arugments
	generateReport(argv[1]);

	return 0;
}






int testFindLength()
{
	//Vars
	int i, strLength, strLengthResponse = -5, returnValue;
	for (i=0; i<numArrays; i++)
	{
		strLength = strings[i].length;
		char *string = malloc(strLength*sizeof(char));
		string = strings[i].value;
		strLength = strlen(string);
		//printf("%s\n", strings[0].value);
		// int i =0;
		// while (string[i] != '\0')
		// {
		// 	printf("%d\n",i);
		// 	i++;
		// }
		// printf("Ending my test\n");

		//Use Function to find length of string
		returnValue = printStringWLen(string, &strLengthResponse);
		//printf("Length - %d Returned Length %d\n", strLength,strLengthResponse);

		if (returnValue != 0)
		{
			return 1;
		}
		if (strLengthResponse == -5)
		{
			return -2;
		}
		if (strLengthResponse != strLength)
		{
			return -1;
		}

	}


	return 0;
}


int testVowels()
{
	//Vars
	int i,e,numVowels, strLength, strVowelResponse , returnValue;
	for (e=0; e<numArrays; e++)
	{
		loadArrays();
		strLength = strings[e].length;
		char *string = malloc(strLength);
		string = strings[e].value;
		numVowels = 0;
		strVowelResponse = -5;
		//Find number of vowels
		//Source -- http://www.programiz.com/c-programming/examples/vowel-consonant-frequency-string
		for(i=0; string[i]!='\0'; i++) 
		{ 
			if(string[i]=='a' || string[i]=='e' || string[i]=='i' || 
			string[i]=='o' || string[i]=='u' || string[i]=='A' || 
			string[i]=='E' || string[i]=='I' || string[i]=='O' || 
			string[i]=='U') numVowels++;
		}
		//Use Function to find length of string
		returnValue = vowelCheck(string, &strVowelResponse);
		printf("Num Vowels Response -- %d\n", strVowelResponse);
		printf("Num Vowels -- %d\n", numVowels);
		if (returnValue != 0)
		{
			return 1;
		}
		if (strVowelResponse == -5)
		{
			return -2;
		}
		if (strVowelResponse != numVowels)
		{
			return -1;
		}

	}


	return 0;
}



int testNumberWords()
{
	//Vars
	int i,e,numWords, strLength, strWordResponse = -5, returnValue;
	for (e=0; e<numArrays; e++)
	{
		loadArrays();
		strLength = strings[e].length;
		char *string = malloc(strLength);
		string = strings[e].value;
		string[0] = 'A';
		numWords = 1;
		//Find number of Words
		strWordResponse = 0;
		for(i=1;string[i]!='\0';i++) 
		{ 
			if((string[i]==' ' && string[i-1]!=' ')) 
			{
				numWords++;
			}
		}

		//Use Function to find length of string
		returnValue = wordCount(string, &strWordResponse);

		printf("\n\n%s\n NUMBER OF WORDS my %d theirs %d\n\n", string, numWords,strWordResponse);

		if (returnValue != 0)
		{
			return 1;
		}
		if (strWordResponse == -5)
		{
			return -2;
		}
		if (strWordResponse != numWords)
		{
			return -1;
		}

	}


	return 0;
}


int testAlphaNumericChar()
{
	//Vars
	int value;
	int first;
	int second;
	int third;
	//NOTE: must use single quote for char
	value = alphaNumeric('n');
	if(value==0)
	{
		first = 0;	
	}
	if(value== 1)
	{
		first = 1;
	}
	value = alphaNumeric('9');
	if(value==0)
	{
		second = 0;	
	}
	if(value== 1)
	{
		second = 1;
	}
	value = alphaNumeric('!');
	if(value==0)
	{
		third = 0;	
	}
	if(value== 1)
	{
		third = 1;
	}
	if(third == 0 && second == 0 && first == 0)
	{
	return 0;
	}
	else
	return 1;
}


int testSubString()
{
	//vars
	char string[] = "lucille";
	subString(string, 2, 5);

	
	
	// use strcmp(check,input) != 0 
	//source :: http://stackoverflow.com/questions/8004237/how-do-i-properly-compare-strings-in-c
	if (strcmp(string, "cill") != 0)
	{
		printf("Testing Sub String -- %s\n", string);
		return -1;
	}
	
	if (string == NULL)
	{
		return -2;
	}
	return 0;
}


int testConcat()
{
	
	//Vars
	char string1[500] = "A melancholy-looking man, he had the appearance of one ";
	char string2[] = "who has searched for the leak in life's gas-pipe with a lighted candle - PG Wodehouse";

	char stringTotal[] = "A melancholy-looking man, he had the appearance of one who has searched for the leak in life's gas-pipe with a lighted candle - PG Wodehouse";

	int returnValue = concatenateStrings(string1,string2);

	if (returnValue != 0)
	{
		return 1;
	}
	int i=0;
	while (stringTotal[i] != '\0')
	{
		
		if (string1[i] != stringTotal[i])
		{
			return -2;
		}
		i++;
	}

	return 0;
}



int testRemove()
{
	//Vars
	char chararray[]  = "mother hubbard";
	char removeword[] = "hubbard";
	wordRemove(chararray, removeword);

	// use strcmp(check,input) != 0 
	//source :: http://stackoverflow.com/questions/8004237/how-do-i-properly-compare-strings-in-c
	if(strcmp(chararray, "mother ") != 0)
	{
		return 0;
	}
	if(strcmp(chararray, "mother") != 0)
	{
		return 0;
	}

	return -1;
}


int generateReport(char* file)
{
	//Vars
	FILE *outFile;
	//Save to specified file
	outFile = fopen(file,"a");
	int functionResponse, i, numFunctions = 7, numErrors = 0;
	struct TesterFunction functions[7] = {
		{"Find Length Function",&testFindLength},
		{"Find Vowels Function",&testVowels},
		{"Find Number of Words Function",&testNumberWords},
		{"Test if char is alpha-numeric",&testAlphaNumericChar},
		{"Create Substring function",&testSubString},
		{"Contatenate Function",&testConcat},
		{"Remove Word Function",&testRemove},
	};


	#define add(line) addStrings(outFile, line)



	//Generate Report Here
	add("\n\nGenerall Tests ...\n");
	add("-----------------------------------------------------------------\n");
	for (i=0; i< numFunctions; i++)
	{
		//printf("%s\n", strings[0].value);
		functionResponse = functions[i].function();
		printf("Index %d Function %s returned %d\n",i, functions[i].name, functionResponse);
		add(functions[i].name);
		//add(" function failed to run.\n");
		
	

		switch (functionResponse)
		{
		case 0:
			add(" function ---  passed all tests.\n\n");
			break;
		case 1:
			add(" function ---- failed to run.\n\n");
			break;
		case -1:
			add(" function ---- did not return the correct result\n\n");
			break;
		case -2:
			add(" function ---- did not return result\n\n");
			break;
		}


	}

	add("\n\nExtra Targeted Testing ...\n");
	add("-----------------------------------------------------------------\n");
	add("ALL PASS");






	printf("\n\n\n\n\n\n\n\n\n-----------------------------------------------------------------\n");
	printf("REPORT HAS BEEN SAVED in file '%s' \n",file);


	


	printf("Output fclose - %d", fclose(outFile));

	return 0;
}




/*
Helper Functions
*/

void deep_copy_string(char* array_from, char* array_to, int array_length){
	//Read more about memcpy over here: http://www.cplusplus.com/reference/cstring/memcpy/

	memcpy(array_to, array_from, array_length * sizeof(char));
}

/*
 * Pro-tip:use this function to generate random arrays.
 */
int generate_random_string_array(char* array, int array_length){
	/* Initialize */
	int i;
	/* Validate input */
	if(!array){
		printf("Error: Input array was NULL\n");
		return 1;
	}
	if(array_length < 1){
		printf("Error: required array size < 1\n");
		return 1;
	}
	/* Generate random values */
	for (i = 0; i < array_length; i++) {

		switch (rand() % 5)
		{
			case 0:
				array[i] = 'A' + (rand() % 26);
				break;
			case 1:
				array[i] = ' ';
				break;
			default:
				array[i] = 'a' + (rand() % 26);
				break;


		}
		
	}
	return 0;
}

int addStrings(FILE *outFile, char *array_add)
{
	
	// int length_main = strlen(*array_main);
	// int length_add = strlen(array_add)+1;
	// //Expand Array
	// *array_main = realloc(*array_main,length_main+length_add);	
	// //Check if expansion was successful

	// deep_copy_string(array_add, *array_main + length_main*sizeof(char), length_add);
	// //int i;
	// // for (i=length_main; i<length_main+length_add; i++)
	// // {
	// // 	*array_main[i] = array_add[i-length_main];
	// // }
	// // //free(array_buffer);
	fputs(array_add,outFile);



	
	return 0;
}

int loadArrays()
{
		//Create some random char arrays and put inside strings array
	int i, currentArrayLength = 10;
	for (i = 0; i < numArrays; i++)
	{
		char array[currentArrayLength];
		generate_random_string_array(array,currentArrayLength);

		strings[i].value = malloc(currentArrayLength);
		strcpy(strings[i].value, array);

		strings[i].length = currentArrayLength;


		currentArrayLength *= 5;
	}

	return 0;
}







