/**
 * @file LunchRush.h
 * @brief Header file for the LunchRush class.
 *
 * This file contains the declaration of the LunchRush class, which is derived from the TrafficFlow class.
 * The LunchRush class represents a specific state of traffic flow during lunch hours.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef LUNCHRUSH_H
#define LUNCHRUSH_H

#include "TrafficFlow.h"

/**
 * @class LunchRush
 * @brief A class representing traffic flow during lunch hours.
 *
 * The LunchRush class inherits from the TrafficFlow class and provides specific implementations
 * for traffic flow and state during lunch hours.
 */
class LunchRush : public TrafficFlow {
    private:
        char state = 'L'; ///< The state of the traffic flow, 'L' for LunchRush.
        float trafficFlow = 0.5; ///< The traffic flow value during lunch hours.

    public:
        /**
         * @brief Get the traffic flow value.
         * @return The traffic flow value as a float.
         */
        float getTrafficFlow();

        /**
         * @brief Get the state of the traffic flow.
         * @return The state of the traffic flow as a char.
         */
        char getState();
};

#endif