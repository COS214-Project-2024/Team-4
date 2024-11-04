/**
 * @file FreightTrain.h
 * @brief Header file for the FreightTrain class.
 * 
 * This file contains the definition of the FreightTrain class, which inherits from the Train class.
 * The FreightTrain class represents a freight train with specific attributes such as weight and length,
 * and it can manage a collection of InsideRoad and FreightTrain objects.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef FREIGHTTRAIN_H
#define FREIGHTTRAIN_H

#include "Train.h"
#include "InsideRoad.h"

class InsideRoad;

/**
 * @class FreightTrain
 * @brief A class representing a freight train.
 * 
 * The FreightTrain class inherits from the Train class and includes additional attributes
 * specific to freight trains, such as weight and length. It also manages collections of
 * InsideRoad and FreightTrain objects.
 */
class FreightTrain : public Train {
    private:
        float weight; ///< The weight of the freight train.
        float length; ///< The length of the freight train.

        std::vector<InsideRoad*> insideRoads; ///< Collection of InsideRoad objects associated with the freight train.
        std::vector<FreightTrain*> freightTrains; ///< Collection of FreightTrain objects associated with the freight train.

    public:
        /**
         * @brief Constructor for the FreightTrain class.
         * 
         * @param state The state of the train.
         * @param line The line on which the train operates.
         * @param weight The weight of the freight train.
         * @param length The length of the freight train.
         */
        FreightTrain(char state, std::string line, float weight, float length);

        /**
         * @brief Adds an InsideRoad object to the freight train.
         * 
         * @param insideRoad Pointer to the InsideRoad object to be added.
         * @return true if the InsideRoad was added successfully, false otherwise.
         */
        bool addInsideRoad(InsideRoad *insideRoad);

        /**
         * @brief Adds a FreightTrain object to the freight train.
         * 
         * @param freightTrain Pointer to the FreightTrain object to be added.
         * @return true if the FreightTrain was added successfully, false otherwise.
         */
        bool addFreightTrain(FreightTrain *freightTrain);

        /**
         * @brief Retrieves an InsideRoad object by index.
         * 
         * @param index The index of the InsideRoad object to retrieve.
         * @return Pointer to the InsideRoad object at the specified index.
         */
        InsideRoad* getInsideRoad(size_t index);

        /**
         * @brief Retrieves a FreightTrain object by index.
         * 
         * @param index The index of the FreightTrain object to retrieve.
         * @return Pointer to the FreightTrain object at the specified index.
         */
        FreightTrain* getFreightTrain(size_t index);

        /**
         * @brief Gets the weight of the freight train.
         * 
         * @return The weight of the freight train.
         */
        float getWeight();

        /**
         * @brief Gets the length of the freight train.
         * 
         * @return The length of the freight train.
         */
        float getLength();

        /**
         * @brief Gets the line on which the train operates.
         * 
         * @return The line on which the train operates.
         */
        std::string getTrainLine();

        /**
         * @brief Calculates an adjusted commute time for the freight train.
         * 
         * This function takes the return value of Train::commuteTime() and adjusts it
         * based on external variables to provide a more realistic commute time.
         * 
         * @return The adjusted commute time for the freight train.
         */
        float commuteTime() override;
        
};

#endif // FREIGHTTRAIN_H