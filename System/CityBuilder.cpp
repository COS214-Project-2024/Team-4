#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include "Citizen.h"
#include "Jobs.h"
#include "Income.h"
#include "Property.h"
#include "Building.h"
#include "Sales.h"
#include "Director.h"
#include "CommercialBuildingBuilder.h"
#include "IndustrialBuildingBuilder.h"
#include "LandmarkBuildingBuilder.h"
#include "ResidentialBuildingBuilder.h"
#include "MaleCitizen.h"
#include "FemaleCitizen.h"
#include "BuildingManager.h"
#include "ResourceManager.h"
#include "Government.h"
#include "TransportManager.h"
#include "Resource.h"
#include "ResourceType.h"
#include "SetTaxCommand.h"
#include "AllocateBudgetCommand.h"
#include "EnforcePolicyCommand.h"
#include "CityTraverser.h"
#include "TaxSatisfactionStrategy.h"
#include "CitizenSatisfactionObserver.h"
#include "PopulationManager.h"

BuildingManager buildingManager(std::vector<std::shared_ptr<Building>>{});
ResourceManager resourceManager(10000); // Initial budget
Government government("City Government");
TransportManager transportManager;
PopulationManager populationManager;

// Main class for the TUI
class CitySimulationUI {
private:
std::vector<std::shared_ptr<Building>> resbuildings;
std::vector<std::shared_ptr<Building>> comBuildings;
    std::vector<std::shared_ptr<Citizen>> citizens;
    std::vector<std::shared_ptr<Jobs>> jobs;
    std::vector<std::unique_ptr<Building>> buildings;
    Director director;

public:

    void initializeResources() {
        auto waterResource = std::make_shared<Resource>(ResourceType::Water, 200); // Initialize with quantity
        auto powerResource = std::make_shared<Resource>(ResourceType::Power, 300); // Initialize with quantity

        resourceManager.addResource(ResourceType::Water, waterResource.get(), 5);  // Set cost per unit
        resourceManager.addResource(ResourceType::Power, powerResource.get(), 10); // Set cost per unit
    }
    // Main menu display
      void displayMainMenu() {
        std::cout << "\n--- City Builder Simulation ---\n";
        std::cout << "1. Manage Buildings\n";
        std::cout << "2. Manage Utilities\n";
        std::cout << "3. Allocate Resources\n";
        std::cout << "4. Set Government Policies\n";
        std::cout << "5. Add Transportation\n";
        std::cout << "6. View City Overview\n";
        std::cout << "7. Display Roads\n";
        std::cout << "8. Display City Map\n";
        std::cout << "9. Citizen Management\n";
        std::cout << "10. Job Management\n";
        std::cout << "11. Building Management\n";
        std::cout << "12. Financial Management\n";
        std::cout << "13. Manage Tax System\n";
        std::cout << "14. Exit\n";
    }

    void run() {
        int choice;
        while (true) {
            displayMainMenu();
            std::cin >> choice;

            switch (choice) {
                case 1:
                    addBuilding();
                    break;
                case 2:
                    manageUtilities();
                    break;
                case 3:
                    manageResources();
                    break;
                case 4:
                    setGovernmentPolicies();
                    break;
                case 5:
                    addTransportation();
                    break;
                case 6:
                    cityOverview();
                    break;
                case 7:
                    displayRoads();
                    break;
                case 8:
                    displayCityMap();
                    break;
                case 9:
                    citizenManagementMenu();
                    break;
                case 10:
                    jobManagementMenu();
                    break;
                case 11:
                    buildingManagementMenu();
                    break;
                case 12:
                    financialManagementMenu();
                    break;
                case 13:
                    manageTaxSystem();
                    break;
                case 14:
                    std::cout << "Exiting the simulation.\n";
                    return;
                default:
                    std::cout << "Invalid choice. Try again.\n";
            }
        }
    }

    void displayCityMap() {
        std::vector<std::vector<char>> cityGrid(10, std::vector<char>(20, ' '));

        size_t index = 0;
        Transportation* transport;
        while ((transport = transportManager.getTransportation(index)) != nullptr) {
            char symbol;

            if (dynamic_cast<Highway*>(transport)) symbol = 'H';
            else if (dynamic_cast<InsideRoad*>(transport)) symbol = 'I';
            else if (dynamic_cast<Bus*>(transport)) symbol = 'B';
            else if (dynamic_cast<Taxi*>(transport)) symbol = 'T';
            else if (dynamic_cast<PassengerTrain*>(transport)) symbol = 'P';
            else if (dynamic_cast<FreightTrain*>(transport)) symbol = 'F';
            else if (dynamic_cast<ComercialAirport*>(transport)) symbol = 'A';
            else if (dynamic_cast<CargoAirport*>(transport)) symbol = 'C';
            else symbol = '?';

            int row = index % 10;
            int col = (index * 2) % 20;
            cityGrid[row][col] = symbol;
            ++index;
        }

        std::cout << (index == 0 ? "No transportation elements added.\n" : "City Transportation Map:\n");
        for (const auto& row : cityGrid) {
            for (const char cell : row) {
                std::cout << std::setw(2) << cell;
            }
            std::cout << '\n';
        }
        std::cout << "Legend: H=Highway, I=InsideRoad, B=Bus, T=Taxi, P=PassengerTrain, F=FreightTrain, A=ComercialAirport, C=CargoAirport\n";
    }

