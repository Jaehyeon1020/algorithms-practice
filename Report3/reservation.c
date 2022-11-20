/**
* Functions about reservation system
* 
* Functions: 
* [x] Reservation init function
* [x] user input parsing function
* [x] insert Reservation to red black tree
* [] Flight path making function
* [x] city connection making function
* [] 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include "rbtree.h"
#include "graph.h"
#include "reservation.h"

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

/* register Reservation to red black tree by reservation ID */
void registerReservation(RbTree* tree, int reservationID) {
	insertion(tree, reservationID);
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
void printReservationInfo(Graph* graph, RbTree* rbTree) {
	printf("<Your Reservations>\n");
}

