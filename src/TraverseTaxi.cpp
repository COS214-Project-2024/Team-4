#include "TraverseTaxi.h"

TraverseTaxi::TraverseTaxi(Transportation *element) : TraverseState(element) {}

bool TraverseTaxi::nextList() {
    if (currentList < upperBound) {
        currentList++;
        return true;
    }
    return false;
}

bool TraverseTaxi::prevList() {
    if (currentList > 0) {
        currentList--;
        return true;
    }
    return false;
}

Transportation* TraverseTaxi::getPos(size_t x) {
    Taxi *taxi = static_cast<Taxi*>(this->getLayer());
    
    switch (currentList) {
        case 0:
            return taxi->getInsideRoad(x);
        case 1:
            return taxi->getComercialAirport(x);
        case 2:
            return taxi->getCargoAirport(x);
        case 3:
            return taxi->getPassengerTrain(x);
        case 4:
            return taxi->getFreightTrain(x);
        default:
            return nullptr;
    }
}