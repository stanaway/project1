//
// Created by emma on 10/11/26.
//

#include "ReservationSearch.h"
#include <iostream>

using namespace std;

//  search by reservation id
Reservation* ReservationSearch::searchByReservationID(ReservationManager& resMgr, const string& reservationID)
{
    ReservationNode* current = resMgr.getFirstNode();

    while (current != nullptr)
    {
        if (current->reservation.getReservationID() == reservationID)
        {
            return &(current->reservation); //match is found, so return memory ptr
        }
        current = current->next;    //move to next node in linked list
    }

    return nullptr; //if no match found
}

//  search by student id
vector<Reservation> ReservationSearch::searchByStudentID(ReservationManager& resMgr, string studentID)
{
    vector<Reservation> matches;
    ReservationNode* current = resMgr.getFirstNode();

    while (current != nullptr)
    {
        if (current->reservation.getStudentID() == studentID)
        {
            matches.push_back(current->reservation);    //add to vector
        }
        current = current->next;
    }

    return matches; //returns the vector that has all matches found
}

//  search by student name
vector<Reservation> ReservationSearch::searchByStudentName(ReservationManager& resMgr, string studentName)
{
    vector<Reservation> matches;
    ReservationNode* current = resMgr.getFirstNode();
    while (current != nullptr)
    {
        if (current->reservation.getStudentName() == studentName)
        {
            matches.push_back(current->reservation);
        }
        current = current->next;
    }

    return matches;
}

//  search menu
void ReservationSearch::runSearchMenu(ReservationManager& resMgr)
{
    int choice = 0;
    cout << "\n====== Search Reservations ======" << endl;
    cout << "1. Search by Reservation ID" << endl;
    cout << "2. Search by Student ID" << endl;
    cout << "3. Search by Student Name" << endl;
    cout << "Enter choice: ";
    cin >> choice;
    cin.ignore();

    switch (choice){

    case 1: //search by reservation ID
    {
        string resID;
        cout << "Enter reservation ID: ";
        getline(cin, resID);

        Reservation* match = searchByReservationID(resMgr, resID);
        if (match != nullptr) //if reservation found, then:
        {
            cout << "\nReservation found!" << endl;
            cout << "Reservation ID: " << match->getReservationID() << endl;
            cout << "Student ID: " << match->getStudentID() << endl;
            cout << "Student Name: " << match->getStudentName() << endl;
            cout << "Resource ID: " << match->getResourceID() << endl;
            cout << "Date " << match->getReservationDate() << endl;
        }
        else
        {
            cout << "No reservation found with ID: " << resID << endl;
        }
        break;
    }

    case 2: //search by student id
    {
        string stuID;
        cout << "Enter student ID: ";
        getline(cin, stuID);
        vector<Reservation> matches = searchByStudentID(resMgr, stuID);
        if (matches.empty())
        {
            cout << "No reservations found for Student ID: " << stuID << endl;
        }
        else
        {
            cout << "\nFound " << matches.size() << " reservation(s):" << endl;
            for (int i = 0; i < matches.size(); ++i)
            {
                cout << "- ID: " << matches[i].getReservationID()
                << " | Resource: " << matches[i].getResourceID()
                << " | Date: " << matches[i].getReservationDate() << endl;
            }
        }
        break;
    }

    case 3: //search by student name
    {
        string name;
        cout << "Enter student name: ";
        getline(cin, name);

        vector<Reservation> matches = searchByStudentName(resMgr, name);
        if (matches.empty())
        {
            cout << "No reservations found for student: " << name << endl;
        }
        else
        {
            cout << "\nFound " << matches.size() << " reservation(s):" << endl;
            for (int i = 0; i < matches.size(); ++i)
            {
                cout << "- ID: " << matches[i].getReservationID()
                << " | Resource: " << matches[i].getResourceID()
                << " | Date: " << matches[i].getReservationDate() << endl;
            }
        }
        break;
    }

    default:
        cout << "Invalid search option."  << endl;
        break;
    }
}