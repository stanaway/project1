
#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include "ReservationManager.h"
#include "ResourceManager.h"
#include "WaitingList.h"
#include <string>

using namespace std;

class ReportGenerator {
private:
    static int countActiveForResource(
        ReservationManager& rm,
        string resourceID
    );

    static int countWaitingForResource(
        WaitingList& wl,
        string resourceID
    );

public:
    static void displayActiveReservations(ReservationManager& rm);

    static void displayResourceUtilization(
        ReservationManager& rm,
        ResourceManager& resMgr
    );

    static void displayMostRequestedResources(
        ReservationManager& rm,
        ResourceManager& resMgr,
        WaitingList& wl
    );

    static void displayWaitingListStatistics(
        ResourceManager& resMgr,
        WaitingList& wl
    );

    static void displayAllReports(
        ReservationManager& rm,
        ResourceManager& resMgr,
        WaitingList& wl
    );
};

#endif
