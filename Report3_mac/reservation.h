#pragma once

#include "rbTree.h"
#include "graph.h"

#define MAX_NAME 50

typedef struct Node reservationNode;

/* struct for reservation informations*/
typedef struct Reservation {
	char* name;
	int source;
	int dest;
	int id;
} Reservation;

void initReservation(Reservation* reservation);
Reservation* makeReservation(char* userInput);
void registerReservation(RbTree* tree, int reservationID);
void makeCityGraph(Graph* graph);
char* getFlightPath(Graph* graph, int source, int dest);
void saveReservation(Reservation* reservation, reservationNode* reservations);
void printReservationInfo(Graph* graph, RbTree* rbTree, reservationNode* reservations);
Reservation* getReservation(int id, reservationNode* reservations);