#include "CityTraverser.h"

CityTraverser::CityTraverser(){
    state = nullptr;
    currentElement = -1;
    Element = nullptr;
    currentLayer = nullptr;
    dataType = 0;

}

CityTraverser::CityTraverser(Transportation* t){
    if(t == nullptr){
        state = nullptr;
        currentElement = -1;
        Element = nullptr;
        currentLayer = nullptr;
        dataType = 0;
        return;
    }

    this->dataType = t->getType();
    this->currentElement = 0;
    this->currentLayer = t;

    this->setState();

    this->Element = state->getPos(currentElement);

}

CityTraverser::CityTraverser(CityTraverser* t){
    if(t == nullptr){
        state = nullptr;
        currentElement = -1;
        Element = nullptr;
        currentLayer = nullptr;
        dataType = 0;
        return;
    }

    this->currentLayer = t->currentLayer;
    this->dataType = t->dataType;
    this->currentElement = t->currentElement;

    this->setState();

    this->Element = state->getPos(currentElement);

}

bool CityTraverser::operator++(){
    if(this->Element == nullptr){
        return false;
    }

    Transportation* temp = state->getPos(currentElement+1);

    if(temp == nullptr){
        return false;
    }

    this->currentElement++;
    this->Element = temp;

    return true;
}

bool CityTraverser::operator--(){
    if(this->Element == nullptr){
        return false;
    }

    Transportation* temp = state->getPos(currentElement-1);

    if(temp == nullptr){
        return false;
    }

    this->currentElement--;
    this->Element = temp;

    return true;

}

bool CityTraverser::operator+(){
    if(this->state->nextList() == false){
        return false;
    }

    this->currentElement = 0;
    this->Element = state->getPos(currentElement);

    return true;

}

bool CityTraverser::operator-(){
    if(this->state->prevList() == false){
        return false;
    }

    this->currentElement = 0;
    this->Element = state->getPos(currentElement);

    return true;
}

bool CityTraverser::stepIn(){
    if(this->Element == nullptr){
        return false;
    }

    this->prevLayers.push_back(this->currentLayer);
    this->currentLayer = this->Element;
    this->dataType = this->currentLayer->getType();
    this->setState();
    this->currentElement = 0;
    this->Element = state->getPos(currentElement);

    return true;

}

bool CityTraverser::stepOut(){
    if(this->prevLayers.size() == 0){
        return false;
    }

    this->currentLayer = this->prevLayers.back();
    this->prevLayers.pop_back();
    this->dataType = this->currentLayer->getType();
    this->setState();
    this->currentElement = 0;
    this->Element = state->getPos(currentElement);

    return true;

}

Transportation* CityTraverser::operator*(){
    return this->Element;
}

Transportation* CityTraverser::getCurrentLayer(){
    return this->currentLayer;
}

bool CityTraverser::operator=(Transportation* t){
    if(t == nullptr){
        return false;
    }

    this->dataType = t->getType();
    this->currentElement = 0;
    this->currentLayer = t;
    this->setState();
    this->Element = state->getPos(currentElement);
    this->prevLayers.clear();

    return true;
}

bool CityTraverser::operator=(CityTraverser* t){
    if(t == nullptr){
        return false;
    }

    this->currentLayer = t->currentLayer;
    this->dataType = t->dataType;
    this->currentElement = t->currentElement;
    this->setState();
    this->Element = state->getPos(currentElement);
    
    this->prevLayers.clear();

    for(Transportation *x: t->prevLayers){
        this->prevLayers.push_back(x);
    }

    return true;
}

bool CityTraverser::setState(){
    if(this->state != nullptr){
        delete this->state;
    }

    switch(dataType){
        case 'H':
            state = new TraverseHighway(this->currentLayer);
            break;

        case 'I':
            state = new TraverseInsideRoad(this->currentLayer);
            break;

        case 'B':
            state = new TraverseBus(this->currentLayer);
            break;

        case 'T':
            state = new TraverseTaxi(this->currentLayer);
            break;

        case 'F':
            state = new TraverseFreightTrain(this->currentLayer);
            break;

        case 'P':
            state = new TraversePassengerTrain(this->currentLayer);
            break;

        case 'C':
            state = new TraverseCargoAirport(this->currentLayer);
            break;

        case 'A':
            state = new TraverseComercialAirport(this->currentLayer);
            break;

        default:
            state = nullptr;
            break;
    }

    return true;

}

CityTraverser::~CityTraverser(){
    if(this->state != nullptr){
        delete this->state;
    }

    this->prevLayers.clear();
}