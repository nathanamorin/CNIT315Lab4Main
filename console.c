/* console.c
* Description: Provides functions for interacting with user inside a console environment.
*
* Name: Nathan Morin
* Email: morinn@purdue.edu
* Course: CNIT 315
* Collaborators : None
*/
#include "console.h"
#include <stdio.h>



int printMenu(char* *array, int arrayLength)
{
	int i;

	printf("\n\n Created by Nathan Morin for CNIT 315 Purdue University\n\n");
	for (i=0; i<arrayLength; i++)
	{
		printf("\t%d for %s\n", i, array[i]);
	}
	return 0;
}

int askQuestionInt(int *value, char *q)
{
	printf("\n%s : ",q);
	scanf("%d", value);

	if (*value == -1)
	{
		return -1;
	}

	while ( getchar() != '\n' );
	return 0;

}

float askQuestionFloat(float *value, char *q)
{	
	printf("%s : ",q);
	scanf("%f", value);

	if (*value == -1)
	{
		return -1;
	}
	while ( getchar() != '\n' );
	
	return 0;

}

int askQuestionString(char *value, char *q)
{	
	//value = "test is a test";
	//char test[100];
	printf("%s : ",q);
	scanf("%[^\t\n]s", value);
	printf("%s\n", value);

	// if (*value == "")
	// {
	// 	return -1;
	// }
	while ( getchar() != '\n' );
	
	return 0;

}