#include <stdio.h>
#include <stdlib.h>
/*
Name: Tyler Schumacher
Class: CS 2060-001
Due: September 25, 2019
Assignment: Pass by Reference
Description: In this program, the user is asked to input three integers and displays them. After that the 
program passes the three integers to a function that sorts them and passes them back to the main function
and displays the integers again.
*/

//Main method
int main(int argc, char *argv[]) 
{
	//Declared for ease
	int valueOne = 0;
	int valueTwo = 0;
	int valueThree = 0;
	int *vptrOne = &valueOne;
	int *vptrTwo = &valueTwo;
	int *vptrThree = &valueThree;
	
	//Welcomes the user and asks for the three integer inputs
	printf("Hello and welcome to Tyler's Sort Program!");
	printf("\nThis program will sort three user inputted integer values.\n");
	printf("\nPlease input the first integer.\n");
	scanf("%d", &valueOne);
	printf("\nPlease input the second integer.\n");
	scanf("%d", &valueTwo);
	printf("\nPlease input the third integer.\n");
	scanf("%d", &valueThree);
	printf("\nYour three values to be sorted are: \n");
	printf("Value One = %d   ", valueOne);
	printf("Value Two = %d   ", valueTwo);
	printf("Value Three = %d\n", valueThree);
	
	//Calls the Sort function	
	printf("\nThe sorted values are: \n");
	Sort(vptrOne, vptrTwo, vptrThree);
	
	return 0;
}

//This function sorts the three values given in acsending order
void Sort(int *vptrOne, int *vptrTwo, int *vptrThree)
{
	//Variable initialized
	int vOne = *vptrOne;
	int vTwo = *vptrTwo;
	int vThree = *vptrThree;
	
	//Value order one, two, three
	if(vOne <= vTwo && vOne <= vThree && vTwo <= vThree)
	{
		printf("Value One = %d   ", vOne);
		printf("Value Two = %d   ", vTwo);
		printf("Value Three = %d\n", vThree);
	}
	//Value order one, three, two
	else if(vOne <= vTwo && vOne <= vThree && vThree <= vTwo)
	{
		printf("Value One = %d   ", vOne);
		printf("Value Three = %d   ", vThree);
		printf("Value Two = %d\n", vTwo);
	}
	//Value order two, one, three
	else if(vTwo <= vOne && vTwo <= vThree && vOne <= vThree)
	{
		printf("Value Two = %d   ", vTwo);
		printf("Value One = %d   ", vOne);
		printf("Value Three = %d\n", vThree);
	}
	//Value order two, three, one
	else if(vTwo <= vOne && vTwo <= vThree && vThree <= vOne)
	{
		printf("Value Two = %d   ", vTwo);
		printf("Value Three = %d   ", vThree);
		printf("Value One = %d\n", vOne);
	}
	//Value order three, one, two
	else if(vThree <= vOne && vThree <= vTwo && vOne <= vTwo)
	{
		printf("Value Three = %d   ", vThree);
		printf("Value One = %d   ", vOne);
		printf("Value Two = %d\n", vTwo);
	}
	//Value order three, two, one
	else if(vThree <= vOne && vThree <= vTwo && vTwo <= vOne)
	{
		printf("Value Two = %d   ", vTwo);
		printf("Value One = %d   ", vOne);
		printf("Value Three = %d\n", vThree);
	}
}


