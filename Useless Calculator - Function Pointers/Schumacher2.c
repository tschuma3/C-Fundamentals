/*
Name: Tyler Schumacher
Assignment Title and #: Useless Calculator - Function Pointers, Assingment 2
Due Date: October 16, 2019
Description: This program prompts the user for which function they would like to run.
The program loops until the choice to exit is selected. The program should use an array
oof three functions where the first function multiplies the inputted value by 2, the 
second function squares the inputted value, and the third function cubes the inputted
value. The function will be pass the user inputted value, print the equation without 
the answer, and return the solution. There is only one line of code for calling all 
three functions.
*/

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int doubleFun(int num);
int squareFun(int num);
int cubeFun(int num);

int main(int argc, char *argv[]) 
{
	//Declaring Variables
	int choice;
	int value;
	
	//Declaring a prototype
	int (*ptr[3])(int);
	
	//Arrays pointed at the respected functions
	ptr[0] = &doubleFun;
	ptr[1] = &squareFun;
	ptr[2] = &cubeFun;
	
	//Displaying a menu, gets choice, and diplays a value based off of choice
	do
	{
		printf("\n0    exit\n");
		printf("\n1    double(operand) * 2\n");
		printf("\n2    square (operand) * (operand)\n");
		printf("\n3    cube (operand) ^ 3\n");
		
		printf("\nEnter a menu choice: ");
		scanf("%d", &choice);
		
		if (choice != 0)
		{
			printf("\nEnter a value for the operand: ");
			scanf("%d", &value);
			printf("%d\n", ptr[choice - 1] (value));
		}
	}
	
	//Keeps going as long as the choice is not 0
	while (choice != 0);
	
	return 0;
}

//Double function
int doubleFun(int num)
{
	printf("%d * 2 = ", num);
	return num * 2;
}

//Square function
int squareFun(int num)
{
	printf("%d ^ 2 = ", num);
	return num * num;
}

//Cube function
int cubeFun(int num)
{
	printf("%d ^ 3 = ", num);
	return num * num * num;
}
