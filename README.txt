Campus Resource Reservation System - Emma Stanaway, Gabriela Magana, Zeynep Cansu
=================================================================================

Description
---------------------------------------------------------------------------------
This program is a C++ program that allows students to reserve campus resources such as study rooms, laptops, calculators, lab equipment, and tutoring appointments. The program manages resources, active reservations, waiting lists, and cancellation history using different data structures.


Features
---------------------------------------------------------------------------------
Resource management:
    Viewing campus resources
    Checking resource availability by resource ID and reservation date
Reservation operations:
    Viewing active reservations
    Creating a new reservation
    Cancelling an existing reservation
Waiting list and cancellation history:
    Viewing cancellation history
    Adding students to a waiting list when a resource is unavailable
    Processing students from the waiting list
    Undo a cancelled reservation
Searching and generating reports:
    Searching reservations
    Generating reports


Project Files
---------------------------------------------------------------------------------
project1/
    data/
        Reservations.txt - Sample reservations list from Canvas
        Resources.txt - Sample resources list from Canvas
    include/
        CancellationHistory.h - header file for CancellationHistory class
        ReportGenerator.h - header file for ReportGenerator class
        Reservation.h - header file for Reservation class
        ReservationManager.h - header file for ReservationManager class
        ReservationNode.h - header file for ReservationNode class
        ReservationSearch.h - header file for ReservationSearch class
        Resource.h - header file for Resource class
        ResourceManager.h - header file for ResourceManager class
        WaitingList.h - header file for WaitingList class
    src/
        CancellationHistory.cpp - Handles cancellation history objects and their push, pop, and display functions
        main.cpp - Main program file, has menu and handles user input, calls all needed functions from objects and their respective classes
            ReportGenerator.cpp - Implements statistics about reservations, resource utilization, and the waiting list.
        Reservation.cpp - Defines reservation information
        ReservationManager.cpp - Handles reservation creation, cancellation, and
        availability checking
        ReservationNode.cpp - Defines the nodes for the reservation linked list.
        ReservationSearch.cpp - Supports searching reservations by reservation ID, student ID, or student name
        Resource.cpp - Displays the menu and connects the program’s features
        ResourceManager.cpp - Loads, displays, searches, and sorts resources using quick sort
        WaitingList.cpp - Handles waiting list objects and their enqueue, dequeue, process next waiting student, and display functions
    CMakeLists.txt - Necessary for using CMake in an IDE to build this program
    githuburl.txt - URL to this repository to meet Canvas requirements
    README.txt - this readme document


How to Compile
---------------------------------------------------------------------------------
Compile the program using g++:
    g++ -Iinclude src/*.cpp


How to Run
---------------------------------------------------------------------------------
After compiling, run the command:
    ./a.out


Resource File Format
---------------------------------------------------------------------------------
Resources are stored in the following format:
    ResourceID|ResourceName|ResourceType|AvailabilityStatus

Example:
    R101|Study Room 101|Study Room|Available


Reservation File Format
---------------------------------------------------------------------------------
Reservations are stored in the following format:
    ReservationID|StudentID|StudentName|ResourceID|ReservationDate

Example:
    301|1001|Alice Smith|R101|09/15/2026


Team Contributions
---------------------------------------------------------------------------------
