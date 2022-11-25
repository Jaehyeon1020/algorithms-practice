/**
* Airline Reservation System
* 2019314891 Kim Jaehyeon
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rbtree.h"
#include "graph.h"
#include "reservation.h"
#include "linkedList.h"

void printFirstMenu() {
	printf("========== Airline Reservation System ==========\n");
	printf("1. Make new reservation\n");
	printf("2. Check the reservations\n");
	printf("3. Exit\n");
}

void getMenuInput(char* userInput) {
	printf("Select : ");
	scanf("%s", userInput);
}

void getReservationInput(char* userInput) {
	printf("Enter your reservation information (format: name,source,destination,date) : ");
	scanf("%s", userInput);
}

int main() {
	Graph* cities = createGraph(CITY_NUM);
	RbTree* reservationTree = newRbTree();
	Reservation* currentReservation;
	reservationNode* head = NULL;

	char* userInput;

	while (1) {
		printFirstMenu();
		getMenuInput(userInput);

		if (strcmp(userInput, "3") == 0) {
			break;
		}
		else if (strcmp(userInput, "2") == 0) {
			printReservationInfo(cities, reservationTree, head);
		}
		else if (strcmp(userInput, "1") == 0) {
			getReservationInput(userInput);
			currentReservation = makeReservation(userInput);
			registerReservation(reservationTree, currentReservation->id);
			addData(head, currentReservation);
		}
		else {
			printf("You entered wrong input\n");
		}
	}
	
	printf("========== Exit airline reservation system ==========\n");

	return 0;
}