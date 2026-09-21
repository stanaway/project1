#include "Resource.h"
#include <iostream>
using namespace std;


Resource::Resource(){
    resourceID = "";
    resourceName = "";
    resourceType = "";
    availabilityStatus = "";
}


Resource::Resource(string rsrcID, string rsrcName, string rsrcType, string availStat){
    resourceID = rsrcID;
    resourceName = rsrcName;
    resourceType = rsrcType;
    availabilityStatus = availStat;
}

//---------------------------------------
string Resource::getResourceID(){
    return resourceID;

}

string Resource::getResourceName(){
    return resourceName;

}

string Resource::getResourceType(){
    return resourceType;

}
        
string Resource::getAvailabilityStatus(){
    return availabilityStatus;
        
}

//---------------------------------------
void Resource::setResourceID(string rsrcID){
    resourceID = rsrcID;

}

void Resource::setResourceName(string rsrcName){
    resourceName = rsrcName;
}
        
void Resource::setResourceType(string rsrcType){
    resourceType = rsrcType;
}
        
void Resource::setAvailabilityStatus(string availStat){
    availabilityStatus =  availStat;
}


