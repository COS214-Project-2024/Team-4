#include "TraverseHighway.h"

TraverseHighway::TraverseHighway(Transportation *element): TraverseState(element){
    currentList = 0;
}

int TraverseHighway::getCurrentList(){
    return currentList;
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

std::vector<Transportation*> TraverseHighway::getList(){
    

}