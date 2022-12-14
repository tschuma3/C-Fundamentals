/*
Name: Tyler Schumacher
Assignment Title and #: Ordered Link Lists, Assignment 4
Due Date: November 13, 2019
Description: This program asks for an user input that is greater than 0. If the user inputs 0 or a
negative number then the program will exit. There is a main function that prints a welcome message
and instructions. The main function calls a function the createNode function. The main function
calls a function that prints tha list just before exiting and frees the list. The createNode function
creates a new node, initializes that new node, and calls the insertNode function. The insertNode 
function inserts the node into the linked list. The printTheList function runs after exiting the 
program. The printTheList function prints the linked list and calls the freeTheList function. The 
freeTheList function frees the list.
*/

#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct listNode 
{
	int data;  //ordered field
    struct listNode *next;
} header = {0, NULL};

// Prototypes
void createNewNode(int);
void insertNode(struct listNode*);
void printTheList(void);
void freeTheList(void);

int main(int argc, char *argv[]) 
{
	// Initialize local variable
	int userValue = 1;
	
	// Welcomes user to the program
	printf("\nWelcome to Tyler's Ordered Link List program\n");
	printf("\nThis program builds an ordered link list of numbers graeter than 0.\n");
	printf("\nOnce the user inputs a 0 or negative number the program will print out\n");
	printf("\nthe ordered link list and exit the program.\n");
	printf("\nPlease input an integer or enter a negative number or 0 to exit.\n");
	scanf("%d", &userValue);
	
	// As long as the user doesn't input a value less than or equal to 0
	while (userValue > 0)
	{
		// Calls createNode function
		createNewNode(userValue);
		
		printf("\nPlease input an integer or enter a negative number or 0 to exit.\n");
		scanf("%d", &userValue);	
	}
	
	// Calls free function once user inputs 0 or a negative number
	printTheList();
	
	return 0;
}

// Creates a new node
void createNewNode(int userValue)
{
	// Creates the node
	struct listNode * newNode = NULL;
	newNode  = (struct listNode *) malloc(sizeof(struct listNode));
	
	// Sets the node
	(*newNode).data = userValue;
	
	// Calles the insert function
	insertNode(newNode);
}

// Inserts a new node
void insertNode(struct listNode * newNode)
{
	// Gets previous and current
	struct listNode * previous = &header;
	struct listNode * current = header.next;
	
	// As long as current is not null insert the new node
	while (current != NULL && newNode -> data > current -> data)
	{
		previous = current;
		current = current -> next;
	}
	
	// Set newNode and current to the correct data
	previous -> next = newNode;
	newNode -> next = current;
}

// Prints the list
void printTheList()
{
	// Initialized variables
	struct listNode * current = &header;
	
	// Printing list
	printf("\nPrinting your list...\n");
	
	// Does the while loop as long as current isn't null
	while (current != NULL)
	{
		// Prints the current node
		printf("%d,\n", current -> data);
		
		// Sets current equal to the next node
		current = current -> next;
	}
	
	// Prints NULL and calls the freeTheList function
	printf("NULL");
	freeTheList();
}

// Frees the linked list
void freeTheList()
{
	// Initialized variables
	struct listNode * current = &header;
	struct listNode * temp = NULL;
	
	while (current != NULL)
	{
		// Sets current to next an frees the node
		temp = current;
		current = current -> next;
		temp = NULL;
		free(temp);
	}
}
