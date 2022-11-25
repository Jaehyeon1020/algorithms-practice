#include <stdlib.h>
#include "linkedList.h"
#include "reservation.h"

reservationNode* addData(reservationNode* node, Reservation* reservation)
{
    if (node == NULL)
    {
        reservationNode* newNode = (reservationNode*)malloc(sizeof(reservationNode));
        newNode->reservation = reservation;
        newNode->next = NULL;

        return newNode;
    }

    node->next = addData(node->next, reservation);
    return node;
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