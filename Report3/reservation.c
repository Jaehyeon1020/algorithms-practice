/**
* Functions about reservation system
* 
* 구현 기능:
* [x] Reservation 객체 초기화 함수
* [x] 사용자 input 받아서 Reservation 객체에 저장하는 함수
* [x] Reservation 객체를 Red Black Tree에 저장하는 함수
* [] Flight path 만드는 함수
* [x] 무작위 도시간 연결 생성 함수
* [] 경로 탐색 함수
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "rbtree.h"
#include "graph.h"
#include "reservation.h"

/* Reservation 객체 초기화 */
void initReservation(Reservation* reservation) {
	static int idCount = 1; // reservation id 부여: 1부터 시작

	reservation->name = (char*)malloc(sizeof(char) * MAX_NAME);
	reservation->id = idCount++;
}

/* 유저 입력으로부터 예약 정보를 받아 Reservation 객체를 생성 */
Reservation* makeReservation(char* userInput) {
	Reservation* newReservation = (Reservation*)malloc(sizeof(Reservation));
	initReservation(newReservation);
	
	/* input을 "," 기준으로 나누어 Reservation 객체에 적절하게 저장 */
	newReservation->name = strtok(userInput, ",");
	newReservation->source = (strtok(NULL, ","))[0];
	newReservation->dest = (strtok(NULL, ","))[0];

	return newReservation;
}

/* Reservation id로 객체 트리에 저장 */
void registerReservation(RbTree* tree, int reservationID) {
	insertion(tree, reservationID);
}

/* 무작위로 연결된 도시를 생성 */
void makeCityGraph(Graph* graph) {
	int connectionCount;
	int randomNumber;

	srand(time(NULL));
	/* city별로 무작위로 10개의 연결을 생성 */
	for (int i = 0; i < CITY_NUM; i++) {
		connectionCount = getConnections(graph, i);

		/* 총 연결이 10개가 될 때까지 연결 생성 */
		while (connectionCount < 10) {
			randomNumber = rand() % 26;
			
			if (randomNumber != i && !isAlreadyConnected(graph, i, randomNumber)) {
				addEdge(graph, i, randomNumber);
				connectionCount += 1;
			}
		}
	}
}