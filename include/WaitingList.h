#ifndef WAITING_LIST_H
#define WAITING_LIST_H

#include "Reservation.h"
using namespace std;

struct WaitNode {
    Reservation data;   //holds reservation data of student at this node
    WaitNode* next;     //points to next node in queue
    WaitNode(Reservation res) : data(res), next(nullptr) {} //struct constructor 
};

class WaitingList {
private:
    WaitNode* front;    //pointer to front of queue
    WaitNode* rear;     //pointer to rear of queue
public:
    WaitingList();  //constructor
    ~WaitingList();  //destructor
    bool isEmpty() const;   //returns true if queue is empty
    void enqueue(Reservation resToQueue);   //adds to end of queue
    Reservation dequeue();  //removes first from queue
    Reservation processNextWaitingStudent(string resourceID);   //processes next
    void displayWaitingList();  //prints entire queue
};

#endif