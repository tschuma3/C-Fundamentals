/*
Name: Tyler Schumacher
Assignment Title and #: Arrays of String Pointers, Assignment 5
Due Date: December 4, 2019
Description: This program prints out an initial array by passing the array into a print function. 
The array is then passed into another function that sorts the array in alphabetical order. Then the 
array is passed once again into the print function and the sorted array is printed.
*/

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Prototypes
void printList(int size, char ** wordPtr);
void sortList(int size, char ** wordPtr);

// Main function
int main(int argc, char *argv[]) 
{
	// Declares the size variable
	int size = 0;
	
	// Declares the array
	char * wordPtr[] = {"Matthew", "Peter", "James", "Luke"};
	
	// Sets size equal to size of the array
	size = sizeof(wordPtr) / sizeof(char *);
	
	// Welcomes and explains the program
	printf("Welcome to Tyler's Array of String Pointers Assignment!");
	printf("\nIn this assignment an array is created. The initial array");
	printf("\nis printed out in a printList function. The same array is");
	printf("\nthen sorted in a sortList function and the reprinted out");
	printf("\nusing the same printList function as before.\n");

	// Initial array label
	printf("\nThis is the initial array!\n");

	// Prints the initial array	
	printList(size, wordPtr);
	
	// Sorts the array
	sortList(size, wordPtr);
	
	// Sorted array label
	printf("\n\nThis is the sorted array!\n");
	
	// Prints the sorted array
	printList(size, wordPtr);
	
	return 0;
}

// This function prints the list
void printList(int size, char ** wordPtr)
{	
	// Loops through the array until all the elements have been printed
	for (int i = 0; i < size; i++)
	{
		printf("%s ", wordPtr[i]);
	}
}

// This function sorts the list
void sortList(int size, char ** wordPtr)
{	
	// Temporary variable
	char * temp = NULL;
	
	// Loops through the array until all elements are sorted
	for (int c = 0; c < size; c++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			// Sorts if the first element is greater than the second
			if (*wordPtr[i] > *wordPtr[i + 1])
			{
				// Sorts the array
				temp = wordPtr[i];
				wordPtr[i] = wordPtr[i + 1];
				wordPtr[i + 1] = temp;
			}
		}
	}
}
