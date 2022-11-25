#pragma once

#include "reservation.h"

typedef struct Node
{
    Reservation* reservation;
    struct Node* next;
}reservationNode;

reservationNode* addData(reservationNode* node, Reservation* reservation);
reservationNode* search(reservationNode* node, int id);