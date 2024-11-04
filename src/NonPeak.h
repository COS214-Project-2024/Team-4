/**
 * @file NonPeak.h
 * @brief Header file for the NonPeak class.
 * @version 1.0
 * 
 * This file contains the definition of the NonPeak class, which is a subclass of TrafficFlow.
 * The NonPeak class represents traffic flow during non-peak hours.
 *
 * @date 2024-11-04
 */
#ifndef NONPEAK_H
#define NONPEAK_H

#include "TrafficFlow.h"

/**
 * @class NonPeak
 * @brief A class to represent traffic flow during non-peak hours.
 * 
 * The NonPeak class inherits from the TrafficFlow class and provides specific
 * implementations for traffic flow and state during non-peak hours.
 */
class NonPeak : public TrafficFlow {
    private:
        float trafficFlow = 0.2; ///< Traffic flow rate during non-peak hours.
        char state = 'N'; ///< State representing non-peak hours.

    public:
        /**
         * @brief Get the traffic flow rate.
         * 
         * @return float The traffic flow rate during non-peak hours.
         */
        float getTrafficFlow();

        /**
         * @brief Get the state of traffic flow.
         * 
         * @return char The state representing non-peak hours.
         */
        char getState();
    
};

#endif // NONPEAK_H