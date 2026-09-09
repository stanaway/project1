Project 1: Campus Resource Reservation System
Project Overview

Universities manage a variety of resources every day, including study rooms, tutoring appointments, laptops, calculators, and laboratory equipment. Students frequently request access to these resources, and administrators must efficiently manage reservations, waiting lists, cancellations, and usage reports.

In this project, your team will develop a Campus Resource Reservation System that allows users to reserve campus resources, manage waiting lists, track reservation history, and generate reports.

The goal of this project is to apply object-oriented programming and fundamental data structures to solve a realistic problem.
Learning Objectives

Upon completion of this project, students will be able to:

    Design and implement a moderately sized C++ software system.
    Apply object-oriented programming principles.
    Read and write structured data files.
    Implement and use linked lists.
    Implement and use stacks.
    Implement and use queues.
    Analyze algorithm efficiency.
    Implement searching algorithms.
    Implement sorting algorithms.
    Collaborate using GitHub.
    Develop modular and maintainable code.

Functional Requirements
Resource Management

The system shall:

    Load resource data from input files.
    Store information about available resources.
    Display all resources.
    Search for resources.
    Sort resources according to user-selected criteria.

Resources may include:

    Study Rooms
    Laptops
    Calculators
    Lab Equipment
    Tutoring appointments

Each resource must contain:

    Resource ID
    Resource Name
    Resource Type
    Availability Status

Reservation Management

Users shall be able to:

    Create a reservation.
    Cancel a reservation.
    View current reservations.
    Search for reservations.

Each reservation must contain:

    Reservation ID
    Student ID
    Student Name
    Resource ID
    Reservation Date

Waiting List Management

When a resource is unavailable:

    Student requests must be placed in a waiting queue.
    Requests must be processed in FIFO order.
    Available resources must automatically be assigned to the next waiting user.

Reservation History

The system shall maintain a cancellation history.

When a reservation is cancelled:

    It is stored on a stack.
    Users may undo the most recent cancellation.

Only the most recently cancelled reservation may be restored.
Reporting

The system shall generate reports including:

    Most frequently reserved resources
    Current availability
    Number of active reservations
    Waiting list reports

Non-Functional Requirements
Code Organization

    Separate implementation and header files.
    Main function must be in its own source file.
    Use meaningful file and class names.

Documentation

    Source code must contain comments.
    README file required.
    Function-level documentation encouraged.

User Interface

Menu-driven command-line interface.

Example:

===== Campus Resource Reservation System =====

    View Resources
    Create Reservation
    Cancel Reservation
    View Waiting Lists
    Undo Cancellation
    Search Reservations
    Sort Resources
    Generate Report
    Exit

Enter Choice:

Required Data Structures
Linked List

Used For:

    Active reservation storage

Why Appropriate:

    Frequent insertions and deletions
    Dynamic size

Queue

Used For:

    Resource waiting lists

Why Appropriate:

    First Come, First Served processing

Stack

Used For:

    Cancellation history
    Undo functionality

Why Appropriate:

    Last In, First Out behavior

Vector

Used For:

    Resource inventory

Why Appropriate:

    Fast traversal and sorting support

Required Algorithms
Searching

Students must implement:

    Linear Search OR
    Binary Search

Applications:

    Finding a resource by ID
    Finding a reservation by ID
    Finding reservations associated with a specific student

Sorting

Students must implement at least one efficient sorting algorithm:

    Merge Sort OR
    Quick Sort

Applications:

    Resource reports
    Reservation reports

Suggested Object-Oriented Design
Classes
Resource

Stores information about campus resources.
Reservation

Stores reservation information.
Student

Stores student data.
ReservationManager

Handles reservation operations.
WaitingList

Manages queue operations.
CancellationHistory

Manages stack operations.
ReportGenerator

Creates reports and statistics.
File Organization

Project1/

│

├── include/

│ ├── Resource.h

│ ├── Reservation.h

│ ├── ReservationManager.h

│

├── src/

│ ├── main.cpp

│ ├── Resource.cpp

│ ├── Reservation.cpp

│ └── ReservationManager.cpp

│

├── data/

│ ├── resources.txt

│ └── reservations.txt

│

├── README.txt

└── .gitignore

 
Error Handling

The system must:

    Validate all menu selections.
    Validate file opening.
    Prevent duplicate reservation IDs.
    Prevent invalid resource IDs.
    Handle empty stacks.
    Handle empty waiting queues.

