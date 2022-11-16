/**
* Functions about reservation system
* 
* 구현 기능:
* [x] 사용자 input 받아서 reservation 객체에 저장하는 함수
* [] output 출력 함수
* [] Flight path 찾는 함수
* [] 무작위 지형 생성 함수
* [] 경로 탐색 함수
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

/* 유저 입력으로부터 예약 정보를 받아 Reservation 객체를 생성 */
Reservation* makeReservation(char* userInput) {
	Reservation* newReservation = (Reservation*)malloc(sizeof(Reservation));
	initReservation(newReservation);
	
	/* input을 "," 기준으로 나누어 Reservation 객체에 적절하게 저장 */
	newReservation->name = strtok(userInput, ",");
	newReservation->source = (strtok(NULL, ","))[0];
	newReservation->dest = (strtok(NULL, ","))[0];
	newReservation->departureTime = atoi(strtok(NULL, ","));

	return newReservation;
}