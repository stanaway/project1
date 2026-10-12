
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
#include <cctype>

using namespace std;

bool isBlank(string text){
    for(char c : text){
        if(!isspace(static_cast<unsigned char>(c))){ // checks each character to see if it is a space
            return false;
        }
    }
    return true;
}

//-----------------------------------
/*
since dates in the source files are MM/DD/YYYY, the length of the entered date has to be 10 and we 
have to check if the 2nd and the 5th characters are '/'
*/
bool isValidDate(string date){
    if(date.length() != 10 || date[2] != '/' || date[5] != '/'){ 
        return false;
    }

    for(int i = 0; i < 10; i++){
        
        if(i == 2 || i == 5){
            continue;
        }
        
        if(!isdigit(static_cast<unsigned char>(date[i]))){
            return false;
        }
    }
    // extracts the months, days, and years from the data and converts them to integers
    int month = stoi(date.substr(0,2));
    int day = stoi(date.substr(3,2));
    int year = stoi(date.substr(6,4));


    // checks if the year and the month are valid
    if(year < 1 || month < 1 || month > 12){
        return false;
    }

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    // checks if the year on the date is a leap year
    bool leapYear = false;

    if(year % 400 == 0){
        leapYear = true;
    }
    else if(year % 100 == 0){
        leapYear = false;
    }
    else if(year % 4 == 0){
        leapYear = true;
    }
    //-----------------------------
    //if the year is a leap year, February (daysInMonth[1]) is assigned to have 29 days
    if(leapYear){
        daysInMonth[1] = 29;
    }
    //-----------------------------
    //checks if the date is valid
    if(day >= 1 && day <= daysInMonth[month - 1]){
        return true;
    }
    else{
        return false;
    }
    

}


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
Reservation* ReservationManager::findReservation(string reservationID) {
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

    if(!checkAvailability(reservation.getResourceID(), reservation.getReservationDate())){
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
bool ReservationManager::removeReservationByID(string reservationID, Reservation& removed
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
    ResourceManager& resourceManager,
    WaitingList& wl
) {
    string reservationID;
    string studentID;
    string studentName;
    string resourceID;
    string reservationDate;

    cout << "Reservation ID: ";
    getline(cin, reservationID);

    if (isBlank(reservationID)) {
        cout << "Error: reservation ID cannot be blank." << endl;
        return;
    }

    if (containsID(reservationID) || wl.containsID(reservationID)) {
        cout << "Error: reservation ID already exists." << endl;
        return;
    }

    cout << "Student ID: ";
    getline(cin, studentID);

    if (isBlank(studentID)) {
        cout << "Error: student ID cannot be blank." << endl;
        return;
    }

    cout << "Student Name: ";
    getline(cin, studentName);

    if (isBlank(studentName)) {
        cout << "Error: student name cannot be blank." << endl;
        return;
    }

    cout << "Resource ID: ";
    getline(cin, resourceID);

    if (isBlank(resourceID)) {
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

    if (!isValidDate(reservationDate)) {
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
        updateResourceStatus(resourceManager, resourceID);

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

    if (isBlank(reservationID)) {
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
                updateResourceStatus(resourceManager, resourceID);

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

void ReservationManager::updateResourceStatus(ResourceManager& resourceManager, string resourceID){
    Resource* resource = resourceManager.findResource(resourceID);

    if(resource == nullptr){
        return;
    }

    ReservationNode* current = head;

    while(current != nullptr){
        if(current->reservation.getResourceID() == resourceID){
            resource->setAvailabilityStatus("Unavailable");
            return;
        }
        current = current->next;
    }

    resource->setAvailabilityStatus("Available");
}
