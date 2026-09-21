#include "CancellationHistory.h"
#include <iostream>
using namespace std;

//constructor
CancellationHistory::CancellationHistory() {
    top = nullptr;
}

//destructor
CancellationHistory::~CancellationHistory() {
    while (!isEmpty()) {
        pop();
    }
}

//to check if stack is empty
bool CancellationHistory::isEmpty() const {
    return top == nullptr;  //if top is nullptr, stack is empty
}

//add to the top of the stack
void CancellationHistory::push(Reservation resToPush) {
    StackNode* newNode = new StackNode(resToPush);
    
    newNode->next = top;    //new node's next pointer points to second next
    
    top = newNode;  //top is now newnode
}

//function to remove the top item from the stack
Reservation CancellationHistory::pop() {
    if (isEmpty()) {
        cout << "Error: cancellation history stack is empty." << endl;
        return Reservation();
    }
    
    StackNode* temp = top;  //temp node for storing top
    Reservation resData = temp->data;   //get its reservaton data
    
    top = top->next;    //top is now next
    
    delete temp;    //no longer needed 
    return resData; //returns cancelled reservation's data
}

Reservation WaitingList::processNextWaitingStudent(string resourceID) {
    if (isEmpty()) {
        return Reservation();
    }

    WaitNode* current = front;
    WaitNode* previous = nullptr;

    while (current != nullptr) {
        if (current->data.getResourceID() == resourceID) {
            Reservation matchedRes = current->data;

            if (current == front) {
                front = front->next;
                if (front == nullptr) {
                    rear = nullptr;
                }
            } else {
                previous->next = current->next;
                if (current == rear) {
                    rear = previous;
                }
            }

            delete current;
            return matchedRes;
        }
        previous = current;
        current = current->next;
    }

    return Reservation(); // Return empty if no match found for this resource
}

// display function
void CancellationHistory::displayHistory() const {
    if (isEmpty()) {
        cout << "No cancellation history found." << endl;
    } else {
        cout << "--------------- Cancellation History -------------" << endl;
        StackNode* current = top;
        int position = 1;
        
        while (current != nullptr) {
            Reservation res = current->data;
            cout << position << ".\tCancelled Reservation ID: " << res.getReservationID()
                 << " - Student: " << res.getStudentName()
                 << " - Resource ID: " << res.getResourceID() << endl;
            current = current->next;
            position++;
        }
        
        cout << "--------------------------------------------------" << endl;
    }
}