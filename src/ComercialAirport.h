#ifndef COMERCIALAIRPORT_H
#define COMERCIALAIRPORT_H

#include "Airport.h"
#include "InsideRoad.h"

class ComercialAirport : public Airport {
    private:
        std::vector<InsideRoad*> roads;
        std::vector<ComercialAirport*> comercialAirports;

    public:
        ComercialAirport(char state, std::string name);
        bool addRoad(InsideRoad *road);
        bool addComercialAirport(ComercialAirport *comercialAirport);
        InsideRoad* getRoad(std::size_t index);
        ComercialAirport* getComercialAirport(std::size_t index);
        std::string getName();
};

#endif