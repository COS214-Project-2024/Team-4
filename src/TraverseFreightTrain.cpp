#include "TraverseFreightTrain.h"

TraverseFreightTrain::TraverseFreightTrain(Transportation *element) : TraverseState(element){}

bool TraverseFreightTrain::nextList(){
    if(currentList < upperBound){
        currentList++;
        return true;
    }
    return false;
}

bool TraverseFreightTrain::prevList(){
    if(currentList > 0){
        currentList--;
        return true;
    }
    return false;
}

Transportation* TraverseFreightTrain::getPos(size_t x){
    FreightTrain *freightTrain = static_cast<FreightTrain*>(this->getLayer());

    switch(currentList){
        case 0:
            return freightTrain->getFreightTrain(x);
        
        case 1:
            return freightTrain->getInsideRoad(x);

        default:
            return nullptr;
    }

}