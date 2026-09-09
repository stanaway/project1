# project1
Milestone 1 – Core System Development
Objectives

Develop the core functionality of the Campus Resource Reservation System and establish the team's collaboration workflow.

By the end of this milestone, the system should support resource management, reservations, waiting lists, cancellation tracking, and team collaboration through GitHub.

Although this is a group project, each student will be evaluated individually based on their own contribution to the milestone.
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

Each student must use their own GitHub account when contributing to the repository. Students may be asked to demonstrate their commits, branches, pull requests, and other GitHub contributions.
Individual Contribution and Team Responsibilities

Each team must divide the project responsibilities among its members. The assigned responsibilities should reflect the actual work each student is expected to complete.

Each team member must make a meaningful, substantial, and documented contribution to the milestone. Contributions do not have to be identical in size or type, but each student is expected to complete their assigned responsibilities and contribute sufficiently to the project.

Students should keep track of the specific functions, features, testing, debugging, documentation, and other work they complete throughout the milestone.
Group Contribution Report

Each group must submit ONE contribution report as part of the Milestone 1 submission. The report must include a separate section for each team member describing the work completed by that student.

For each team member, the report must clearly identify:

    The component(s) of the project they worked on
    The specific functions, classes, or features they implemented
    Testing and debugging they completed
    Contributions to documentation or complexity analysis
    Relevant GitHub contributions, such as commits, branches, or pull requests
    Any other significant work completed for the milestone

The report should use the following format: Team Member 	Component(s) 	Specific Tasks Completed 	Testing/Debugging 	GitHub Contributions
Student 1 				
Student 2 				
Student 3 				

Below the table, include a short paragraph for each team member describing their individual contribution in more detail.

General statements such as "I worked on reservations" or "I helped with the project" are not sufficient. Students must identify the specific work they completed.

The contribution report must accurately represent the actual work completed by each team member. The instructor may compare the contribution report with the submitted source code and GitHub activity.
Deliverables

Submit a zip file containing following files:

    Source code
    Header files
    README
    Complexity analysis document
    GitHub repository URL
    Group Contribution Report

The README, source code, and header files should match those that we find in your GitHub code repository. 

Testing Expectations

Teams should demonstrate:

    File input works correctly
    Reservations can be created
    Reservations can be cancelled
    Waiting lists function correctly
    Undo functionality works correctly
    Invalid input is handled properly

Your project must compile and run successfully on the UNT CSE CELL machines before submission.
You may develop your project on your personal computer or another development environment, but you are responsible for verifying that your final code compiles and runs correctly on CELL.
