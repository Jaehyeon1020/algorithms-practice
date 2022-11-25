/**
* Airline Reservation System
* 2019314891 Kim Jaehyeon
*/

#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rbTree.h"
#include "graph.h"
#include "reservation.h"
#include "linkedList.h"

#define MAX_USER_INPUT 256

void printFirstMenu() {
	printf("1. Make new reservation\n");
	printf("2. Check the reservations\n");
	printf("3. Exit\n");
}

void getMenuInput(char* userInput) {
	printf(">> ");
	scanf("%s", userInput);
	getchar();
}


int main() {
	//Graph* cities = createGraph(CITY_NUM);
	RbTree* reservationTree = newRbTree();
	Reservation* currentReservation;
	reservationNode* head = (reservationNode*)malloc(sizeof(reservationNode));
	head->next = NULL;
	head->reservation = NULL;

	char userInput[MAX_USER_INPUT];
	char userReservationInput[MAX_USER_INPUT];

	printf("========== Welcom to Airline Reservation System ==========\n");
	while (1) {
		printFirstMenu();
		getMenuInput(userInput);

		if (strcmp(userInput, "3") == 0) {
			break;
		}
		else if (strcmp(userInput, "2") == 0) {
			printReservationInfo(reservationTree, head);
		}
		else if (strcmp(userInput, "1") == 0) {
			printf("\nEnter your reservation information (format: name,source,destination)\n>> ");
			scanf("%s", userReservationInput);
			currentReservation = makeReservation(userReservationInput);
			getchar();

			registerReservation(reservationTree, currentReservation->id);
			addData(head, currentReservation);

			printf("Reservation register completed\n\n");
		}
		else {
			printf("You entered wrong input\n");
		}
	}

	printf("========== Exit airline reservation system ==========\n");

	return 0;
}