    void displayRoads() {
        int x = 0;
        Transportation *temp = transportManager.getTransportation(x);;

        while(temp != nullptr){
            if(temp->getType() == 'H'){
                Highway *H = static_cast<Highway*>(temp);
                std::cout << H->getRoadName() << std::endl;

            }
            else if(temp->getType() == 'I'){
                InsideRoad *I = static_cast<InsideRoad*>(temp);
                std::cout << I->getRoadName() << std::endl;
            }
            x++;
            temp = transportManager.getTransportation(x);
        }

    }

    void cityOverview() {
        Resource* waterResource = resourceManager.getResource(ResourceType::Water);
        Resource* powerResource = resourceManager.getResource(ResourceType::Power);

        std::cout << "\nCity Overview:\n";
        std::cout << "Number of buildings: " << buildingManager.getBuildings().size() << "\n";
        std::cout << "Current budget: " << resourceManager.getBudget() << "\n";
        std::cout << "Water resource available: " << (waterResource ? waterResource->getQuantity() : 0) << "\n";
        std::cout << "Power resource available: " << (powerResource ? powerResource->getQuantity() : 0) << "\n";

        size_t index = 0;
        Transportation* transport;
        std::cout << "Transportation options:\n";
        while ((transport = transportManager.getTransportation(index)) != nullptr) {
            std::string transportType;

            if (dynamic_cast<Highway*>(transport)) transportType = "Highway";
            else if (dynamic_cast<InsideRoad*>(transport)) transportType = "Inside Road";
            else if (dynamic_cast<Bus*>(transport)) transportType = "Bus";
            else if (dynamic_cast<Taxi*>(transport)) transportType = "Taxi";
            else if (dynamic_cast<PassengerTrain*>(transport)) transportType = "Passenger Train";
            else if (dynamic_cast<FreightTrain*>(transport)) transportType = "Freight Train";
            else if (dynamic_cast<ComercialAirport*>(transport)) transportType = "Commercial Airport";
            else if (dynamic_cast<CargoAirport*>(transport)) transportType = "Cargo Airport";
            else transportType = "Unknown";

            std::cout << "- Transportation " << index + 1 << ": " << transportType << "\n";
            ++index;
        }
        std::cout << "Total transportation options: " << index << "\n";
    }


