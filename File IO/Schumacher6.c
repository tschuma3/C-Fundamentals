/*
Name: Tyler Schumacher
Assignment Title and #: File IO, Assignment 6
Due Date: December 9, 2019
Description: This program asks the user for the name of the text file. Then reads the file and
prints it to the user. I then asks the user for input and writes to the end of the file 3 times.
Then the file reads and prints out the file again.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 1024 // Can be shorter, but not longer
#define MAXLOOP 3 // To keep track of the max loops the for loop can have

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Prototype
void printFile(char *);

// Main function
int main(int argc, char *argv[]) 
{
	// Declaration of variables
	FILE * filePtr = NULL;
	FILE * fileReadPtr = NULL;
	FILE * fileWritePtr = NULL;
	char filename[50] = "data.dat";
	char * line = NULL;
	char name[50] = "Tommy";
	char trash = '\0';
	
	// Malloc line
	line = (char *)malloc(sizeof(char)* MAX);
	
	// Welcomes and explains the program
	printf("Welcome to Tyler\'s File IO program!");
	printf("\nThis program will ask for a file. It will");
	printf("\nthen read the file and print out the contents.");
	printf("\nIt will then ask you, the user, to write something");
	printf("\nin it three times. Then it will read and print out");
	printf("\nthe file again before ending the program.");
	
	// Asks the user for a file name
	printf("\n\nWhat is the file\'s name > ");
	scanf("%s", &filename);
	
	// Calls the print function
	printFile(filename);
	
	// Opens the file and appends (writes) in the file if it is not null
	if ((fileWritePtr = fopen(filename, "a")) == NULL)
	{
		printf("%s ERROR opening file \n\n", filename);
	}
	else
	{
		// Gets rid of uneeded spaces
		scanf("%c", &trash);
		
		// Loops 3 times
		for (int i = 0; i < MAXLOOP; i++)
		{
			// Appends and writes
			printf("Write something to append > ");
			fgets(name, 50, stdin);
			fprintf(fileWritePtr, "%s", name);
		}
		// Closes the file	
		fclose(fileWritePtr);
	}
	
	// Calls the print function
	printFile(filename);
	
	return 0;
}

// Reads and prints the file
void printFile(char * filename)
{
	// Declared variables
	FILE * printFilePtr = NULL;
	char * line = NULL;
	
	// Malloc line
	line = (char *)malloc(sizeof(char *)* MAX);
	
	// Opens the file and reads it if not null
	if ((printFilePtr = fopen(filename, "r")) == NULL)
	{
		printf("%s does not exist\n\n", filename);
	}
	else
	{
		// Reads the file 
		line = fgets(line, MAX, printFilePtr);
		
		while (line != NULL)
		{
			// Reads line and prints out
			printf("%s", line);
			line = fgets(line, MAX, printFilePtr);
		}
		// Closes the file
		fclose(printFilePtr);
	}
	
}
