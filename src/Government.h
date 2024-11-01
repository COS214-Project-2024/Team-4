#ifndef GOVERNMENT_H
#define GOVERNMENT_H

#include <string>
#include <vector>


class Government {
public:
    Government(const std::string& name);

    // Getters
    std::string getName() const;
    std::string getType() const;
    double getTaxRate() const;
    double getBudget() const;
    void setName(const std::string& name);
    void setType(const std::string& type);
    void setTaxRate(double rate);
    void setBudget(double budget);
    void addPolicy(const std::string& policy);
    std::vector<std::string> getPolicies() const;
    void notifyCitizen() const;
    void notifyBusinesses() const;
    void notifyServices() const;
//     void allocateBudget(CityService& service, double amount);
//    void enforcePolicy(const Policy& policy);
    void update(int newPopulation);

private:
    std::string name;
    std::string type;
    double taxRate;
    double budget;
    std::vector<std::string> policies;
};
#endif // GOVERNMENT_H