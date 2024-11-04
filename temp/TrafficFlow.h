#ifndef TRAFFICFLOW_H
#define TRAFFICFLOW_H

class TrafficFlow {
    public:
        virtual float getTrafficFlow() = 0;
        virtual char getState() = 0;
    
};

#endif