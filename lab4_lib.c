/*
* Names:Matthew Morehouse, Ben Hail, Joseph Christopher, Luella Stonecipher, Sabrina Hsu, and Taylor Curtis
* Email:mmorehou@purdue.edu
* Course: CNIT 315
* Lab batch:10
* Lab assignment: 4
* Date:March 3rd, 2015
*/


#include <stdio.h>
#include <stdlib.h>
#include "lab4_lib.h"

int wordCount(char* sentence_array, int* numWords)
{
  if (sentence_array == '\0')
  {
    printf("ERROR: array entered was null.\n");
    return 1;
  }
  *numWords = CountWords(sentence_array, 0, 0, 1000);
  return 0;
}
// This is the start of the function that counts the number of words.
// Code written by Matthew Morehouse
int CountWords(char* sentence_array, int count, int start, int maxSize)
{
  
  //Validation checks start here
  if (count < 0)
  {
    printf("ERROR: count needs to be greater than 0.\n");
    return 1;
  }
  if (sentence_array == NULL)
  {
    printf("ERROR: array entered was null.\n");
    return 1;
  }
  if (start > maxSize)
  {
    printf("ERROR: the start point was greater than the max size.\n");
    return 1;
  }
  if (start < 0 || maxSize < 0)
  {
    printf("ERROR: the start point or the max size were set less than zero.\n");
    return 1;
  }
  if (sentence_array[0] == ' ')
  {
    printf("ERROR: the first character in the array was empty. Please start "
    "your sentence from the beginning.\n");
    return 1;
  }
  
  int a = 0;
  //getting the actual size of the array
  while (sentence_array[a] != '\0')
  {
    a++;
  }
  maxSize = a;
  
  //checking to see if there is a blank space in the index
  //If there is a blank space, then increase the count of words
  if (sentence_array[start] == ' ' && sentence_array[start - 1] != ' ' &&
   start != (maxSize-1))
  {
    count = count+1;
  }
  //Continuation criteria
  if (start != maxSize)
  {
    count = CountWords(sentence_array, count, (start + 1), maxSize);
  }
  //Exit criteria
  if (start == maxSize)
  {
    count++;
    printf("number of words: %d\n", count);
    return count;
  }
  
  return count;
}

// This is the start of the function to remove a word from a sentence.
// Code written by Matthew Morehouse
int wordRemove(char* sentence_array, char* word)
{
 if (sentence_array == NULL)
  {
    printf("ERROR: array entered was null.\n");
    return 1;
  }
  if (word == NULL)
  {
    printf("ERROR: array entered was null.\n");
    return 1;
  }
  
  int sizeSentence = 0;
  while (sentence_array[sizeSentence] != '\0')
  {
    sizeSentence++;
  }
  
  
  int sizeWord = 0;
  while (word[sizeWord] != '\0')
  {
    sizeWord++;
  }
  
  int head=-1,scanner, stop = sizeSentence - sizeWord;
  int found = 0;
  while (head<=stop && found == 0)
  {
    head++;
    scanner = 0;
    if (sentence_array[head] == word[0])
    {
      while (scanner < sizeWord)
      {
        found = 1;
        if (sentence_array[head+scanner] != word[scanner])
        {
          found = 0;
          break;
        }
        scanner++;
      }
    }
  }
  int i=head;
  while (sentence_array[i+sizeWord] != '\0')
  {
   sentence_array[i] = sentence_array[i+sizeWord]; 
   i++;
  }
  sentence_array[i] = '\0';
  
  return 0;
  
  
}


// This is the start of the function that checks the number of vowels in a sentence.
// Code written by Joseph Christopher
int vowelCheck(char* array, int* vowels)
{
    
    int i;
    
    for (i = 0; array[i] != '\0'; i++)
    {
        if ((array[i] == 'a' || array[i] == 'e' || array[i] ==
        'i' || array[i] == 'o' || array[i] == 'u') ||
        (array[i] == 'A' || array[i] == 'E' || array[i] ==
        'I' || array[i] == 'O' || array[i] == 'U'))
        {
            *vowels = *vowels + 1;
        }
     }
    
    printf("No. of vowels in %s = %d\n", array, *vowels);

    return 0;
    
}


// This is the start of the substring portion of the lab
// Code written by Ben Hail
int subString (char *array1, int index1, int index2)
		{
				
			int position;
			int i = 0;
			char input2[100];
	
			

		if (array1 == NULL)
				{
					return 1;
				}

			// for (position = index1; position <= index2; position++)
   //      {
   //          printf("%c", array1[position]);
						
			// 			input2[i] = array1[position];
			// 			i++;
						

   //      }
        position = index1;
        for (i=0; array1[i] != '\0'; i++, position++)
        {
          if (position <= index2)
          {
            array1[i] = array1[position];
          }
          else
          {
            array1[i] = NULL;
          }

        }
				
					// array1 = input2;
     //     printf("\n");
					return 0;
		}

// This is the start of the function that concatenates two strings together
// Code written by Sabrina Hsu
int concatenateStrings(char* str1, char* str2)
{
	int firstArrayLength = 0;
	int secondArrayLength = 0;
	
	while (str1[firstArrayLength] != '\0')
	{
		firstArrayLength++;
	}
  printf("%d",firstArrayLength);
	
  while (str2[secondArrayLength] != '\0')
	{
		//printf("Copying - '%c'\n",str2[secondArrayLength]);
    str1[firstArrayLength] = str2[secondArrayLength];
    printf("%c\n", str1[firstArrayLength]);
    secondArrayLength++;
    firstArrayLength++;
	}
  
  str1[firstArrayLength] = '\0';


	return 0;
}



//  Function for accepting astring from a user and then printing it back 
//  for verification
//  uses a character array of 50
//  only allows 50 characters to be "Scanned" by scanf
//  returns the string for the user to see
//  Code written by Luella Stonecipher
  
  int printString()
  {
    char mystring[50];
  printf("Please type a string\n\n");
  scanf("\n%50[^\n]s", mystring);
  printf("%s\n", mystring);
  }
  
  
  
//  Function for accepting a string from a user and then returning the string
//  for verificaiton and then counts the length\
//  only 50 characters is allowed because the array is statically set to 50
//  Code written by Luella Stonecipher
    int printStringWLen(char* array, int* length)
  {

  if (array[0] == '\0')
  {
    printf("Error -- array is null");
   return 1; 
  }
  
  int number = 0;
  while (array[number] != '\0')
  {
    number++;
  }
  
  *length = number;
  
  printf("You Entered:%s\n", array);
  printf("The Length of the string is: %d\n",*length);
  return 0;
  
  }


// This is the start of the alphaNumeric function
// Code written by Taylor Curtis
int alphaNumeric(char ch)
{
	//scanf("%c", &ch);
	
	if (ch >= '0' && ch <= '9')
	{
		printf("|%c| is alphanumeric.\n", ch);
	}
	else if (ch >= 'A' && ch <= 'Z')
	{
		printf("|%c| is alphanumeric.\n", ch);
	}
	else if (ch >= 'a' && ch <= 'z')
	{
		printf("|%c| is alphanumeric.\n", ch);
	}
	else
	{
		printf("%c is not alphanumeric.\n", ch);
	}
	return 0;
}

