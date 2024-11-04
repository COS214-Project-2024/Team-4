#include <iostream>
#include <memory>
#include <vector>
#include "PopulationManager.h"
#include "BuildingManager.h"
#include "Citizen.h"
#include "MaleCitizen.h"
#include "FemaleCitizen.h"
#include "JobSatisfactionStrategy.h"
#include "HousingSatisfactionStrategy.h"
#include "TaxSatisfactionStrategy.h"
#include "ResidentialBuildingBuilder.h"
#include "CommercialBuildingBuilder.h"
#include "CitizenObserver.h"
#include "CitizenSatisfactionObserver.h"

int main() {
    // Step 1: Create instances of Residential and Commercial buildings
    ResidentialBuildingBuilder residentialBuilder;
    residentialBuilder.setName("Residential Complex")
                      .setArea(1000)
                      .setFloors(15)
                      .setCapacity(200)
                      .setCitizenSatisfaction(20.0f)
                      .setEconomicGrowth(10.0f)
                      .setResourceConsumption(15.0f);
    auto residentialBuilding = residentialBuilder.build();

    CommercialBuildingBuilder commercialBuilder;
    commercialBuilder.setName("Innovation Hub")
                     .setArea(2000)
                     .setFloors(10)
                     .setCapacity(400)
                     .setCitizenSatisfaction(25.0f)
                     .setEconomicGrowth(20.0f)
                     .setResourceConsumption(30.0f);
    auto commercialBuilding = commercialBuilder.build();

    residentialBuilding->addJob(std::make_shared<Jobs>("Engineer", 5000));
    residentialBuilding->addJob(std::make_shared<Jobs>("Architect", 6000));
    commercialBuilding->addJob(std::make_shared<Jobs>("Designer", 5500));
    commercialBuilding->addJob(std::make_shared<Jobs>("Developer", 7000));

    // Step 2: Initialize BuildingManager with shared_ptr buildings
    std::vector<std::shared_ptr<Building>> buildings = {
        std::move(residentialBuilding),
        std::move(commercialBuilding)
    };
    BuildingManager buildingManager(buildings);

    // Step 3: Initialize PopulationManager
    PopulationManager populationManager;

    // Step 4: Create citizens and assign satisfaction strategies
    auto citizen1 = std::make_shared<MaleCitizen>("John Doe", 30);
    auto citizen2 = std::make_shared<FemaleCitizen>("Jane Smith", 28);
    auto citizen3 = std::make_shared<FemaleCitizen>("Janet Smithy", 28);

    // Assign satisfaction strategies to each citizen
    citizen1->addSatisfactionStrategy(std::make_shared<JobSatisfactionStrategy>());
    citizen1->addSatisfactionStrategy(std::make_shared<HousingSatisfactionStrategy>());
    citizen1->addSatisfactionStrategy(std::make_shared<TaxSatisfactionStrategy>());

    citizen2->addSatisfactionStrategy(std::make_shared<JobSatisfactionStrategy>());
    citizen2->addSatisfactionStrategy(std::make_shared<HousingSatisfactionStrategy>());
    citizen2->addSatisfactionStrategy(std::make_shared<TaxSatisfactionStrategy>());

    citizen3->addSatisfactionStrategy(std::make_shared<JobSatisfactionStrategy>());
    citizen3->addSatisfactionStrategy(std::make_shared<HousingSatisfactionStrategy>());
    citizen3->addSatisfactionStrategy(std::make_shared<TaxSatisfactionStrategy>());

    // Add citizens to population manager
    populationManager.addCitizen(citizen1);
    populationManager.addCitizen(citizen2);
    populationManager.addCitizen(citizen3);

    // Step 5: Attach SatisfactionObserver to monitor citizen satisfaction
    auto satisfactionObserver = std::make_shared<CitizenSatisfactionObserver>();
    citizen1->addObserver(satisfactionObserver.get());
    citizen2->addObserver(satisfactionObserver.get());
    citizen3->addObserver(satisfactionObserver.get());

    // Step 6: Citizens search for jobs using BuildingManager
    std::cout << "\n--- Job Application Process ---\n";
    citizen1->searchAndApplyForJob(buildingManager, buildings[1].get(), "Developer");
    citizen2->searchAndApplyForJob(buildingManager, buildings[0].get(), "Engineer");
    citizen3->searchAndApplyForJob(buildingManager, buildings[0].get(), "Engineer");

    // Step 7: Update satisfaction to check the impact of job changes
    std::cout << "\n--- Satisfaction Updates ---\n";
    citizen1->updateSatisfaction();
    citizen2->updateSatisfaction();
    citizen3->updateSatisfaction();

    // Step 8: Display initial satisfaction levels
    std::cout << "\n--- Initial Citizen Satisfaction Levels ---\n";
    std::cout << citizen1->getName() << " Satisfaction Level: " << citizen1->getSatisfactionLevel() << "%\n";
    std::cout << citizen2->getName() << " Satisfaction Level: " << citizen2->getSatisfactionLevel() << "%\n";
    std::cout << citizen3->getName() << " Satisfaction Level: " << citizen3->getSatisfactionLevel() << "%\n";

    // Simulation loop over several cycles (e.g., 12 months)
    for (int month = 1; month <= 12; ++month) {
        std::cout << "\n--- Month " << month << " ---\n";

        // Simulate population growth (randomly add/remove citizens)
        

        // Manage relationships between citizens
        populationManager.manageRelationships();

        // Update citizens' ages and apply any changes due to reaching milestones
        populationManager.updateCitizensAge();


        // Check and update citizen states based on satisfaction levels
        populationManager.checkCitizenStates();

                // Update satisfaction levels for all citizens
        populationManager.updateCitizensSatisfaction();

        populationManager.findJobsForUnemployedCitizens(buildingManager);

        
        // Display current relationship statuses and satisfaction levels
        std::cout << "\n--- Current Population and Satisfaction ---\n";
        for (const auto& citizen : populationManager.getCitizens()) {
            std::cout << citizen->getName()
                      << " (Age: " << citizen->getAge() << ", "
                      << "Status: " << citizen->getRelationshipStatus() << ", "
                      << "Satisfaction Level: " << citizen->getSatisfactionLevel() << "%)\n";
        }

        populationManager.simulatePopulationGrowth();
    }



    std::cout << "\n--- Final Population Summary ---\n";
    std::cout << "Total Population: " << populationManager.getPopulation() << "\n";

    return 0;
}






