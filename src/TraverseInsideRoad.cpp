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
    switch(currentList){
        case 0:
            InsideRoad *temp = static_cast<InsideRoad*>(this->getLayer())->getInsideRoad(x);
            return temp;

        case 1:
            Highway *temp2 = static_cast<InsideRoad*>(this->getLayer())->getHighway(x);
            return temp2;   

        case 2:
            Bus *temp3 = static_cast<InsideRoad*>(this->getLayer())->getBus(x);
            return temp3;

        case 3:
            Taxi *temp4 = static_cast<InsideRoad*>(this->getLayer())->getTaxi(x);
            return temp4;

        case 4:
            ComercialAirport *temp5 = static_cast<InsideRoad*>(this->getLayer())->getComercialAirport(x);
            return temp5;

        case 5:
            CargoAirport *temp6 = static_cast<InsideRoad*>(this->getLayer())->getCargoAirport(x);
            return temp6;

        case 6:
            PassengerTrain *temp7 = static_cast<InsideRoad*>(this->getLayer())->getPassengerTrain(x);
            return temp7;

        case 7:
            FreightTrain *temp8 = static_cast<InsideRoad*>(this->getLayer())->getFreightTrain(x);
            return temp8;

        default:
            return nullptr;
            
    }

}