    void addTransportation() {
    int choice;
    std::cout << "Choose transportation type:\n1. Bus\n2. Train\n3. Taxi\n4. Highway\n5. Inside Road\n6. Freight Train\n7. Commercial Airport\n8. Cargo Airport\n";
    std::cin >> choice;
    std::cin.ignore();  // Clear the newline character after reading an integer

    bool success = false;
    switch (choice) {
        case 1: {
            char state = 'N';
            std::string route;
            int busNumber, capacity;
            std::cout << "Enter route: ";
            std::getline(std::cin, route);
            std::cout << "Enter bus number: ";
            std::cin >> busNumber;
            std::cin.ignore();
            std::cout << "Enter capacity: ";
            std::cin >> capacity;
            std::cin.ignore();
            success = transportManager.createBus(state, route, busNumber, capacity);
            break;
        }
        case 2: {
            char state = 'P';
            std::string line;
            std::cout << "Enter train line: ";
            std::getline(std::cin, line);
            success = transportManager.createPassengerTrain(state, line);
            break;
        }
        case 3: {
            char state = 'N';
            std::string route, taxiCompany;
            int taxiNumber;
            std::cout << "Enter route: ";
            std::getline(std::cin, route);
            std::cout << "Enter taxi company: ";
            std::getline(std::cin, taxiCompany);
            std::cout << "Enter taxi number: ";
            std::cin >> taxiNumber;
            std::cin.ignore();
            success = transportManager.createTaxi(state, route, taxiCompany, taxiNumber);
            break;
        }
        case 4: {
            char state = 'N';
            std::string roadName;
            float speedLimit;
            std::cout << "Enter highway name: ";
            std::getline(std::cin, roadName);
            std::cout << "Enter speed limit: ";
            std::cin >> speedLimit;
            std::cin.ignore();
            success = transportManager.createHighway(state, roadName, speedLimit);
            break;
        }
        case 5: {
            char state = 'N';
            std::string roadName;
            float avgStopTime;
            std::cout << "Enter road name: ";
            std::getline(std::cin, roadName);
            std::cout << "Enter average stop time: ";
            std::cin >> avgStopTime;
            std::cin.ignore();
            success = transportManager.createInsideRoad(state, roadName, avgStopTime);
            break;
        }
        case 6: {
            char state = 'N';
            std::string line;
            float weight, length;
            std::cout << "Enter freight train line: ";
            std::getline(std::cin, line);
            std::cout << "Enter train weight: ";
            std::cin >> weight;
            std::cin.ignore();
            std::cout << "Enter train length: ";
            std::cin >> length;
            std::cin.ignore();
            success = transportManager.createFreightTrain(state, line, weight, length);
            break;
        }
        case 7: {
            char state = 'L';
            std::string name;
            std::cout << "Enter commercial airport name: ";
            std::getline(std::cin, name);
            success = transportManager.createComercialAirport(state, name);
            break;
        }
        case 8: {
            char state = 'P';
            std::string name;
            std::cout << "Enter cargo airport name: ";
            std::getline(std::cin, name);
            success = transportManager.createCargoAirport(state, name);
            break;
        }
        default:
            std::cout << "Invalid option.\n";
            return;
    }

    std::cout << (success ? "Transportation added successfully.\n" : "Failed to add transportation.\n");

    size_t transportCount = 0;
    while (transportManager.getTransportation(transportCount) != nullptr) {
        transportCount++;
    }
    std::cout << "Total transportation elements in TransportManager: " << transportCount << "\n";
}


    void setGovernmentPolicies() {
    int choice;
    std::cout << "Choose a government policy to set:\n";
    std::cout << "1. Set Tax Rate\n";
    std::cout << "2. Enforce Policy\n";
    std::cout << "3. Allocate Budget\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();

    switch (choice) {
        case 1: {
            float taxRate;
            std::cout << "Set a new tax rate (0-100%): ";
            std::cin >> taxRate;
            SetTaxCommand setTaxCommand(&government, taxRate);
            setTaxCommand.execute();
            std::cout << "Tax rate updated to " << taxRate << "% using SetTaxCommand.\n";
            break;
        }
        case 2: {
            std::string policyName, policyPriority;
            std::cout << "Enter policy name: ";
            std::getline(std::cin, policyName);
            std::cout << "Enter policy priority (High, Medium, Low): ";
            std::getline(std::cin, policyPriority);
            Policy policy(policyName, policyPriority);
            EnforcePolicyCommand enforcePolicyCommand(&government, policy);
            enforcePolicyCommand.execute();
            std::cout << "Policy \"" << policyName << "\" enforced with priority: " << policyPriority << ".\n";
            break;
        }
        case 3: {
            std::string serviceName;
            double budgetAmount;
            std::cout << "Enter service name to allocate budget: ";
            std::getline(std::cin, serviceName);
            std::cout << "Enter budget amount: ";
            std::cin >> budgetAmount;
            CityService cityService(serviceName, budgetAmount);
            AllocateBudgetCommand allocateBudgetCommand(&government, cityService, budgetAmount);
            allocateBudgetCommand.execute();
            std::cout << "Budget of " << budgetAmount << " allocated to " << serviceName << ".\n";
            break;
        }
        default:
            std::cout << "Invalid option.\n";
    }
}


    void manageResources() {
        int resourceChoice, quantity;
        std::cout << "Choose a resource to manage:\n1. Water\n2. Power\n";
        std::cin >> resourceChoice;
        std::cin.ignore();

        ResourceType resourceType = (resourceChoice == 1) ? ResourceType::Water : ResourceType::Power;
        Resource* resource = resourceManager.getResource(resourceType);

        if (resource) {
            std::cout << "Enter quantity to allocate (positive) or release (negative): ";
            std::cin >> quantity;
            std::cin.ignore();

            if (quantity > 0) {
                bool success = resourceManager.allocateResources(resourceType, quantity);
                std::cout << "Allocation of " << quantity << " units of "
                        << (resourceType == ResourceType::Water ? "Water" : "Power") << ": "
                        << (success ? "Success" : "Failed") << std::endl;
            } else {
                resourceManager.releaseResources(resourceType, -quantity);
                std::cout << "Released " << -quantity << " units of "
                        << (resourceType == ResourceType::Water ? "Water" : "Power") << std::endl;
            }

            std::cout << "Remaining " << (resourceType == ResourceType::Water ? "Water" : "Power")
                    << " resource quantity: " << resource->getQuantity() << std::endl;
        } else {   
            std::cout << "Resource not found.\n";
        }
    }

