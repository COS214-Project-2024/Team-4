/**
 * @file NonPeak.cpp
 * @brief Implementation of the NonPeak class.
 * @version 1.0
 * 
 * This file contains the implementation of the NonPeak class, which provides methods to get
 * the traffic flow and state during non-peak hours.
 */

#include "NonPeak.h"

/**
 * @brief Gets the traffic flow during non-peak hours.
 * @return The traffic flow.
 */
float NonPeak::getTrafficFlow() {
    return trafficFlow;
}

/**
 * @brief Gets the state during non-peak hours.
 * @return The state.
 */
char NonPeak::getState() {
    return state;
}