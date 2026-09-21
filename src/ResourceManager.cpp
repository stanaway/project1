#include "ResourceManager.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;



void ResourceManager::loadResources(string resourcesFile){
    ifstream inputFile(resourcesFile);

    if(!inputFile.is_open()){
        cout << "Error opening the resources.txt file." << endl;
        return;
    }

    string line;

    while(getline(inputFile, line)){
        string resourceID;
        string resourceName;
        string resourceType;
        string availabilityStatus;

        stringstream ss(line);

        getline(ss, resourceID, '|');
        getline(ss, resourceName, '|');
        getline(ss, resourceType, '|');
        getline(ss, availabilityStatus, '|');


        Resource newResource(resourceID, resourceName, resourceType, availabilityStatus);

        resources.push_back(newResource);

    }

    inputFile.close();


}

void ResourceManager::displayResources(){

    for(int i = 0; i < resources.size(); i++){
        cout << "Resource ID: " << resources[i].getResourceID() << endl;
        cout << "Resource Name: " << resources[i].getResourceName() << endl;
        cout << "Resource Type: " << resources[i].getResourceType() << endl;
        cout << "Availability Status: " << resources[i].getAvailabilityStatus() << endl;
        cout << "----------------------------------------------------------------------" << endl;

    }

}

Resource* ResourceManager::findResource(string resourceID){
    for(int i = 0; i < resources.size(); i++){
        if(resources[i].getResourceID() == resourceID){
            return &resources[i];
        }
    }

    return nullptr;


}

bool ResourceManager::resourceExists(string resourceID){
    if(findResource(resourceID) != nullptr){
        return true;
    }
    else{
        return false;
    }

}
