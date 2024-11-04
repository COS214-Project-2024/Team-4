/**
 * @file Peak.h
 * @brief Header file for the Peak class, which inherits from TrafficFlow.
 * 
 * This file contains the declaration of the Peak class, which represents a specific 
 * type of traffic flow with a predefined state and traffic flow value.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef PEAK_H
#define PEAK_H

#include "TrafficFlow.h"

/**
 * @class Peak
 * @brief A class representing peak traffic flow.
 * 
 * The Peak class inherits from the TrafficFlow class and represents a peak traffic 
 * flow state with a specific traffic flow value.
 */
class Peak : public TrafficFlow {
    private:
        char state = 'P'; ///< The state of the traffic flow, default is 'P' for peak.
        float trafficFlow = 0.8; ///< The traffic flow value, default is 0.8.

    public:
        /**
         * @brief Get the traffic flow value.
         * 
         * @return The traffic flow value as a float.
         */
        float getTrafficFlow();

        /**
         * @brief Get the state of the traffic flow.
         * 
         * @return The state of the traffic flow as a char.
         */
        char getState();
};

#endif