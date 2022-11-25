#pragma warning(disable:4996)

#include <stdlib.h>
#include "linkedList.h"
#include "reservation.h"

void addData(reservationNode* node, Reservation* reservation)
{
    reservationNode* newNode = (reservationNode*)malloc(sizeof(reservationNode));
    newNode->reservation = reservation;
    newNode->next = NULL;

    reservationNode* currentNode = node;

    while (currentNode->next != NULL) {
        currentNode = currentNode->next;
    }

    currentNode->next = newNode;
    return;
}

reservationNode* search(reservationNode* node, int id)
{
    Reservation* reserve = node->reservation;

    if (node == NULL)
        return NULL;

    if (reserve->id == id)
        return node;

    return search(node->next, id);
}