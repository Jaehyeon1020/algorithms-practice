#pragma once

typedef struct Reservation Reservation;

typedef struct Node
{
    struct Reservation* reservation;
    struct Node* next;
}reservationNode;

reservationNode* addData(reservationNode* node, Reservation* reservation);
reservationNode* search(reservationNode* node, int id);