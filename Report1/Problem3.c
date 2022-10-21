#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
	int data;
	struct Node* next;
}node;

int calculateLinkedListLength(node* listHead)
{
	int length = 1;

	if (listHead->next == NULL)
		return 0;
	
	node * currentNode = listHead->next;
	while (1)
	{
		if (currentNode->next != NULL)
		{
			length++;
			currentNode = currentNode->next;
		}
		else
		{
			return length;
		}
	}
}

void insert(node* listHead, int value)
{
	// in case only head
	if (listHead->next == NULL)
	{
		node* newNode = (node*)malloc(sizeof(node));
		newNode->next = NULL;
		newNode->data = value;
		listHead->next = newNode;
		return;
	}

	// in case the list has node except head
	node* currentNode = listHead->next;
	while (1)
	{
		if (currentNode->next != NULL)
			currentNode = currentNode->next;
		else
			break;
	}
	node* newNode = (node*)malloc(sizeof(node));
	newNode->next = NULL;
	newNode->data = value;
	currentNode->next = newNode;
}

void delete(node* listHead)
{
	int length = calculateLinkedListLength(listHead);
	node * currentNode = listHead;

	for (int i = 0; i < length - 3; i++)
		currentNode = currentNode->next;
	
	node* nextOfCurrentNode = currentNode->next;
	currentNode->next = nextOfCurrentNode->next;
	free(nextOfCurrentNode);
}

void print(node* listHead)
{
	int length = calculateLinkedListLength(listHead);
	int firstSecondLineNumber = length / 3;
	int thirdLineNumber = length - (firstSecondLineNumber * 2);
	node* currentNode = listHead;

	printf("1st line : ");
	for (int i = 0; i < firstSecondLineNumber; i++)
	{
		if (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
			printf("%d ", currentNode->data);
		}
	}
	printf("\n");

	printf("2nd line : ");
	for (int i = 0; i < firstSecondLineNumber; i++)
	{
		if (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
			printf("%d ", currentNode->data);
		}
	}
	printf("\n");

	printf("3rd line : ");
	for (int i = 0; i < thirdLineNumber; i++)
	{
		if (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
			printf("%d ", currentNode->data);
		}
	}
	printf("\n");
}

int main()
{
	node* lst = (node*)malloc(sizeof(node)); // head of linkedList
	lst->next = NULL;

	int randNumberArray[60];
	srand(time(NULL));
	for (int i = 0; i < 60; i++)
	{
		randNumberArray[i] = rand() % 1000;
		for (int j = 0; j < i; j++)
		{
			if (randNumberArray[i] == randNumberArray[j])
			{
				i--;
				break;
			}
		}
	}

	for (int i = 0; i < 60; i++)
	{
		insert(lst, randNumberArray[i]);
	}

	for(int i=0; i<3; i++)
	{ 
		delete(lst);
		print(lst);
		printf("\n");
	}

	return 0;
}