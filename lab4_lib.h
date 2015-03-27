#ifndef LAB4_LIB_H_
#define LAB4_LIB_H_


int wordCount(char* sentence_array, int* numWords);
int CountWords(char* sentence_array, int count, int start, int maxSize);
/*
  This function counts the number of words in a char array
  sentence_array needs to be the character array that has all of the words to be counted
  count needs to be initialized to 0
  start needs to be initialized to 0
  maxSize needs to be the maximum size of the character array entered
*/

int wordRemove(char* sentence_array, char* word);
/*
  This function removes a single word from a char array.
  sentence_array needs to be the char array that has the word that you want removed
  maxSize needs to be the maximum size of the character array entered
*/

int vowelCheck(char* array, int* vowels);
/*
  This function counts the number of vowels in a char array
  the function does not require any input
*/

int subString(char* array1, int index1, int index2);
/*
  This function prints the characters in a substring
  The char array is made inside of the function
  the function does not require any input.
*/

int concatenateStrings(char* str1, char* str2);
/*
  This function combines two character arrays together
  the function requires two char arrays that already have characters in them
*/

int printString();
/*
  Function for accepting astring from a user and then printing it back 
  for verification
  uses a character array of 50
  only allows 50 characters to be "Scanned" by scanf
  returns the string for the user to see
*/

int printStringWLen(char* array, int* length);
/*
  Function for accepting a string from a user and then returning the string
  for verificaiton and then counts the length\
  only 50 characters is allowed because the array is statically set to 50
*/

int alphaNumeric(char ch);
/*
  Function to determine if a character is alphanumeric or not
  Requires a single character
  prints the result during the function runtime
*/

#endif
