/**
* Functions about reservation system
* 
* ���� ���:
* [x] ����� input �޾Ƽ� reservation ��ü�� �����ϴ� �Լ�
* [] output ��� �Լ�
* [] Flight path ã�� �Լ�
* [] ������ ���� ���� �Լ�
* [] ��� Ž�� �Լ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbTree.h"
#include "graph.h"
#include "reservation.h"

void initReservation(Reservation* reservation) {
	reservation->name = (char*)malloc(sizeof(char) * MAX_NAME);

}

/* ���� �Է����κ��� ���� ������ �޾� Reservation ��ü�� ���� */
Reservation* makeReservation(char* userInput) {
	Reservation* newReservation = (Reservation*)malloc(sizeof(Reservation));
	initReservation(newReservation);
	
	/* input�� "," �������� ������ Reservation ��ü�� �����ϰ� ���� */
	newReservation->name = strtok(userInput, ",");
	newReservation->source = (strtok(NULL, ","))[0];
	newReservation->dest = (strtok(NULL, ","))[0];
	newReservation->departureTime = atoi(strtok(NULL, ","));

	return newReservation;
}