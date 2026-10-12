#include <iostream>
#include <string>
#include <algorithm>
#include "ReservationSearch.h"
#include "ResourceManager.h"
#include "ReservationManager.h"
#include "WaitingList.h"
#include "CancellationHistory.h"

using namespace std;

//  function to print main menu
void printMenu() {
    cout << "\n===== Campus Resource Reservation System =====" << endl;
    cout << "1. View Resources" << endl;
    cout << "2. Create Reservation" << endl;
    cout << "3. Cancel Reservation" << endl;
    cout << "4. View Waiting Lists" << endl;
    cout << "5. Undo Cancellation" << endl;
    cout << "6. View Cancellation History" << endl;
    cout << "7. View Active Reservations" << endl;
    cout << "8. Search Reservations" << endl;   //new!
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    //  create objects
    ResourceManager resMgr;
    ReservationManager resvMgr;
    WaitingList wl;
    CancellationHistory ch;
    

    //  load data files
    resMgr.loadResources("data/resources.txt");
    resvMgr.loadReservations("data/reservations.txt");
    
    int choice = 0;

    //  main menu loop!
    while (choice != 9) {
        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: //view resources
                resMgr.displayResources();
                break;
            case 2: //create reservation
                resvMgr.createReservation(resMgr, wl);
                break;
            case 3: //cancel reservation
                resvMgr.cancelReservation(resMgr, wl, ch);
                break;
            case 4: //view waitinglists
                wl.displayWaitingList();
                break;
            case 5: {   //undo cancellation
                if (ch.isEmpty()) {
                    cout << "No cancellation hsitory available to undo."  << endl;
                } else {
                    Reservation restored = ch.pop();

                    //check if resource is free on that date
                    if (!resvMgr.checkAvailability(restored.getResourceID(), restored.getReservationDate()))    //if not free
                    {
                        cout << "Cannot undo cancellation: Resource " << restored.getResourceID() << " is already reserved on " << restored.getReservationDate() << "." << endl;
                        ch.push(restored);
                    }
                    else //if free, proceed
                    {
                        resvMgr.insertReservation(restored);

                        Resource* res = resMgr.findResource(restored.getResourceID());
                        if (res != nullptr) {
                            res->setAvailabilityStatus("Unavailable");
                        }
                        cout << "Restored reservation ID " << restored.getReservationID() << "." << endl;
                    }
                }
                break;
            }

            case 6: //view cancellation history
                ch.displayHistory();
                break;

            case 7: //view active reservations
                resvMgr.displayReservations();
                break;

            case 8: //search reservations
                ReservationSearch::runSearchMenu(resvMgr);
                break;

            case 9: //exit
                cout << "Goodbye! Exiting program..." << endl;
                break;

            default:    //default case
                cout << "Invalid selection. Please enter a number between 1 and 8." << endl;
                break;
        }

    }

    return 0;
}