/**
* Functions about reservation system
* 
* ���� ���:
* [x] Reservation ��ü �ʱ�ȭ �Լ�
* [x] ����� input �޾Ƽ� Reservation ��ü�� �����ϴ� �Լ�
* [x] Reservation ��ü�� Red Black Tree�� �����ϴ� �Լ�
* [] Flight path ����� �Լ�
* [x] ������ ���ð� ���� ���� �Լ�
* [] ��� Ž�� �Լ�
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rbtree.h"
#include "graph.h"
#include "reservation.h"

/* Reservation ��ü �ʱ�ȭ */
void initReservation(Reservation* reservation) {
	static int idCount = 1; // reservation id �ο�: 1���� ����

	reservation->name = (char*)malloc(sizeof(char) * MAX_NAME);
	reservation->id = idCount++;
}

/* ���� �Է����κ��� ���� ������ �޾� Reservation ��ü�� ���� */
Reservation* makeReservation(char* userInput) {
	Reservation* newReservation = (Reservation*)malloc(sizeof(Reservation));
	initReservation(newReservation);
	
	/* input�� "," �������� ������ Reservation ��ü�� �����ϰ� ���� */
	newReservation->name = strtok(userInput, ",");
	newReservation->source = (strtok(NULL, ","))[0];
	newReservation->dest = (strtok(NULL, ","))[0];

	return newReservation;
}

/* Reservation id�� ��ü Ʈ���� ���� */
void registerReservation(RbTree* tree, int reservationID) {
	insertion(tree, reservationID);
}

/* �������� ����� ���ø� ���� */
void makeCityGraph(Graph* graph) {
	int connectionCount;
	int randomNumber;

	srand(time(NULL));
	/* city���� �������� 10���� ������ ���� */
	for (int i = 0; i < CITY_NUM; i++) {
		connectionCount = getConnections(graph, i);

		/* �� ������ 10���� �� ������ ���� ���� */
		while (connectionCount < 10) {
			randomNumber = rand() % 26;
			
			if (randomNumber != i && !isAlreadyConnected(graph, i, randomNumber)) {
				addEdge(graph, i, randomNumber);
				connectionCount += 1;
			}
		}
	}
}