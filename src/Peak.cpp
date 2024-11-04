/**
 * @file Peak.cpp
 * @brief Implementation of the Peak class.
 * @version 1.0
 * 
 * This file contains the implementation of the Peak class, which provides methods to get
 * the traffic flow and state during peak hours.
 */

#include "Peak.h"

/**
 * @brief Gets the traffic flow during peak hours.
 * @return The traffic flow.
 */
float Peak::getTrafficFlow() {
    return trafficFlow;
}

/**
 * @brief Gets the state during peak hours.
 * @return The state.
 */
char Peak::getState() {
    return state;
}