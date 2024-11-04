#include "TraverseCargoAirport.h"

TraverseCargoAirport::TraverseCargoAirport(Transportation *element) : TraverseState(element) {}

bool TraverseCargoAirport::nextList() {
    if (currentList < upperBound) {
        currentList++;
        return true;
    }
    return false;
}

bool TraverseCargoAirport::prevList() {
    if (currentList > 0) {
        currentList--;
        return true;
    }
    return false;
}

Transportation* TraverseCargoAirport::getPos(size_t x) {
    CargoAirport *cargoAirport = static_cast<CargoAirport*>(this->getLayer());

    switch(currentList) {
        case 0:
            return cargoAirport->getInsideRoad(x);
     
        case 1:
            return cargoAirport->getCargoAirport(x);
     
        default:
            return nullptr;
    }

}