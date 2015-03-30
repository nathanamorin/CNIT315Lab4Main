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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4_lib.h"

/*
Function : Test Find Length
Purpose: runs test on indicated function
@return
0 - Passed All Tests
-1 - Return Incorrect Result
-2 - Did Not Return Result
1 - Failed to Run
*/
int testFindLength();

/*
Function : Test Number Vowels
Purpose: runs test on indicated function
input should be char array, pointer of lengthvariable
not testing for nulls
@return
0 - Passed All Tests
-1 - Return Incorrect Result
-2 - Did Not Return Result
1 - Failed to Run
*/
int testVowels();

/*
Function : Test Number Words
Purpose: runs test on indicated function
input should be char array
input should be pointer of numberofvowelsvariable
return should be 0 if successful and 1 if not
input char
@return
0 - Passed All Tests
-1 - Return Incorrect Result
-2 - Did Not Return Result
1 - Failed to Run
*/
int testNumberWords();

/*
Function : Test Alpha Numeric Word
Purpose: runs test on indicated function
input should be char array
input should be pointer of numberofwordsvariabe
return should be 0 if successful and 1 if not
@return
0 - Passed All Tests
-1 - Return Incorrect Result
-2 - Did Not Return Result
1 - Failed to Run
*/
int testAlphaNumericChar();

/*
Function : Test Substring
Purpose: runs test on indicated function
@return
input value, char
return 0 for alphaneurmeric or 1 if other type

*/
int testSubString();

/*
Function : Test Concatenation 
Purpose: runs test on indicated function
input char array, char array, int index1, int index2
@return
0 - Passed All Tests
-1 - Return Incorrect Result
-2 - Did Not Return Result
1 - Failed to Run
*/
int testConcat();

/*
Function : Test Remove Word
Purpose: runs test on indicated function
input char array, char array, int length, int length2
@return
0 - Passed All Tests
-1 - Return Incorrect Result
-2 - Did Not Return Result
1 - Failed to Run
*/
int testRemove();

/*
Function : generate report
Purpose: using testing functions, generate report and push out to .txt file
			specified in main input.
input char array(totalstring), char array(word to remove)
return 0 for success
return 1 for fail
*/
int generateReport(char* file);



/**
* Function: deep_copy_string()
*
* Duplicates the input array and stores the deep copy in the output array.
*
* Parameters:
* @param array_from	The array that needs to be copied.
* @param array_to  	The new array which will hold a deep copy of the input
* 						array.
* @param array_length	The length of the input array.
*
* Returns:
* 	@return 	0 - Successful completion of the function.
* 				1 - An error during operation.
*
* Expectations:
* 	- All parameters are valid, i.e.:
* 			* array_from is declared.
*			* array_to has enough memory allocated.
*			* array_length accurately portrays the number of elements in
*			  array_from
* Coppied From Lab 3
*/
void deep_copy_string(char* array_from, char* array_to, int array_length);

/**
* Function: generate_random_string()
*
* Generates an integer array of specified size filled with random chars.
*
*
* Parameters:
* 	@param array 			Pointer to the char array.
* 	@param array_length 	Number elements to be stored in the array.
*
* Returns:
* 	@return 	0 - Successful.
* 				1 - Fail/Error.
*
* Expectations:
* 	- None
* Modified From Lab 3
*/

int generate_random_string(char* array, int array_length);

int addStrings(FILE *outFile, char *array_add);

int loadArrays();
