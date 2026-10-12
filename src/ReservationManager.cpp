
#include "ReservationManager.h"
#include "Reservation.h"
#include "ResourceManager.h"
#include "ReservationNode.h"
#include "WaitingList.h"
#include "CancellationHistory.h"

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

// Constructor
ReservationManager::ReservationManager() {
    head = nullptr;
}

// Load reservations from a file
void ReservationManager::loadReservations(string reservationFile) {
    ifstream inputFile(reservationFile);

    if (!inputFile.is_open()) {
        cout << "Error opening the reservations file." << endl;
        return;
    }

    string line;

    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        string reservationID;
        string studentID;
        string studentName;
        string resourceID;
        string reservationDate;

        stringstream ss(line);

        if (!getline(ss, reservationID, '|') ||
            !getline(ss, studentID, '|') ||
            !getline(ss, studentName, '|') ||
            !getline(ss, resourceID, '|') ||
            !getline(ss, reservationDate)) {

            cout << "Skipping invalid reservation record." << endl;
            continue;
        }

        // Remove carriage return from Windows-formatted files
        if (!reservationDate.empty() &&
            reservationDate.back() == '\r') {
            reservationDate.pop_back();
        }

        // Prevent duplicate active reservation IDs
        if (containsID(reservationID)) {
            cout << "Skipping duplicate reservation ID: "
                 << reservationID << endl;
            continue;
        }

        Reservation newReservation(
            reservationID,
            studentID,
            studentName,
            resourceID,
            reservationDate
        );

        insertReservation(newReservation);
    }

    inputFile.close();
}

// Display all active reservations
void ReservationManager::displayReservations() {
    if (head == nullptr) {
        cout << "No active reservations." << endl;
        return;
    }

    ReservationNode* current = head;

    while (current != nullptr) {
        cout << "Reservation ID: "
             << current->reservation.getReservationID() << endl;

        cout << "Student ID: "
             << current->reservation.getStudentID() << endl;

        cout << "Student Name: "
             << current->reservation.getStudentName() << endl;

        cout << "Resource ID: "
             << current->reservation.getResourceID() << endl;

        cout << "Reservation Date: "
             << current->reservation.getReservationDate() << endl;

        cout << "----------------------------------------" << endl;

        current = current->next;
    }
}

// Find an active reservation by ID
Reservation* ReservationManager::findReservation(
    string reservationID
) {
    ReservationNode* current = head;

    while (current != nullptr) {
        if (current->reservation.getReservationID() == reservationID) {
            return &(current->reservation);
        }

        current = current->next;
    }

    return nullptr;
}

// Check whether an active reservation has this ID
bool ReservationManager::containsID(string reservationID) {
    return findReservation(reservationID) != nullptr;
}

// Insert a reservation at the end of the linked list
bool ReservationManager::insertReservation(Reservation reservation) {
    if (containsID(reservation.getReservationID())) {
        return false;
    }

    ReservationNode* newNode = new ReservationNode(reservation);

    if (head == nullptr) {
        head = newNode;
        return true;
    }

    ReservationNode* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;

    return true;
}

// Remove a reservation by ID
bool ReservationManager::removeReservationByID(
    string reservationID,
    Reservation& removed
) {
    if (head == nullptr) {
        return false;
    }

    // Remove the head node
    if (head->reservation.getReservationID() == reservationID) {
        ReservationNode* temp = head;

        removed = temp->reservation;
        head = head->next;

        delete temp;
        return true;
    }

    // Search for the node after the current node
    ReservationNode* current = head;

    while (current->next != nullptr) {
        if (current->next->reservation.getReservationID()
            == reservationID) {

            ReservationNode* temp = current->next;

            removed = temp->reservation;
            current->next = temp->next;

            delete temp;
            return true;
        }

        current = current->next;
    }

    return false;
}

// Check availability for a resource on a specific date
bool ReservationManager::checkAvailability(
    string resourceID,
    string reservationDate
) {
    ReservationNode* current = head;

    while (current != nullptr) {
        if (current->reservation.getResourceID() == resourceID &&
            current->reservation.getReservationDate() == reservationDate) {
            return false;
        }

        current = current->next;
    }

    return true;
}

