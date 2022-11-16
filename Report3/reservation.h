#pragma once

#define MAX_NAME 50

/* struct for reservation informations*/
typedef struct reservation {
	char* name;
	char source;
	char dest;
	int departureTime;
} Reservation;

Reservation* makeReservation(char* userInput);