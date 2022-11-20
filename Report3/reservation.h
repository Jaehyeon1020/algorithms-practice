#pragma once

#define MAX_NAME 50

/* struct for reservation informations*/
typedef struct reservation {
	char* name;
	char source;
	char dest;
	int id;
} Reservation;

void initReservation(Reservation* reservation);
Reservation* makeReservation(char* userInput);
void registerReservation(RbTree* tree, int reservationID);
void makeCityGraph(Graph* graph);
char* getFlightPath(Graph* graph, int source, int dest);
void printReservationInfo(Graph* graph, RbTree* rbTree);