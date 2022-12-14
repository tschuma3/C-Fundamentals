/*
Name: Tyler Schumacher
Assignment Title and #: Stacking using Pointers, Assignment 3
Due Date: Originally October 30, 2019 - Changed to October 31, 2019
Description: This program implements a stack. The stack will have 5 float slots. It will use 
pointer arithmetic for everything. There are no indexes or variables that keep track of the current
element. There is a function called push(pass in top) that requests a float value from the user 
and puts it on the stack. There is a function called pop(pass in top) that takes a number off the 
stack and prints it out to the user (2 decimal places!). There is a function named unwind(pass in 
top), that pops everything left on the stack by calling pop( ) in a loop until the stack is empty.
There is a pointer called top. There is a main() that uses an array of three function pointers,
displays the menu(the same way).
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() 
{
	//Declares an array
	float stack[SIZE] = {0};
	int choice = 0;
	//Initializes the top of stack
	float *top = 0;
	
	//Loops until the user's choice is not 3
	do
	{
		//Welcome
		printf("\n Welcome to Tyler's Stack Using Pointers Program!");
		printf("\n This program implements a stack. The stack has 5 float slots. The program");
		printf("\n uses pointer arithmetic for everything.");
		
		//Dsplays menu
		printf("\n\t Menue:");
		printf("\n\t 0	exit");
		printf("\n\t 1	push value onto stack");
		printf("\n\t 2	pop value off stack");
		
		//Choice
		printf("\n Enter a Menu Option: ");
		scanf("%d", &choice);
		
		//Checks the users input and calls the right function
		switch(choice)
		{
			case 1:
				push(&top, stack);
				break;
			case 2:
				pop(&top, stack);
				break;
			case 0:
				unwind(&top, stack);
				exit(0);
				break;
			default:
				printf("\n\t Please enter a valid choice(0/1/2)");
		}
	}
	
	while(0 <= choice < 3);
	
	return 0;
}

//This function pushes
int push(int *top, float stack[])
{
	//Stores the number
	float num = 0;
	
	//Checks the stack size and either displays an error message or accpets and pushes data
	if (*top >= SIZE - 1)
	{
		printf("\n\t Error: STACK Overflow");
	}
	else
	{
		printf("Enter a value to Push: ");
		scanf("%d", &num);
		
		//Increase the top position by one
		*top++;
		//Assigns the number to the top of the stack
		num = stack[*top];
		return num;
	}
}

//This function pops
int pop(int *top, float stack[])
{
	//Checks if the top is -1 and either displays an error message or pops the number
	if (*top <= -1)
	{
		printf("\n\t Error: STACK Underflow");
	}
	else
	{
		//Displays the stack top number
		printf("\n\t Popped value is %d", stack[*top]);
		//Decreases the stack top by 1
		*top--;
		return top;
	}
}

//This function traverses the stack and display the numbers
int unwind(int *top, float stack[])
{
	//Loop variable
	int j = 0;
	
	//Checks if the top is greater or equal to 0 otherwise displays error message
	if (*top >= 0)
	{
		printf("\n Stack Contents \n");
		//Loops till the end of stack and displays the stacks
		for (j = *top; j >= 0; j--)
		{
			printf("\n| %d |", stack[j]);
		}
		return top;
	}
	else
	{
		printf("\n Stack is Empty");
	}
}
