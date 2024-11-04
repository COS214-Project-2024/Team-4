/**
 * @file CityTraverser.cpp
 * @brief Implementation of the CityTraverser class.
 *
 * This file contains the implementation of the CityTraverser class which traverses through different city transportation layers.
 * @date 2024-11-04
 * @version 1.0
 */

#include "CityTraverser.h"

/**
 * @brief Default constructor for CityTraverser.
 *
 * Initializes the CityTraverser with default values.
 */
CityTraverser::CityTraverser(){
    state = nullptr;
    currentElement = -1;
    Element = nullptr;
    currentLayer = nullptr;
    dataType = 0;
}

/**
 * @brief Constructor for CityTraverser with a Transportation object.
 *
 * Initializes the CityTraverser with a given Transportation object.
 * 
 * @param t Pointer to a Transportation object.
 */
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

/**
 * @brief Copy constructor for CityTraverser.
 *
 * Initializes the CityTraverser with another CityTraverser object.
 * 
 * @param t Pointer to a CityTraverser object.
 */
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

/**
 * @brief Increment operator for CityTraverser.
 *
 * Moves to the next element in the current layer.
 * 
 * @return True if successful, false otherwise.
 */
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

/**
 * @brief Decrement operator for CityTraverser.
 *
 * Moves to the previous element in the current layer.
 * 
 * @return True if successful, false otherwise.
 */
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

/**
 * @brief Move to the next list in the current layer.
 * 
 * @return True if successful, false otherwise.
 */
bool CityTraverser::operator+(){
    if(this->state->nextList() == false){
        return false;
    }

    this->currentElement = 0;
    this->Element = state->getPos(currentElement);

    return true;
}

/**
 * @brief Move to the previous list in the current layer.
 * 
 * @return True if successful, false otherwise.
 */
bool CityTraverser::operator-(){
    if(this->state->prevList() == false){
        return false;
    }

    this->currentElement = 0;
    this->Element = state->getPos(currentElement);

    return true;
}

/**
 * @brief Step into the current element.
 * 
 * @return True if successful, false otherwise.
 */
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

/**
 * @brief Step out to the previous layer.
 * 
 * @return True if successful, false otherwise.
 */
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

/**
 * @brief Dereference operator for CityTraverser.
 * 
 * @return Pointer to the current Transportation element.
 */
Transportation* CityTraverser::operator*(){
    return this->Element;
}

/**
 * @brief Get the current layer.
 * 
 * @return Pointer to the current Transportation layer.
 */
Transportation* CityTraverser::getCurrentLayer(){
    return this->currentLayer;
}

/**
 * @brief Assignment operator for CityTraverser with a Transportation object.
 * 
 * @param t Pointer to a Transportation object.
 * @return True if successful, false otherwise.
 */
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

/**
 * @brief Assignment operator for CityTraverser with another CityTraverser object.
 * 
 * @param t Pointer to a CityTraverser object.
 * @return True if successful, false otherwise.
 */
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

/**
 * @brief Set the state based on the current data type.
 * 
 * @return True if successful, false otherwise.
 */
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

/**
 * @brief Destructor for CityTraverser.
 */
CityTraverser::~CityTraverser(){
    if(this->state != nullptr){
        delete this->state;
    }

    this->prevLayers.clear();
}