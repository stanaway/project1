//
// Created by emma on 10/11/26.
//

#ifndef RESERVATIONSEARCH_H
#define RESERVATIONSEARCH_H

#include <string>
#include <vector>
#include "Reservation.h"
#include "ReservationManager.h"

using namespace std;

class ReservationSearch {
public:

    //linear search, to find a single reservation by its reservation ID
    static Reservation* searchByReservationID(ReservationManager& resMgr, const string& reservationID);

    //linear search, to find all reservations for a student ID
    static vector<Reservation> searchByStudentID(ReservationManager& resMgr, string studentID);

    //linear search, to find all reservations for a given student name
    static vector<Reservation> searchByStudentName(ReservationManager& resMgr, string studentName);

    //creates a menu for collecting user input and displaying search output
    static void runSearchMenu(ReservationManager& resMgr);
    
};

#endif