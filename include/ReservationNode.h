#ifndef RESERVATIONNODE_H
#define RESERVATIONNODE_H

#include <vector>
#include <string>
#include "Reservation.h"

using namespace std;

class ReservationNode{
    public:
        Reservation reservation;
        ReservationNode* next;

        ReservationNode(Reservation reserv){
            reservation = reserv;
            next = nullptr;
        }
};


#endif
