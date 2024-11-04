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
    Bus *temp = static_cast<Bus*>(this->getLayer());

    switch(currentList) {
        case 0:
            return temp->getInsideRoad(x);

        case 1:
            return temp->getBus(x);

        case 2:
            return temp->getComercialAirport(x);

        case 3:
            return temp->getPassengerTrain(x);

        default:
            return nullptr;
    }
}
