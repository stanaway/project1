#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <string>
#include "Resource.h"

using namespace std;


class ResourceManager{
    private:
        vector<Resource> resources;

    public:
        void loadResources(string resourcesFile);
        void displayResources();

        Resource* findResource(string resourceID);

        bool resourceExists(string resourceID);

};


#endif
