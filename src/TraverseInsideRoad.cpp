#include "TraverseInsideRoad.h"

TraverseInsideRoad::TraverseInsideRoad(Transportation *element) : TraverseState(element) {}

bool TraverseInsideRoad::nextList() {
    if (currentList < upperBound) {
        currentList++;
        return true;
    }
    return false;
}

bool TraverseInsideRoad::prevList() {
    if (currentList > 0) {
        currentList--;
        return true;
    }
    return false;
}

Transportation* TraverseInsideRoad::getPos(size_t x) {
    InsideRoad *temp = static_cast<InsideRoad*>(this->getLayer());

    switch(currentList){
        case 0:
            return temp->getInsideRoad(x);

        case 1:
            return temp->getHighway(x);   

        case 2:
            return temp->getBus(x);

        case 3:
            return temp->getTaxi(x);

        case 4:
            return temp->getComercialAirport(x);

        case 5:
            return temp->getCargoAirport(x);

        case 6:
            return temp->getPassengerTrain(x);

        case 7:
            return temp->getFreightTrain(x);

        default:
            return nullptr;
            
    }

}
