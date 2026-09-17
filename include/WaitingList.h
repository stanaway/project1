#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include "Reservation.h"
using namespace std;

struct WaitNode {
    Reservation data;  // Data of the student in the waiting list
    WaitNode* next;    // Pointer to the next node in the queue
    WaitNode(Reservation res) : data(res), next(nullptr) {}
};

class WaitingList {
private:
    WaitNode* front;
    WaitNode* rear;
public:
    WaitingList();  // Constructor for WaitingList class
    ~WaitingList();  // Destructor for WaitingList class
    bool isEmpty() const;
    void enqueue(Reservation resToQueue);    // Function to add a student to the waiting list queue
    Reservation dequeue();  // Function to remove a student from the waiting list queue
    void displayWaitingList();  // Function to print out the waiting list queue
};

#endif