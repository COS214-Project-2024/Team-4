// Citizen.h

#ifndef CITIZEN_H
#define CITIZEN_H

#include <string>
#include <memory>
#include <vector>

class Policy;
class Service;

class Citizen {
protected:
    std::string name;
    int age;
    std::string resStatus;
    std::string jobStatus;
    float satisfaction;
    bool maritalStatus;
    bool health;
    double bankBalance;
    std::string educationLevel;
    bool housingSatisfaction;
    double income;
	std::vector<CitizenObserver*> observers;

public:
    Citizen(const std::string& name, int age, const std::string& resStatus, const std::string& jobStatus);
    virtual ~Citizen();
    
    virtual std::shared_ptr<Citizen> clone() const = 0; // Prototype pattern

	// Observer management
    void addObserver(CitizenObserver* observer);
    void removeObserver(CitizenObserver* observer);
    void notifyObservers();

    // Update Methods
    void updateJobSatisfaction();
    void updateMaritalStatus();
    void updateTaxRate(double rate);
    void updateHealth(bool status);
    void updateSatisfaction();
    void updateTaxRatePolicy(Policy& policy);
    void updateResService(Service& service);
    void changeTaxRate(double rate);
	void updateEducationLevel();
	void updateHealthStatus();
	void updateHousingSatisfaction();
	void updateBankBalance(double amount);
	void updateService(Service* service);
	void updatePolicy(const Policy* policy);



    // Getters
	int getAge() const;
    std::string getName() const;
    std::string getJob() const;
    bool getHealth() const;
    bool getFather() const;
	bool getMother() const;
	std::string getResStatus() const;
	std::string getJobStatus() const;
};

#endif // CITIZEN_H
