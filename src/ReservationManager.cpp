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


ReservationManager::ReservationManager(){
    head = nullptr;

}

void ReservationManager::loadReservations(string reservationFile){
    ifstream inputFile(reservationFile);

    if(!inputFile.is_open()){
        cout << "Error opening the reservations.txt file." << endl;
        return;
    }

    string line;

    while(getline(inputFile, line)){
        string reservationID;
        string studentID;
        string studentName;
        string resourceID;
        string reservationDate;

        stringstream ss(line);

        getline(ss, reservationID, '|');
        getline(ss, studentID, '|');
        getline(ss, studentName, '|');
        getline(ss, resourceID, '|');
        getline(ss, reservationDate, '|');



        Reservation newReservation(reservationID, studentID, studentName, resourceID, reservationDate);

        insertReservation(newReservation);

    }

    inputFile.close();
}

void ReservationManager::displayReservations(){

    if(head == nullptr){ // checks if the LL is empty
        cout << "No active reservations." << endl;
        return;
    }

    ReservationNode* current = head;

    while(current != nullptr){
        cout << "Reservation ID: " << current->reservation.getReservationID() << endl;
        cout << "Student ID: " << current->reservation.getStudentID() << endl;
        cout << "Student Name: " << current->reservation.getStudentName() << endl;
        cout << "Resource ID: " << current->reservation.getResourceID() << endl;
        cout << "Resource Date: " << current->reservation.getReservationDate() << endl;
        cout << "----------------------------------------------------------------------" << endl;

        current = current->next;
    }

}

Reservation* ReservationManager::findReservation(string reservationID){

    ReservationNode* current = head;

    while(current != nullptr){// checks if the LL is empty
        if(current->reservation.getReservationID() == reservationID){ //checks if the current node's value matches the reservation ID that is inputted by the user
            return &(current->reservation); // if found, returns it
        }
        current = current->next; //goes to the next node
    }
    return nullptr; //if not found, returns a null pointer

}

bool ReservationManager::containsID(string reservationID){
    if(findReservation(reservationID) != nullptr){
        return true;
    }
    else{
        return false;
    }

}

bool ReservationManager::insertReservation(Reservation reservation){
    ReservationNode* newNode = new ReservationNode(reservation);

    if(head == nullptr){ //checks if the linked list is empty
        head = newNode;
        return true;
    }

    //if not, finds the last node
    ReservationNode* current = head;

    while(current->next != nullptr){
        current = current->next;
    }

    current->next = newNode; // adds and attaches a new node to the end

    return true;
}

bool ReservationManager::removeReservationByID(string reservationID, Reservation& removed){
    if(head == nullptr){
        return false;
    }

    if(head->reservation.getReservationID() == reservationID){
        ReservationNode* temp = head;

        removed = temp->reservation;

        head = head->next;
        delete temp;
        return true;
    }

    ReservationNode* current = head;
    while(current->next != nullptr){
        if(current->next->reservation.getReservationID() == reservationID){
            ReservationNode* temp = current->next;

            removed = temp->reservation; //saves the reservation before deleting the node

            current->next = temp->next; // skips over the node being removed

            delete temp;
            return true;
        }

        current = current->next;

    }

    return false; //if reservation is not found

}

bool ReservationManager::checkAvailability(string resourceID, string reservationDate){
    
    ReservationNode* current = head;

    while(current != nullptr){ // checks if the LL is empty
        
        if(current->reservation.getResourceID() == resourceID 
        && current->reservation.getReservationDate() == reservationDate){ 
           
            return false;
            
        }
        
        current = current->next;
    }
    
    return true;
    
}

void ReservationManager::createReservation(ResourceManager& resourceManager) {

    string reservationID, studentID, studentName, resourceID, reservationDate;

    cout << "Reservation ID: ";
    getline(cin, reservationID);

    // 1. Validate reservation ID
    if (containsID(reservationID)) {
        cout << "Error: reservation ID already exists." << endl;
        return;
    }

    cout << "Student ID: ";
    getline(cin, studentID);

    cout << "Student Name: ";
    getline(cin, studentName);

    cout << "Resource ID: ";
    getline(cin, resourceID);

    cout << "Reservation Date: ";
    getline(cin, reservationDate);

    // Validate resource ID
    Resource* resource = resourceManager.findResource(resourceID);
    

    if (resource == nullptr) {
        cout << "Error: resource ID does not exist." << endl;
        return;
    }

    //  Create a reservation object
    Reservation newReservation(reservationID, studentID, studentName, resourceID, reservationDate);

    //  Check availability
    if (!checkAvailability(resourceID, reservationDate)){

        cout << "Resource is unavailable on this date." << endl;
        
        waitingList.enqueue(newReservation);
        return;
    }

    //  Add reservation to linked list
    if (insertReservation(newReservation)) {

        //  Mark resource unavailable
        resource->setAvailabilityStatus("Unavailable");

        cout << "Reservation created successfully." << endl;

    } else {
        cout << "Error: could not create reservation." << endl;
    }
}

void ReservationManager::cancelReservation(ResourceManager& resourceManager,WaitingList &wl){
    string reservationID;

    cout << "Enter Reservation ID to cancel: ";
    getline(cin, reservationID);

    // 1. Find and remove reservation
    Reservation removedReservation;

    if (!removeReservationByID(reservationID, removedReservation)) {
        cout << "Error: active reservation not found.\n";
        return;
    }

    // 2. Save in cancellation history stack
    cancellationHistory.push(removedReservation);

    // 3. Find the resource
    Resource* resource = resourceManager.findResource(removedReservation.getResourceID());

    if (resource) {

        // 4. Make resource available
        resource->setAvailabilityStatus("Available");

        // 5. Check waiting list
        wl.processNextWaitingStudent(
            removedReservation.getResourceID()

        );
    }
    
    cout << "Reservation cancelled successfully." << endl;

}