    void manageUtilities() {
        std::cout << "Managing utilities...\n";
        // Placeholder for utility management as `WaterSupply` and `WasteManagement` are unavailable.
        std::cout << "Utilities have been managed for all buildings.\n";
    }

    // Citizen Management
    void citizenManagementMenu() {
        int choice;
        while (true) {
            std::cout << "\nCitizen Management\n";
            std::cout << "1. Add Citizen\n";
            std::cout << "2. View Citizens\n";
            std::cout << "3. Assign Job to Citizen\n";
            std::cout << "4. Return to Main Menu\n";
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
                case 1:
                    addCitizen();
                    break;
                case 2:
                    displayCitizens();
                    break;
                case 3:
                    assignJobToCitizen();
                    break;
                case 4:
                    return;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }

    void addCitizen() {
        std::string name, gender;
        int age;
        std::cout << "Enter name: ";
        std::cin >> name;
        std::cin.ignore();
        std::cout << "Enter age: ";
        std::cin >> age;
        std::cin.ignore();
        std::cout << "Enter gender (M/F): ";
        std::cin >> gender;
        std::cin.ignore();

        if (gender == "M" || gender == "m") {
            citizens.push_back(std::make_shared<MaleCitizen>(name, age));
        } else if (gender == "F" || gender == "f") {
            citizens.push_back(std::make_shared<FemaleCitizen>(name, age));
        } else {
            std::cout << "Invalid gender.\n";
        }
    }

    void displayCitizens() const {
        for (const auto& citizen : citizens) {
            std::cout << "Name: " << citizen->getName() << ", Age: " << citizen->getAge()
                      << ", Satisfaction: " << citizen->getSatisfactionLevel() << "\n";
            std::cout << "Employment Status: " << (citizen->isEmployed() ? citizen->getJob() : "Unemployed") << "\n";
            std::cout << "Bank Balance: " << citizen->getBankBalance() << "\n";
            std::cout << "---------------------------\n";
        }
    }

    void assignJobToCitizen() {
    std::string citizenName, jobTitle;
    std::cout << "Enter citizen name: ";
    std::cin.ignore();
    std::getline(std::cin, citizenName);
    std::cout << "Enter job title: ";
    std::getline(std::cin, jobTitle);

    auto citizen = findCitizen(citizenName);
    auto job = findJob(jobTitle);

    if (citizen && job && !job->isOccupied()) {
        citizen->setJob(job);
        citizen->setEmployed(true);
        citizen->setJobTitle(job->getTitle());
        job->hireEmployee();
        std::cout << "Job assigned successfully to " << citizenName << "!\n";
    } else {
        std::cout << "Could not assign job. Either job is filled or citizen not found.\n";
    }
}



    std::shared_ptr<Citizen> findCitizen(const std::string& name) const {
        std::cout << "Searching for citizen: " << name << std::endl;
        for (const auto& citizen : citizens) {
            if (citizen->getName() == name) {
                std::cout << "Citizen found: " << name << std::endl;
                return citizen;
            }
        }
        std::cout << "Citizen not found: " << name << std::endl;
        return nullptr;
    }

    std::shared_ptr<Jobs> findJob(const std::string& title) const {
        std::cout << "Searching for job: " << title << std::endl;
        for (const auto& job : jobs) {
            if (job->getTitle() == title) {
                std::cout << "Job found: " << title << std::endl;
                return job;
            }
        }
        std::cout << "Job not found: " << title << std::endl;
        return nullptr;
    }


    // Job Management
    void jobManagementMenu() {
        int choice;
        while (true) {
            std::cout << "\nJob Management\n";
            std::cout << "1. Add Job\n";
            std::cout << "2. View Jobs\n";
            std::cout << "3. Return to Main Menu\n";
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
                case 1:
                    addJob();
                    break;
                case 2:
                    displayJobs();
                    break;
                case 3:
                    return;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }

    void addJob() {
        std::string title;
        double salary;
        std::cout << "Enter job title: ";
        std::cin.ignore();  // Ensure no leftover input interferes
        std::getline(std::cin, title);  // Use getline to allow multi-word titles
        std::cout << "Enter job salary: ";
        std::cin >> salary;

        jobs.push_back(std::make_shared<Jobs>(title, salary));
        std::cout << "Job added successfully!\n";
    }

    void displayJobs() const {
        for (const auto& job : jobs) {
            std::cout << "Job Title: " << job->getTitle() << ", Salary: " << job->getIncome()->getBaseSalary()
                      << ", Status: " << (job->isOccupied() ? "Occupied" : "Vacant") << "\n";
        }
    }

    // Building Management
    void buildingManagementMenu() {
        int choice;
        while (true) {
            std::cout << "\nBuilding Management\n";
            std::cout << "1. Add Building\n";
            std::cout << "2. View Buildings\n";
            std::cout << "3. Return to Main Menu\n";
            std::cin >> choice;
            std::cin.ignore();

            switch (choice) {
                case 1:
                    addBuilding();
                    break;
                case 2:
                    displayBuildings();
                    break;
                case 3:
                    return;
                default:
                    std::cout << "Invalid choice.\n";
            }
        }
    }

    void addBuilding() {
        int choice;
        std::cout << "\nChoose building type:\n1. Residential\n2. Commercial\n3. Industrial\n4. Landmark\n";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                ResidentialBuildingBuilder builder;
                builder.setName("Residential Complex")
                    .setArea(1200.0f)
                    .setFloors(5)
                    .setCapacity(100)
                    .setCitizenSatisfaction(3.0f)
                    .setEconomicGrowth(1.0f)
                    .setResourceConsumption(1.5f);
                auto residentialBuilding = builder.build();
                buildingManager.addBuilding(residentialBuilding.get());
                std::cout << "Residential building added.\n";
                break;
            }
            case 2: {
                CommercialBuildingBuilder builder;
                builder.setName("Business Center")
                    .setArea(2500.0f)
                    .setFloors(10)
                    .setCapacity(300)
                    .setCitizenSatisfaction(2.5f)
                    .setEconomicGrowth(5.0f)
                    .setResourceConsumption(2.0f);
                auto commercialBuilding = builder.build();
                buildingManager.addBuilding(commercialBuilding.get());
                std::cout << "Commercial building added.\n";
                break;
            }
            case 3: {
                IndustrialBuildingBuilder builder;
                builder.setName("Industrial Plant")
                    .setArea(3000.0f)
                    .setFloors(8)
                    .setCapacity(200)
                    .setCitizenSatisfaction(-1.0f)
                    .setEconomicGrowth(7.0f)
                    .setResourceConsumption(4.0f);
                auto industrialBuilding = builder.build();
                buildingManager.addBuilding(industrialBuilding.get());
                std::cout << "Industrial building added.\n";
                break;
            }
            case 4: {
                LandmarkBuildingBuilder builder;
                builder.setName("City Park")
                    .setArea(2000.0f)
                    .setFloors(1)
                    .setCapacity(500)
                    .setCitizenSatisfaction(5.0f)
                    .setEconomicGrowth(1.0f)
                    .setResourceConsumption(0.5f);
                auto landmarkBuilding = builder.build();
                buildingManager.addBuilding(landmarkBuilding.get());
                std::cout << "Landmark building added.\n";
                break;
            }
            default:
                std::cout << "Invalid option.\n";
        }
    }

