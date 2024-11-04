#include "TraversePassengerTrain.h"

TraversePassengerTrain::TraversePassengerTrain(Transportation *element) : TraverseState(element) {}

bool TraversePassengerTrain::nextList() {
    if (currentList < upperBound) {
        currentList++;
        return true;
    }
    return false;
}

bool TraversePassengerTrain::prevList() {
    if (currentList > 0) {
        currentList--;
        return true;
    }
    return false;
}

Transportation* TraversePassengerTrain::getPos(size_t x) {
    PassengerTrain *passengerTrain = static_cast<PassengerTrain*>(this->getLayer());

    switch (currentList) {
        case 0:
            return passengerTrain->getPassengerTrain(x);
        
        case 1:
            return passengerTrain->getInsideRoad(x);

        default:
            return nullptr;
    }

}