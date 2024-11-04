/**
 * @file TrafficFlow.h
 * @brief Defines the TrafficFlow interface for traffic flow measurement.
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef TRAFFICFLOW_H
#define TRAFFICFLOW_H

/**
 * @class TrafficFlow
 * @brief An abstract class that represents the traffic flow.
 *
 * This class provides an interface for measuring traffic flow and obtaining the state of the traffic.
 */
class TrafficFlow {
    public:
        /**
         * @brief Pure virtual function to get the traffic flow.
         * 
         * @return float The current traffic flow.
         */
        virtual float getTrafficFlow() = 0;

        /**
         * @brief Pure virtual function to get the state of the traffic.
         * 
         * @return char The current state of the traffic.
         */
        virtual char getState() = 0;
};

#endif