    void displayBuildings() const {
        for (const auto& building : buildings) {
            std::cout << "Building Name: " << building->getName() << ", Type: " << building->getType() << "\n";
        }
    }

    void financialManagementMenu() {
    int choice;
    while (true) {
        std::cout << "\n--- Financial Management ---\n";
        std::cout << "1. View Current Budget\n";
        std::cout << "2. Allocate Budget for City Services\n";
        std::cout << "3. Return to Main Menu\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1: {
                // View Current Budget
                std::cout << "Current Budget: " << resourceManager.getBudget() << "\n";
                break;
            }
            case 2: {
                // Allocate Budget
                std::string serviceName;
                int amount;
                std::cout << "Enter the city service name to allocate budget: ";
                std::cin.ignore();
                std::getline(std::cin, serviceName);
                std::cout << "Enter the budget amount to allocate: ";
                std::cin >> amount;
                std::cin.ignore();

                if (amount > resourceManager.getBudget()) {
                    std::cout << "Insufficient budget. Current Budget: " << resourceManager.getBudget() << "\n";
                } else {
                    resourceManager.allocateBudget(serviceName, amount);
                    std::cout << "Allocated " << amount << " to " << serviceName << ".\n";
                    std::cout << "Remaining Budget: " << resourceManager.getBudget() << "\n";
                }
                break;
            }
            case 3:
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void manageTaxSystem() {
    bool running = true;
    while (running) {
        std::cout << "\nTax System Management\n";
        std::cout << "1. Create Citizen\n";
        std::cout << "2. Create Residential Building\n";
        std::cout << "3. Add Citizen to Residential Building\n";
        std::cout << "4. Set Tax Rates\n";
        std::cout << "5. Set Citizen Income and Job\n";
        std::cout << "6. Collect Taxes\n";
        std::cout << "7. Create Business\n";
        std::cout << "8. Create Commercial Building\n";
        std::cout << "9. Add Business to Commercial Building\n";
        std::cout << "10. Check impact of taxes\n";
        std::cout << "11. Back to Main Menu\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // Create Citizen
                std::string name;
                int age;
                char gender;
                std::cout << "Enter citizen's name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter age: ";
                std::cin >> age;
                std::cout << "Enter gender (M/F): ";
                std::cin >> gender;

                std::shared_ptr<Citizen> citizen;
                if (gender == 'M' || gender == 'm') {
                    citizen = std::make_shared<MaleCitizen>(name, age);
                } else if (gender == 'F' || gender == 'f') {
                    citizen = std::make_shared<FemaleCitizen>(name, age);
                } else {
                    std::cout << "Invalid gender input.\n";
                    break;
                }

                // Assign satisfaction strategies
                citizen->addSatisfactionStrategy(std::make_shared<JobSatisfactionStrategy>());
                citizen->addSatisfactionStrategy(std::make_shared<HousingSatisfactionStrategy>());
                citizen->addSatisfactionStrategy(std::make_shared<TaxSatisfactionStrategy>());

                // Attach SatisfactionObserver
                auto satisfactionObserver = std::make_shared<CitizenSatisfactionObserver>();
                citizen->addObserver(satisfactionObserver.get());

                // Add citizen to population manager
                populationManager.addCitizen(citizen);

                std::cout << "Citizen " << name << " created and added to population.\n";
                break;
            }
            case 2: {
                // Create Residential Building
                ResidentialBuildingBuilder builder;
                std::string name;
                float area;
                int floors, capacity;
                float citizenSatisfaction, economicGrowth, resourceConsumption;

                std::cout << "Enter building name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter area: ";
                std::cin >> area;
                std::cout << "Enter number of floors: ";
                std::cin >> floors;
                std::cout << "Enter capacity: ";
                std::cin >> capacity;
                std::cout << "Enter citizen satisfaction impact: ";
                std::cin >> citizenSatisfaction;
                std::cout << "Enter economic growth impact: ";
                std::cin >> economicGrowth;
                std::cout << "Enter resource consumption: ";
                std::cin >> resourceConsumption;

                builder.setName(name)
                       .setArea(area)
                       .setFloors(floors)
                       .setCapacity(capacity)
                       .setCitizenSatisfaction(citizenSatisfaction)
                       .setEconomicGrowth(economicGrowth)
                       .setResourceConsumption(resourceConsumption);

                auto residentialBuilding = builder.build();
                resbuildings.push_back(std::move(residentialBuilding)); // Add to global vector
                buildingManager.addBuilding(resbuildings.back().get());
                
                std::cout << "Residential building " << name << " added.\n";
                break;
            }
            case 3: {
                // Add Citizen to Residential Building
                if (populationManager.getCitizens().empty()) {
                    std::cout << "No citizens available. Please create citizens first.\n";
                    break;
                }
                if (resbuildings.empty()) {
                    std::cout << "No residential buildings available. Please create buildings first.\n";
                    break;
                }

                std::cout << "Available Citizens:\n";
                int index = 1;
                for (const auto& citizen : populationManager.getCitizens()) {
                    std::cout << index++ << ". " << citizen->getName() << "\n";
                }

                std::cout << "Select a citizen to add: ";
                int citizenChoice;
                std::cin >> citizenChoice;

                if (citizenChoice < 1 || citizenChoice > populationManager.getCitizens().size()) {
                    std::cout << "Invalid citizen choice.\n";
                    break;
                }

                std::cout << "Available Residential Buildings:\n";
                index = 1;
                for (const auto& building : resbuildings) {
                    std::cout << index++ << ". " << building->getName() << "\n";
                }

                std::cout << "Select a building to add the citizen to: ";
                int buildingChoice;
                std::cin >> buildingChoice;

                if (buildingChoice < 1 || buildingChoice > resbuildings.size()) {
                    std::cout << "Invalid building choice.\n";
                    break;
                }

                auto citizen = populationManager.getCitizens()[citizenChoice - 1];
                auto& building = resbuildings[buildingChoice - 1];
                building->addCitizen(citizen.get());
                std::cout << "Citizen " << citizen->getName() << " added to " << building->getName() << ".\n";
                break;
            }
        case 4: {
    // Set Tax Rates
    double taxRate;
    std::cout << "Enter new overall tax rate (0-100%): ";
    std::cin >> taxRate;

    SetTaxCommand setTaxCommand(&government, taxRate);
    setTaxCommand.execute();
    std::cout << "Overall tax rate set to " << taxRate << "%.\n";

    char taxType;
    double rate;
    std::cout << "Set specific tax rates.\n";
    std::cout << "Enter tax type (I - Income, P - Property, S - Sales): ";
    std::cin >> taxType;
    std::cout << "Enter tax rate for this type (0-100%): ";
    std::cin >> rate;

    std::shared_ptr<TaxType> tax;
    if (taxType == 'I' || taxType == 'i') {
        tax = std::make_shared<Income>(5000, rate / 100.0, 'I');
    } else if (taxType == 'P' || taxType == 'p') {
        double municipalLevy, additionalFees;
        std::cout << "Enter municipal levy: ";
        std::cin >> municipalLevy;
        std::cout << "Enter additional fees: ";
        std::cin >> additionalFees;
        tax = std::make_shared<Property>(rate / 100.0, municipalLevy, additionalFees);
    } else if (taxType == 'S' || taxType == 's') {
        double environmentalLevy, serviceFee;
        std::cout << "Enter environmental levy: ";
        std::cin >> environmentalLevy;
        std::cout << "Enter service fee: ";
        std::cin >> serviceFee;
        tax = std::make_shared<Sales>(rate / 100.0, environmentalLevy, serviceFee);
    } else {
        std::cout << "Invalid tax type.\n";
        break;
    }

    government.getTaxSystem()->addSharedTaxRate(tax);
    std::cout << "Tax rate for type " << taxType << " set to " << rate << "%.\n";
    break;
}
            case 5: {
                // Set Citizen Income and Job
                if (populationManager.getCitizens().empty()) {
                    std::cout << "No citizens available. Please create citizens first.\n";
                    break;
                }

                std::cout << "Available Citizens:\n";
                int index = 1;
                for (const auto& citizen : populationManager.getCitizens()) {
                    std::cout << index++ << ". " << citizen->getName() << "\n";
                }

                std::cout << "Select a citizen to set income and job: ";
                int citizenChoice;
                std::cin >> citizenChoice;

                if (citizenChoice < 1 || citizenChoice > populationManager.getCitizens().size()) {
                    std::cout << "Invalid citizen choice.\n";
                    break;
                }

                double incomeAmount;
                double taxRate;
                std::string jobTitle;
                std::cout << "Enter income amount: ";
                std::cin >> incomeAmount;
                std::cout << "Enter income tax rate (0-100%): ";
                std::cin >> taxRate;
                std::cout << "Enter job title: ";
                std::cin.ignore();
                std::getline(std::cin, jobTitle);

                auto income = std::make_shared<Income>(incomeAmount,taxRate / 100.0,'I');
                auto citizen = populationManager.getCitizens()[citizenChoice - 1];
                auto job = std::make_shared<Jobs>(jobTitle, incomeAmount);
                citizen->setIncome(income);
                citizen->setJob(job);
                citizen->setBankBalance(citizen->getBankBalance() + incomeAmount);
                std::cout << "Income and job set for " << citizen->getName() << ".\n";
                break;
            }
            case 6: {
                // Collect Taxes
                if(resbuildings.empty() && comBuildings.empty()){
                    std::cout << "No buildings available. Please create buildings first.\n";
                    break;
                }

                std::cout << "Available ResBuildings:\n";
                int index = 1;
                for (const auto& building : resbuildings) {
                    std::cout << index++ << ". " << building->getName() << " (" << building->getType() << ")\n";
                }
                int resBuildingCount = index - 1;

                std::cout << "Available comBuildings:\n";
                for (const auto& building : comBuildings) {
                    std::cout << index++ << ". " << building->getName() << " (" << building->getType() << ")\n";
                }

                std::cout << "Select a building to collect taxes from: ";
                int buildingChoice;
                std::cin >> buildingChoice;

                if (buildingChoice < 1 || buildingChoice > resBuildingCount + comBuildings.size()) {
                    std::cout << "Invalid building choice.\n";
                    break;
                }

                char taxType;
                std::cout << "Enter tax type to collect (I - Income, P - Property, S - Sales): ";
                std::cin >> taxType;

                std::shared_ptr<Building> building;
                if (buildingChoice <= resBuildingCount) {
                    building = resbuildings[buildingChoice - 1];
                } else {
                    building = comBuildings[buildingChoice - resBuildingCount - 1];
                }
                
                government.getTaxSystem()->collectTaxes(building.get(), taxType);

                std::cout << "Taxes collected from " << building->getName() << ".\n";
                break;
            }
            case 7: {
                // Create Business
                std::string name;
                double revenue, taxRate;
                std::cout << "Enter business name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter revenue: ";
                std::cin >> revenue;
                std::cout << "Enter tax rate (0-100%): ";
                std::cin >> taxRate;

                auto business = std::make_shared<Business>(revenue, taxRate / 100.0, name);
                std::cout << "Business " << name << " created.\n";
                // Store business in some collection if needed
                // For simplicity, we'll add it directly to a building in option 9
                break;
            }
            case 8: {
                // Create Commercial Building
                CommercialBuildingBuilder builder;
                std::string name;
                float area;
                int floors, capacity;
                float citizenSatisfaction, economicGrowth, resourceConsumption;

                std::cout << "Enter building name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                std::cout << "Enter area: ";
                std::cin >> area;
                std::cout << "Enter number of floors: ";
                std::cin >> floors;
                std::cout << "Enter capacity: ";
                std::cin >> capacity;
                std::cout << "Enter citizen satisfaction impact: ";
                std::cin >> citizenSatisfaction;
                std::cout << "Enter economic growth impact: ";
                std::cin >> economicGrowth;
                std::cout << "Enter resource consumption: ";
                std::cin >> resourceConsumption;

                builder.setName(name)
                       .setArea(area)
                       .setFloors(floors)
                       .setCapacity(capacity)
                       .setCitizenSatisfaction(citizenSatisfaction)
                       .setEconomicGrowth(economicGrowth)
                       .setResourceConsumption(resourceConsumption);

                auto commercialBuilding = builder.build();
                comBuildings.push_back(std::move(commercialBuilding)); // Add to global vector
                buildingManager.addBuilding(comBuildings.back().get());

                std::cout << "Commercial building " << name << " added.\n";
                break;
            }
            case 9: {
                // Add Business to Commercial Building
                if (comBuildings.empty()) {
                    std::cout << "No commercial buildings available.\n";
                    break;
                }

                std::string businessName;
                double revenue, taxRate;
                std::cout << "Enter business name: ";
                std::cin.ignore();
                std::getline(std::cin, businessName);
                std::cout << "Enter revenue: ";
                std::cin >> revenue;
                std::cout << "Enter tax rate (0-100%): ";
                std::cin >> taxRate;

                auto business = std::make_shared<Business>(revenue, taxRate / 100.0, businessName);

                std::cout << "Available Commercial Buildings:\n";
                int index = 1;
                for (const auto& building : comBuildings) {
                    std::cout << index++ << ". " << building->getName() << "\n";
                }

                std::cout << "Select a building to add the business to: ";
                int buildingChoice;
                std::cin >> buildingChoice;

                if (buildingChoice < 1 || buildingChoice > comBuildings.size()) {
                    std::cout << "Invalid building choice.\n";
                    break;
                }

                auto building = comBuildings[buildingChoice - 1];
                building->addBusiness(business);
                std::cout << "Business " << business->getName() << " added to " << building->getName() << ".\n";
                break;
            }
         case 10: {
    // Check impact of taxes
    std::cout << "Checking impact of taxes...\n";

    // Iterate through each tax type in the taxRates map
    for (const auto& taxRatePair : government.getTaxSystem()->getTaxRates()) {
        char taxType = taxRatePair.first;
        std::shared_ptr<TaxType> tax = taxRatePair.second;

        if (taxType == 'I' || taxType == 'i') {
            // Check impact on residential buildings for income tax
            for (const auto& building : resbuildings) {
                government.getTaxSystem()->checkImpact(building.get(), tax);
            }
        } else if (taxType == 'P' || taxType == 'p') {
            // Check impact on residential and commercial buildings for property tax
            for (const auto& building : resbuildings) {
                government.getTaxSystem()->checkImpact(building.get(), tax);
            }
            for (const auto& building : comBuildings) {
                government.getTaxSystem()->checkImpact(building.get(), tax);
            }
        } else if (taxType == 'S' || taxType == 's') {
            // Check impact on commercial buildings for sales tax
            for (const auto& building : comBuildings) {
                government.getTaxSystem()->checkImpact(building.get(), tax);
            }
        } else {
            std::cout << "Unknown tax type: " << taxType << "\n";
        }
    }
    break;
}    case 11: {
                running = false;
                break;
            }
            default:
                std::cout << "Invalid option.\n";
                break;
        }
    }
}

};

int main() {
    CitySimulationUI ui;
    ui.run();
    return 0;
}
