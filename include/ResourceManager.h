
#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <vector>
#include <string>
#include "Resource.h"

using namespace std;


class ResourceManager{
    private:
        friend class ReportGenerator;

        vector<Resource> resources;

    public:
        void loadResources(string resourcesFile);
        void displayResources();

        Resource* findResource(string resourceID);

        bool resourceExists(string resourceID);

        void quickSort(int low, int high);

        int partition(int low, int high);

        void sortResourcesByName();

};


#endif
