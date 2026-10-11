#include <iostream>
#include <string>
#include <algorithm>
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
    cout << "8. Exit" << endl;
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
    while (choice != 8) {
        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                resMgr.displayResources();
                break;
            case 2:
                resvMgr.createReservation(resMgr, wl);
                break;
            case 3:
                resvMgr.cancelReservation(resMgr, wl, ch);
                break;
            case 4:
                wl.displayWaitingList();
                break;
            case 5: {
                if (ch.isEmpty()) {
                    cout << "No cancellation hsitory available to undo."  << endl;
                } else {
                    Reservation restored = ch.pop();
                    resvMgr.insertReservation(restored);

                    Resource* res = resMgr.findResource(restored.getResourceID());
                    if (res != nullptr) {
                        res->setAvailabilityStatus("Unavailable");
                    }
                    cout << "Restored reservation ID " << restored.getReservationID() << "." << endl;
                }
                break;
            }

            case 6:
                ch.displayHistory();
                break;

            case 7:
                resvMgr.displayReservations();
                break;

            case 8:
                cout << "Goodbye! Exiting program..." << endl;
                break;

            default:
                cout << "Invalid selection. Please enter a number between 1 and 8." << endl;
                break;
        }

    }

    return 0;
}