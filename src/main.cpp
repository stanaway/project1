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
    resMgr.displayResources();

    Reservation r;
    resvMgr.createReservation(resMgr);

    // test queue & stack
    wl.enqueue(r);
    wl.displayWaitingList();

    ch.push(r);
    ch.pop();

    wl.processNextWaitingStudent("PC_01");

    return 0;
}