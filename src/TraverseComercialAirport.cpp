#include "TraverseComercialAirport.h"

TraverseComercialAirport::TraverseComercialAirport(Transportation *element) : TraverseState(element) {}

bool TraverseComercialAirport::nextList() {
    if (currentList < upperBound) {
        currentList++;
        return true;
    }
    return false;
}

bool TraverseComercialAirport::prevList() {
    if (currentList > 0) {
        currentList--;
        return true;
    }
    return false;
}

Transportation* TraverseComercialAirport::getPos(size_t x) {
    ComercialAirport *comercialAirport = static_cast<ComercialAirport*>(this->getLayer());

    switch(currentList) {
        case 0:
            return comercialAirport->getRoad(x);
     
        case 1:
            return comercialAirport->getComercialAirport(x);
     
        default:
            return nullptr;
    }

}