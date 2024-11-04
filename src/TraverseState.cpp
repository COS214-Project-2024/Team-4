#include "TraverseState.h"

TraverseState::TraverseState(Transportation *layer){
    this->layer = layer;
}

Transportation* TraverseState::getLayer(){
    return this->layer;
}