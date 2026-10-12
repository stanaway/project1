
#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <vector>
#include <string>
#include "ResourceManager.h"
#include "Reservation.h"
#include "ReservationNode.h"
#include "WaitingList.h"
#include "CancellationHistory.h"

using namespace std;

class ReportGenerator;

class ReservationManager {
private:
    friend class ReportGenerator;

    ReservationNode* head;
    WaitingList waitingList;

public:
    ReservationManager();

    void loadReservations(string reservationFile);
    void displayReservations();

    Reservation* findReservation(string reservationID);
    bool containsID(string reservationID);

    bool insertReservation(Reservation reservation);
    bool removeReservationByID(string reservationID, Reservation& removed);

    bool checkAvailability(string resourceID, string reservationDate);

    void createReservation(ResourceManager& resourceManager);

    void cancelReservation(
        ResourceManager& resMgr,
        WaitingList& wl,
        CancellationHistory& ch
    );

    ReservationNode* getFirstNode() const {
        return head;
    }
};

#endif
