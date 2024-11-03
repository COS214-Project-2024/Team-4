#include <iostream>

using namespace std;

#include "Transportation.h"
#include "TransportManager.h"

int main() {
    TransportManager *manager = new TransportManager();
    
    manager->createInsideRoad('P', "Elm Street", 5);
    if(manager->getTransportation(1) == nullptr) cout << "NULL"; 
    


    delete manager;
    return 0;

}