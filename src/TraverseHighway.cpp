#include "TraverseHighway.h"

TraverseHighway::TraverseHighway(Transportation *element): TraverseState(element){
    currentList = 0;
}

bool TraverseHighway::nextList(){
    if(currentList < upperBound){
        currentList++;
        return true;
    }

    return false;
}

bool TraverseHighway::prevList(){
    if(currentList > 0){
        currentList--;
        return true;
    }

    return false;
}

Transportation* TraverseHighway::getPos(size_t x){
    switch(this->currentList){
        case 0:
            InsideRoad *temp = static_cast<Highway*>(this->getLayer())->getInsideRoad(x);
            return temp;

        case 1:
            Highway *temp2 = static_cast<Highway*>(this->getLayer())->getHighway(x);
            return temp2;

        default:
            return nullptr;
    }


}