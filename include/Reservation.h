#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
using namespace std;


class Reservation{

    private:
        string reservationID;
        string studentID;
        string studentName;
        string resourceID;
        string reservationDate;

    public:
        Reservation();
        Reservation(string reservID, string stuID, string stuName, string resourID, string reservDate); 

        string getReservationID();
        string getStudentID();
        string getStudentName();
        string getResourceID();
        string getReservationDate();

        void setReservationID(string reservID);
        void setStudentID(string stuID);
        void setStudentName(string stuName);
        void setResourceID(string resourID);
        void setReservationDate(string reservDate);


};

#endif
