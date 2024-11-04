#ifndef CITIZENMANAGER_H
#define CITIZENMANAGER_H

#include <string>
#include <map>

class CitizenManager {
private:
    std::map<std::string, double> citizenCharges; // Track charges for each citizen

public:
    void addCharge(const std::string& citizen, double amount) {
        citizenCharges[citizen] += amount;
    }

    double getTotalCharges(const std::string& citizen) const {
        auto it = citizenCharges.find(citizen);
        return it != citizenCharges.end() ? it->second : 0.0;
    }
};

#endif // CITIZENMANAGER_H
