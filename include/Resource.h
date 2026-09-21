#ifndef RESOURCE_H
#define RESOURCE_H 


#include <string>
using namespace std;


class Resource{

    private:
        string resourceID;
        string resourceName;
        string resourceType;
        string availabilityStatus;

    public:
        Resource();
        Resource(string rsrcID, string rsrcName, string rsrcType, string availStat); 
        //rsrcID = resourceID, rsrcName = resourceName, rsrcType = resourceType, availStat = availabilityStatus

        string getResourceID();
        string getResourceName();
        string getResourceType();
        string getAvailabilityStatus();

        void setResourceID(string rsrcID);
        void setResourceName(string rsrcName);
        void setResourceType(string rsrcType);
        void setAvailabilityStatus(string availStat);


};

#endif
