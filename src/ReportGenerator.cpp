
#include "ReportGenerator.h"

#include <iostream>
#include <string>

using namespace std;

// Count active reservations for one resource.
int ReportGenerator::countActiveForResource(
    ReservationManager& rm,
    string resourceID
) {
    int count = 0;
    ReservationNode* current = rm.head;

    while (current != nullptr) {
        if (current->reservation.getResourceID() == resourceID) {
            count++;
        }
        current = current->next;
    }

    return count;
}

// Count waiting requests for one resource.
int ReportGenerator::countWaitingForResource(
    WaitingList& wl,
    string resourceID
) {
    int count = 0;
    WaitNode* current = wl.front;

    while (current != nullptr) {
        if (current->data.getResourceID() == resourceID) {
            count++;
        }
        current = current->next;
    }

    return count;
}

// Report 1: Active reservations.
void ReportGenerator::displayActiveReservations(
    ReservationManager& rm
) {
    cout << "\n========== Active Reservations ==========\n";

    ReservationNode* current = rm.head;

    if (current == nullptr) {
        cout << "No active reservations.\n";
        return;
    }

    while (current != nullptr) {
        Reservation res = current->reservation;

        cout << "Reservation ID: "
             << res.getReservationID() << '\n';
        cout << "Student ID: "
             << res.getStudentID() << '\n';
        cout << "Student Name: "
             << res.getStudentName() << '\n';
        cout << "Resource ID: "
             << res.getResourceID() << '\n';
        cout << "Reservation Date: "
             << res.getReservationDate() << '\n';
        cout << "----------------------------------------\n";

        current = current->next;
    }
}

// Report 2: Resource utilization.
void ReportGenerator::displayResourceUtilization(
    ReservationManager& rm,
    ResourceManager& resMgr
) {
    cout << "\n========== Resource Utilization ==========\n";

    for (size_t i = 0; i < resMgr.resources.size(); i++) {
        Resource res = resMgr.resources[i];

        int count = countActiveForResource(
            rm, res.getResourceID()
        );

        cout << "Resource ID: " << res.getResourceID()
             << " | Name: " << res.getResourceName()
             << " | Active Reservations: " << count << '\n';
    }
}

// Report 3: Most requested resources.
// Requests include active reservations and waiting requests.
void ReportGenerator::displayMostRequestedResources(
    ReservationManager& rm,
    ResourceManager& resMgr,
    WaitingList& wl
) {
    cout << "\n========== Most Requested Resources ==========\n";

    if (resMgr.resources.empty()) {
        cout << "No resources available.\n";
        return;
    }

    int highestCount = 0;

    // Find the highest number of requests.
    for (size_t i = 0; i < resMgr.resources.size(); i++) {
        string id = resMgr.resources[i].getResourceID();

        int total = countActiveForResource(rm, id)
                  + countWaitingForResource(wl, id);

        if (total > highestCount) {
            highestCount = total;
        }
    }

    if (highestCount == 0) {
        cout << "No resource requests found.\n";
        return;
    }

    // Display every resource tied for the highest count.
    for (size_t i = 0; i < resMgr.resources.size(); i++) {
        Resource res = resMgr.resources[i];

        int total = countActiveForResource(rm, res.getResourceID())
                  + countWaitingForResource(wl, res.getResourceID());

        if (total == highestCount) {
            cout << "Resource: " << res.getResourceName()
                 << " (" << res.getResourceID() << ")"
                 << " | Total Requests: " << total << '\n';
        }
    }
}

// Report 4: Waiting-list statistics.
void ReportGenerator::displayWaitingListStatistics(
    ResourceManager& resMgr,
    WaitingList& wl
) {
    cout << "\n========== Waiting-List Statistics ==========\n";

    int totalWaiting = 0;

    for (size_t i = 0; i < resMgr.resources.size(); i++) {
        Resource res = resMgr.resources[i];

        int count = countWaitingForResource(
            wl, res.getResourceID()
        );

        cout << "Resource: " << res.getResourceName()
             << " (" << res.getResourceID() << ")"
             << " | Students Waiting: " << count << '\n';

        totalWaiting += count;
    }

    cout << "Total students waiting: " << totalWaiting << '\n';
}

// Display all four reports.
void ReportGenerator::displayAllReports(
    ReservationManager& rm,
    ResourceManager& resMgr,
    WaitingList& wl
) {
    displayActiveReservations(rm);
    displayResourceUtilization(rm, resMgr);
    displayMostRequestedResources(rm, resMgr, wl);
    displayWaitingListStatistics(resMgr, wl);
}
