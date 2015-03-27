/* console.h
* Description: Provides functions for interacting with user inside a console environment.
*
* Name: Nathan Morin
* Email: morinn@purdue.edu
* Course: CNIT 315
*
*/
/*
Ask the user a question and returns the numeric result as a int or float
@return -1 means user wants to exit
@return 0 successful input
@return 1 error
*/
float askQuestionFloat(float *value, char *q);
int askQuestionInt(int *value, char *q);
int askQuestionString(char *value, char *q);

/*
Takes an aray of strings along with an array length and print out a menu
Selector for first element 0, second 2 ...
*/
int printMenu(char* *array, int arrayLength);