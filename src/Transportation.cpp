/**
 * @file Transportation.cpp
 * @brief Implementation of the Transportation class.
 * 
 * This file contains the implementation of the Transportation class, which represents 
 * a mode of transportation with different states such as Peak, NonPeak, and LunchRush.
 * 
 * @version 1.0
 * @date 2023-10-05
 * 
 */

#include "Transportation.h"

/**
 * @brief Constructs a new Transportation object.
 * 
 * @param state The state of the transportation (P for Peak, N for NonPeak, L for LunchRush).
 * @param type The type of transportation.
 */
Transportation::Transportation(char state, char type) {
    switch (state)
    {
    case 'P':
        this->state = new Peak();
        break;
    
    case 'N':
        this->state = new NonPeak();
        break;

    case 'L':
        this->state = new LunchRush();
        break;

    default:
        break;
    };

    this->type = type;
}

/**
 * @brief Gets the traffic flow based on the current state.
 * 
 * @return The current traffic flow.
 */
float Transportation::getTrafficFlow() {
    return this->state->getTrafficFlow();
}

/**
 * @brief Sets the state of the transportation.
 * 
 * @param state The new state (P for Peak, N for NonPeak, L for LunchRush).
 * @return True if the state was set successfully, false otherwise.
 */
bool Transportation::setState(char state) {
    switch (state)
    {
    case 'P':
        delete this->state;
        this->state = nullptr; 
        this->state = new Peak();
        return true;
        break;
    
    case 'N':
        delete this->state;
        this->state = nullptr;
        this->state = new NonPeak();
        return true;
        break;

    case 'L':
        delete this->state;
        this->state = nullptr;
        this->state = new LunchRush();
        return true;
        break;

    default:
        return false;
        break;
    };
}

/**
 * @brief Gets the type of transportation.
 * 
 * @return The type of transportation.
 */
char Transportation::getType() {
    return this->type;
}

/**
 * @brief Destroys the Transportation object.
 */
Transportation::~Transportation() {
    delete this->state;
    this->state = nullptr;
}