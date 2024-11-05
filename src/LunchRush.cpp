/**
 * @file LunchRush.cpp
 * @brief Implementation of the LunchRush class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the implementation of the LunchRush class, which provides methods to get
 * the traffic flow and state during the lunch rush period.
 */

#include "LunchRush.h"

/**
 * @brief Gets the traffic flow during the lunch rush period.
 * @return The traffic flow.
 */
float LunchRush::getTrafficFlow() {
    return trafficFlow;
}  

/**
 * @brief Gets the state during the lunch rush period.
 * @return The state.
 */
char LunchRush::getState() {
    return state;
}