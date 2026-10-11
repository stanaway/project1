#ifndef RESERVATIONMANAGER_H
#define RESERVATIONMANAGER_H

#include <vector>
#include <string>
#include "ReservationManager.h"
#include "ResourceManager.h"
#include "Reservation.h"
#include "ResourceManager.h"
#include "ReservationNode.h"
#include "WaitingList.h"
#include "CancellationHistory.h"

using namespace std;


class ReservationManager{
    private:
        ReservationNode* head;
        //CancellationHistory cancellationHistory; //obsolete because of ch in main is now passed by reference
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
        
        void createReservation(ResourceManager& resourceManager, WaitingList& wl);
        void cancelReservation(ResourceManager &resMgr, WaitingList &wl, CancellationHistory &ch);

        ReservationNode* getFirstNode() const { return head; }  //needed for reeservationsearch class -emma

};




#endif
