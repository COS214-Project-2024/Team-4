#include "ComercialAirport.h"

ComercialAirport::ComercialAirport(char state, std::string name) : Airport(state, name, 'A') {}

bool ComercialAirport::addRoad(InsideRoad *road) {
    for(InsideRoad *x: this->roads) {
        if(x == road) {
            return false;
        }
    }
    
    roads.push_back(road);
    return true;
}

bool ComercialAirport::addComercialAirport(ComercialAirport *comercialAirport) {
    for(ComercialAirport *x: this->comercialAirports) {
        if(x == comercialAirport) {
            return false;
        }
    }
    
    comercialAirports.push_back(comercialAirport);
    return true;
}

InsideRoad* ComercialAirport::getRoad(std::size_t index) {
    if(index < roads.size() && index >= 0) {
        return roads[index];
    }
    
    return nullptr;
}

ComercialAirport* ComercialAirport::getComercialAirport(std::size_t index) {
    if(index < comercialAirports.size() && index >= 0) {
        return comercialAirports[index];
    }
    
    return nullptr;
}

std::string ComercialAirport::getName() {
    return this->getAirportName();
}

float ComercialAirport::commuteTime() {
    return this->calculateCommute();
}