Sample Execution
Create Reservation

Student ID: 1001

Student Name: Alice Smith

Resource ID: R205

Reservation Created Successfully.

Cancel Reservation

Reservation ID: 301

Reservation Cancelled.

Added to cancellation history.

Undo Cancellation

Reservation Restored Successfully.

GitHub Requirements

All teams must:

    Create a GitHub repository.
    Have all members contribute commits.
    Use meaningful commit messages.
    Create at least one feature branch.
    Merge at least one branch into main.

Examples of acceptable commit messages:

Implemented reservation linked list

Added waiting queue functionality

Fixed resource search bug
Milestone 1 – Core System Development (Due on 9/20)
Objectives

Develop the core functionality of the Campus Resource Reservation System and establish the team's collaboration workflow.

By the end of this milestone, the system should support resource management, reservations, waiting lists, cancellation tracking, and team collaboration through GitHub.

Required Features
Resource Management

The system shall:

    Load resource information from a file.
    Store resource information.
    Display all resources.
    Display resource availability.

Reservation Management

The system shall:

    Create reservations.
    Cancel reservations.
    Display active reservations.
    Validate reservation requests.

Linked List Implementation

A linked list must be used to store active reservations.

The implementation must support:

    Insert reservation
    Remove reservation
    Traverse reservation records
    Display reservation information

Waiting List Management

A queue must be used for waiting lists.

The implementation must support:

    Add student to waiting list
    Remove student from waiting list
    Display waiting list

Cancellation History

A stack must be used for cancellation tracking.

The implementation must support:

    Store cancelled reservations
    Restore the most recently cancelled reservation
    Display cancellation history

 Complexity Analysis

Provide a short report discussing:

    Reservation insertion complexity
    Reservation removal complexity
    Waiting-list processing complexity
    Undo cancellation complexity

Include Big-O notation and brief explanations.

GitHub Collaboration

After the Project Management module, teams must:

    Create a GitHub repository
    Add all team members
    Maintain project code in the repository
    Use meaningful commit messages
    Create and merge at least one feature branch

Deliverables

Submit a zip file containing following files:

    Source code
    Header files
    README
    Complexity analysis document
    GitHub repository URL

The README, source code, and header files should match those that we find in your GitHub code repository. 

Testing Expectations

Teams should demonstrate:

    File input works correctly
    Reservations can be created
    Reservations can be cancelled
    Waiting lists function correctly
    Undo functionality works correctly
    Invalid input is handled properly

Final Project Submission (Due on 10/11)
Objectives

Complete and refine the system by implementing searching, sorting, reporting, testing, and full integration.

Required Features
Searching

Implement at least one searching algorithm:

    Linear Search, or
    Binary Search

The search functionality must be integrated into the system.

Possible applications:

    Search resources
    Search reservations
    Search students

Sorting

Implement at least one sorting algorithm:

    Merge Sort
    Quick Sort
    Heap Sort

The sorting functionality must be integrated into the system.

Possible applications:

    Resources sorted by name
    Resources sorted by popularity
    Reservations sorted by date

Reporting

Generate system reports including:

    Active reservations
    Resource utilization
    Most requested resources
    Waiting-list statistics


System Integration

All project components must function together within a unified system.

The program should provide a consistent user interface and robust error handling.

Testing

Teams should conduct comprehensive testing and document the results.

Deliverables

Submit a zip file containing following files:

    Complete source code
    Header files
    README
    User documentation
    GitHub repository URL

The README, source code, and header files should match those that we find in your GitHub code repository. 

Academic Integrity

All submitted work must be created entirely by your group.

You may NOT:

• Copy code from other students or groups
• Download project solutions
• Use AI-generated code (ChatGPT, Copilot, Gemini, Claude, etc.)
• Use code obtained from online sources without instructor permission

Discussion of concepts and algorithms is permitted.

Sharing source code, project files, or AI-generated implementations is prohibited and will be treated as academic dishonesty.

Failure to compile, inability to explain submitted code, or violations of the Academic Integrity policy may result in significant grade deductions and may be referred for further academic review.

All group members must be able to explain the code they submit.

Final Advice

Start early.

Most project failures occur because groups:

    delay integration
    fail to test incrementally
    wait until the last week to combine code

Build and test your system gradually throughout the project timeline.
