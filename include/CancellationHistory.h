#ifndef CANCELLATION_HISTORY_H
#define CANCELLATION_HISTORY_H

#include "Reservation.h"
using namespace std;

struct StackNode {
    Reservation data;   //holds reservation data of student in this stack
    StackNode* next;    //points to next node in stack
    StackNode(Reservation res) : data(res), next(nullptr) {}    //struct constructor
};

class CancellationHistory {
private:
    StackNode* top;     //pointer for the top of the stack
public:
    CancellationHistory();  //constructor
    ~CancellationHistory(); //destructor
    
    bool isEmpty() const;   //checks if empty
    void push(Reservation resToPush);   //adds to top of staack
    Reservation pop();  //removes from top of stack
    void displayHistory() const;    //prints history
};

#endif