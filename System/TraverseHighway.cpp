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
    Highway *temp = static_cast<Highway*>(this->getLayer());

    switch(this->currentList){
        case 0:
            return temp->getInsideRoad(x);

        case 1:
            return temp->getHighway(x);

        default:
            return nullptr;
    }


}