#include <iostream>
#include "ResourceManager.h"
#include "ReservationManager.h"
#include "WaitingList.h"
#include "CancellationHistory.h"

using namespace std;

int main() {
    ResourceManager resMgr;
    ReservationManager resvMgr;
    WaitingList wl;
    CancellationHistory ch;
    

    // test managers
    resMgr.loadResources("data/resources.txt");
    resvMgr.loadReservations("data/reservations.txt");
    
    resMgr.displayResources();
    resvMgr.displayReservations();

    resvMgr.createReservation(resMgr);
    Reservation r("RES_001", "987654", "Jane Smith", "R101", "2026-10-01");

    // test queue & stack
    wl.enqueue(r);
    wl.displayWaitingList();

    ch.push(r);
    ch.pop();

    wl.processNextWaitingStudent("R101");

    return 0;
}