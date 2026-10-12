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
Zeynep Cansu:
    - Developed the Resource and Reservation Systems using vectors and linked lists.
    - Implemented file loading, searching, displaying, and reservation management.
    - Added duplicate ID checks, input validation, and date-specific availability checking.
    - Implemented Quick Sort to sort resources alphabetically by name.
    - Fixed bugs and improved functionality of the reservation system.
    - Collaborated with team members through GitHub by committing changes, merging code, and fixing integration problems.
Emma Stanaway:
    - Developed main.cpp to implement interactive program menu, handle user input, and call all required functions from respective objects and classes.
    - Developed the ReservationSearch class (uses linear search).
    - Developed the WaitingList class (uses queue).
    - Developed the CancellationHistory class (uses stack).
    - Tested program extensively to ensure smooth and bug-free user experience.
    - Fixed miscellaneous bugs.
    - Set up our team’s GitHub repository.
    - Collaborated with team members through GitHub by committing changes, merging code, and fixing integration problems.
Gabriela Magana:
    - Implemented createReservation() and cancelReservation() in ReservationManager.cpp
    - Added reservation validation, resource availability checks, and reservation creation and cancellation functionality.
    - Integrated cancellation history and resource availability updates when reservations are canceled.
    - Tested and debugged reservation management functions.
    - Collaborated with team members through GitHub by committing changes, merging code, and fixing integration problems.