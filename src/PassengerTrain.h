/**
 * @file PassengerTrain.h
 * @brief Header file for the PassengerTrain class.
 * 
 * This file contains the declaration of the PassengerTrain class, which inherits from the Train class.
 * The PassengerTrain class manages a collection of InsideRoad and PassengerTrain objects.
 *
 * @author Samvit_Prakash_u23525119
 * @date 04/10/2024
 */
#ifndef PASSANGERTRAIN_H
#define PASSANGERTRAIN_H

#include "Train.h"
#include "InsideRoad.h"

class InsideRoad;

/**
 * @class PassengerTrain
 * @brief A class representing a passenger train.
 * 
 * The PassengerTrain class inherits from the Train class and manages a collection of InsideRoad and PassengerTrain objects.
 */
class PassengerTrain : public Train {
    private:
        std::vector<InsideRoad*> insideRoads; ///< A vector of pointers to InsideRoad objects.
        std::vector<PassengerTrain*> passengerTrains; ///< A vector of pointers to PassengerTrain objects.          

    public:
        /**
         * @brief Constructor for the PassengerTrain class.
         * 
         * @param state The state of the train.
         * @param line The line on which the train operates.
         */
        PassengerTrain(char state, std::string line);

        /**
         * @brief Adds an InsideRoad object to the train.
         * 
         * @param insideRoad A pointer to the InsideRoad object to be added.
         * @return true if the InsideRoad was added successfully, false otherwise.
         */
        bool addInsideRoad(InsideRoad *insideRoad);

        /**
         * @brief Adds a PassengerTrain object to the train.
         * 
         * @param passengerTrain A pointer to the PassengerTrain object to be added.
         * @return true if the PassengerTrain was added successfully, false otherwise.
         */
        bool addPassengerTrain(PassengerTrain *passengerTrain);

        /**
         * @brief Gets an InsideRoad object from the train.
         * 
         * @param x The index of the InsideRoad object to be retrieved.
         * @return A pointer to the InsideRoad object.
         */
        InsideRoad *getInsideRoad(std::size_t x);

        /**
         * @brief Gets a PassengerTrain object from the train.
         * 
         * @param x The index of the PassengerTrain object to be retrieved.
         * @return A pointer to the PassengerTrain object.
         */
        PassengerTrain *getPassengerTrain(std::size_t x);

        /**
         * @brief Gets the line on which the train operates.
         * 
         * @return A string representing the train line.
         */
        std::string getTrainLine();


        /**
         * @brief Calculates the adjusted commute time for the passenger train.
         * 
         * This function computes the adjusted commute time based on various factors
         * such as delays, speed adjustments, and other relevant parameters.
         * 
         * @return float The adjusted commute time in hours.
         */
        float commuteTime() override;
};

#endif