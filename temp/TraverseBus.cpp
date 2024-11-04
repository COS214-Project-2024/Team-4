#include "TraverseBus.h"

TraverseBus::TraverseBus(Transportation *element) : TraverseState(element) {}

bool TraverseBus::nextList() {
    if (currentList < upperBound) {
        currentList++;
        return true;
    }
    return false;
}

bool TraverseBus::prevList() {
    if (currentList > 0) {
        currentList--;
        return true;
    }
    return false;
}

Transportation* TraverseBus::getPos(size_t x) {
    switch(currentList) {
        case 0:
            InsideRoad *temp = static_cast<Bus*>(this->getLayer())->getInsideRoad(x);
            return temp;

        case 1:
            Bus *temp1 = static_cast<Bus*>(this->getLayer())->getBus(x);
            return temp1;

        case 2:
            ComercialAirport *temp2 = static_cast<Bus*>(this->getLayer())->getComercialAirport(x);
            return temp2;

        case 3:
            PassengerTrain *temp3 = static_cast<Bus*>(this->getLayer())->getPassengerTrain(x);
            return temp3;

        default:
            return nullptr;
    }
}