// Create a reservation

void ReservationManager::createReservation(
    ResourceManager& resourceManager
) 

{
    WaitingList& wl = waitingList;

    string reservationID;
    string studentID;
    string studentName;
    string resourceID;
    string reservationDate;

    cout << "Reservation ID: ";
    getline(cin, reservationID);

    if (reservationID.empty()) {
        cout << "Error: reservation ID cannot be blank." << endl;
        return;
    }

    if (containsID(reservationID)) {
        cout << "Error: reservation ID already exists." << endl;
        return;
    }

    cout << "Student ID: ";
    getline(cin, studentID);

    if (studentID.empty()) {
        cout << "Error: student ID cannot be blank." << endl;
        return;
    }

    cout << "Student Name: ";
    getline(cin, studentName);

    if (studentName.empty()) {
        cout << "Error: student name cannot be blank." << endl;
        return;
    }

    cout << "Resource ID: ";
    getline(cin, resourceID);

    if (resourceID.empty()) {
        cout << "Error: resource ID cannot be blank." << endl;
        return;
    }

    Resource* resource = resourceManager.findResource(resourceID);

    if (resource == nullptr) {
        cout << "Error: resource ID does not exist." << endl;
        return;
    }

    cout << "Reservation Date: ";
    getline(cin, reservationDate);

    if (reservationDate.empty()) {
        cout << "Error: reservation date cannot be blank." << endl;
        return;
    }

    Reservation newReservation(
        reservationID,
        studentID,
        studentName,
        resourceID,
        reservationDate
    );

    // Check whether the resource is already reserved on this date
    if (!checkAvailability(resourceID, reservationDate)) {
        wl.enqueue(newReservation);

        cout << "Resource is unavailable on this date. "
             << "Student added to the waiting list." << endl;
        return;
    }

    if (insertReservation(newReservation)) {
        resource->setAvailabilityStatus("Unavailable");

        cout << "Reservation created successfully." << endl;
    } else {
        cout << "Error: could not create reservation." << endl;
    }
}

// Cancel an active reservation
void ReservationManager::cancelReservation(
    ResourceManager& resourceManager,
    WaitingList& wl,
    CancellationHistory& ch
) {
    string reservationID;

    cout << "Enter Reservation ID to cancel: ";
    getline(cin, reservationID);

    if (reservationID.empty()) {
        cout << "Error: reservation ID cannot be blank." << endl;
        return;
    }

    Reservation removedReservation;

    if (!removeReservationByID(reservationID, removedReservation)) {
        cout << "Error: active reservation not found." << endl;
        return;
    }

    // Save the cancelled reservation in the cancellation history stack
    ch.push(removedReservation);

    string resourceID = removedReservation.getResourceID();

    Resource* resource = resourceManager.findResource(resourceID);

    if (resource != nullptr) {
        // Find the next waiting student for this resource
        Reservation nextReservation =
            wl.processNextWaitingStudent(resourceID, removedReservation.getReservationDate());

        if (!nextReservation.getReservationID().empty()) {
            if (insertReservation(nextReservation)) {
                resource->setAvailabilityStatus("Unavailable");

                cout << "Waiting student "
                     << nextReservation.getStudentName()
                     << " has been promoted to an active reservation."
                     << endl;
            } else {
                // Return the request to the queue if insertion fails
                wl.enqueue(nextReservation);

                cout << "Error: promotion failed. "
                     << "The request was returned to the waiting list."
                     << endl;
            }
        } else {
            // No waiting student was found for this resource.
            // Check whether another active reservation still uses it.
            bool stillReserved = false;

            ReservationNode* current = head;

            while (current != nullptr) {
                if (current->reservation.getResourceID() == resourceID) {
                    stillReserved = true;
                    break;
                }

                current = current->next;
            }

            if (stillReserved) {
                resource->setAvailabilityStatus("Unavailable");
            } else {
                resource->setAvailabilityStatus("Available");
            }
        }
    }

    cout << "Reservation cancelled successfully." << endl;
}
