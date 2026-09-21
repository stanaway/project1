#include "Reservation.h"
#include <iostream>
using namespace std;


Reservation::Reservation(){
    reservationID = "";
    studentID = "";
    studentName = "";
    resourceID = "";
    reservationDate = "";
}


Reservation::Reservation(string reservID, string stuID, string stuName, string resourID, string reservDate){
    reservationID = reservID;
    studentID = stuID;
    studentName = stuName;
    resourceID = resourID;
    reservationDate = reservDate;
}

//---------------------------------------
string Reservation::getReservationID(){
    return reservationID;

}

string Reservation::getStudentID(){
    return studentID;

}

string Reservation::getStudentName(){
    return studentName;

}
        
string Reservation::getResourceID(){
    return resourceID;
        
}

string Reservation::getReservationDate(){
    return reservationDate;
        
}

//---------------------------------------
void Reservation::setReservationID(string reservID){
    reservationID = reservID;

}

void Reservation::setStudentID(string stuID){
    studentID = stuID;
}
        
void Reservation::setStudentName(string stuName){
    studentName = stuName;
}
        
void Reservation::setResourceID(string resourID){
    resourceID =  resourID;
}

void Reservation::setReservationDate(string reservDate){
    reservationDate =  reservDate;
}


