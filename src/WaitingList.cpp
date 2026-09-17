#include "WaitingList.h"
#include <iostream>
using namespace std;

//constructor, initializes two WaitNode pointers to nullptr 
WaitingList::WaitingList(){
    front = nullptr;
    rear = nullptr;
}

//destructor, dequeues each node until queue is empty 
WaitingList::~WaitingList() {
    while (!isEmpty()) {
        dequeue(); //this deletes the what is being dequeued
    }
}

bool WaitingList::isEmpty() const{
    return front == nullptr;    //if front is nullptr loop is empty
}

void WaitingList::enqueue(Reservation resToQueue){
    WaitNode* newNode = new WaitNode(resToQueue);

    if (isEmpty()) {    //if queue is empty, then new node will be both front and back
        front = newNode; 
        rear = newNode;
    } 
    else {
        rear->next = newNode;   //makes rear's next pointer point to new node
        rear = newNode;         //updates rear
    }
    
    cout << "Added student " << resToQueue.getStudentName() << " to the waiting list." << endl;
}

Reservation WaitingList::dequeue(){
    if (isEmpty() ){    //check if impty first to avoid crashing
        cout << "Error: waiting queue is empty." << endl;
        return Reservation();   //return empty reservation
    }
    else {
        WaitNode* temp = front; //new waitnode pointer that is the same as front of queue
        Reservation resData = temp->data;   //for returning once dequeue is completed

        front = front->next;    //front of queue is now what used to be next node
        if (front == nullptr){  //if front is nullptr that means loop is done, so reset nullptr too
            rear = nullptr;
        }

        delete temp;        //deletes node being dequeued
        return resData;     //returns the reservation data for node in front of queue
    }
}

//function to display waiting list: it iterates through the queue and 
void WaitingList::displayWaitingList(){
    if(isEmpty()){
        cout << "The waiting list is currently empty." << endl;
    }
    else {
        cout << "\n---------- Current Waiting List ----------" << endl;
    
        WaitNode* current = front;  //waitnode pointer for while loop, will start at front of queue
        int position = 1;

        while (current != nullptr){
            Reservation res = current->data; //using the current node's data
            cout << position << ".\tStudent name: " << res.getStudentName()
            << " - Student ID: " << res.getStudentID()
            << " - Resource ID: " << res.getResourceID()
            << " - Reservation Date: " << res.getReservationDate() << endl;
            current = current->next;    //iterate to next node in queue
            position++;
        }

        cout << "------------------------------------------" << endl;
    }
}

/*  FROM PLAN DOCUMENT: 
    Create a “Waiting List” Queue
    Detect the availability of resources
        If resource is available => create reservation
        If not => waiting lists
    Add the student to the queue
        Make sure they give all the necessary information
    Keep the FIFO order
    Display the waiting list
        Add a “View Waiting Lists” function to the menu
            User should be able to see who is waiting for each resource
    Process the queue when the resource becomes available
        When a resource becomes available
            Check its waiting queue
            If nobody is waiting => leave it available
            If someone is waiting => process the person at the front (FIFO)
*/