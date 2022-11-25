/**
* Functions about reservation system
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include "rbtree.h"
#include "graph.h"
#include "reservation.h"
#include "linkedList.h"

/* init Reservation */
void initReservation(Reservation* reservation) {
	static int idCount = 1; // reservation id

	reservation->name = (char*)malloc(sizeof(char) * MAX_NAME);
	reservation->id = idCount++;
}

/* make Reservation from user input */
Reservation* makeReservation(char* userInput) {
	Reservation* newReservation = (Reservation*)malloc(sizeof(Reservation));
	initReservation(newReservation);
	
	/* split user input by ',' */
	newReservation->name = strtok(userInput, ",");
	newReservation->source = (strtok(NULL, ","))[0];
	newReservation->dest = (strtok(NULL, ","))[0];

	return newReservation;
}

/* get reservation that has identical reservation id ID */
Reservation* getReservation(int id, reservationNode* reservations) {
	return search(reservations, id);
}

/* register Reservation to red black tree by reservation ID */
void registerReservation(RbTree* tree, int reservationID) {
	insertion(tree, reservationID);
}

/* save Reservations to linked list*/
void saveReservation(Reservation* reservation, reservationNode* reservations) {
	addData(reservations, reservation);
}

/* make random connections of cities */
void makeCityGraph(Graph* graph) {
	int connectionCount;
	int randomNumber;

	srand(time(NULL));

	for (int i = 0; i < CITY_NUM; i++) {
		connectionCount = getConnections(graph, i);

		/* make connections until the number of connections become 10 */
		while (connectionCount < 10) {
			randomNumber = rand() % 26;
			
			if (randomNumber != i && !isAlreadyConnected(graph, i, randomNumber)) {
				addEdge(graph, i, randomNumber);
				connectionCount += 1;
			}
		}
	}
}

/* generate flight path: from source to dest */
char* getFlightPath(Graph* graph, int source, int dest) {
	
}

/* print reservation informations */
void printReservationInfo(Graph* graph, RbTree* rbTree, reservationNode* reservations) {
	reservationNode* currentNode = reservations->next;

	printf("========================\n");
	printf("<Your Reservations>\n");

	while(reservations->next != NULL) {
		Reservation* currentReservation = currentNode->reservation;

		printf("Name: %s\n", currentReservation->name);
		printf("Reservation ID: %d\n", currentReservation->id);
		printf("Source: %d\n", currentReservation->source);
		printf("Destination: %d\n", currentReservation->dest);
		printf("---------------------\n");
		
		reservations = reservations->next;
	}

	printf("========================\n");
}

