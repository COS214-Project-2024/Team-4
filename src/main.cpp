#include <iostream>
#include <memory>
#include "ResidentialBuildingBuilder.h"
#include "CommercialBuildingBuilder.h"
#include "IndustrialBuildingBuilder.h"
#include "LandmarkBuildingBuilder.h"
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

//utilities includes
#include "UtilityMediator.h"
#include "Utility.h"
#include "WaterSupply.h"
#include "WasteManagement.h"

// Resource management includes
#include "ResourceManager.h"
#include "Resource.h"
#include "ResourceType.h"
#include "ResourceAvailability.h"
//GOV includes
#include "Government.h"
#include "SetTaxCommand.h"
#include "EnforcePolicyCommand.h"
#include "AllocateBudgetCommand.h"
#include "CollectTaxesCommand.h"
#include "CityService.h"
#include "Policy.h"
#include "Business.h"

//Transportation includes
#include "Transportation.h"
#include "Airport.h"
#include "Train.h"
#include "PublicTransit.h"
#include "Road.h"
#include "TransportationFactory.h"
#include "TransportManager.h"
#include "Highway.h"
#include "InsideRoad.h"
#include "Bus.h"
#include "FreightTrain.h"
#include "PassengerTrain.h"
#include "Taxi.h"
#include "ComercialAirport.h"
#include "CargoAirport.h"
#include "createTraverser.h"
#include "CityTraverser.h"

void testResidentialBuildingBuilder();
void testCommercialBuildingBuilder();
void testIndustrialBuildingBuilder();
void testLandmarkBuildingBuilder();
void testUtilities();
void testResourceManager();
void testGOVF1();
void TESTGOVCOMMAND();
void testcit();
void TRANSPORTATION_TEST();

int main() {
    // Testing each builder class separately
    testResidentialBuildingBuilder();
    testCommercialBuildingBuilder();
    testIndustrialBuildingBuilder();
    testLandmarkBuildingBuilder();
    testUtilities();
    testResourceManager();
    testcit();

    std::cout << "============================GOVT1========================" << std::endl;
    TESTGOVCOMMAND();
    std::cout << "============================GOVT2========================" << std::endl;
    testGOVF1();
    std::cout << "\033[1;32m============================TRANSPORTATION========================\033[0m" << std::endl;
    // TRANSPORTATION_TEST();
    std::cout << "\033[1;32mAll tests completed.\033[0m\n";
  
    return 0;
}

// Test ResidentialBuildingBuilder
void testResidentialBuildingBuilder() {
    std::cout << "\nTesting ResidentialBuildingBuilder\n";

    ResidentialBuildingBuilder builder;
    builder.setName("Green Villa")
           .setArea(1200.0f)
           .setFloors(2)
           .setCapacity(60)
           .setCitizenSatisfaction(2.5f)
           .setEconomicGrowth(1.5f)
           .setResourceConsumption(1.0f);                // Residential-specific method

builder.setResidentialUnit(30);
builder.setComfort(4.0f);
    auto residentialBuilding = builder.build();
    residentialBuilding->construct();
    residentialBuilding->updateImpacts();

    //testing specific funtions in residential builder
    std::cout<<"Testing getResidentialUnit:"<<builder.getResidentialUnit()<<std::endl;
    std::cout<<"Testing getComfort:"<<builder.getComfort()<<std::endl;

    //testing building
ResidentialBuilding resbuild = ResidentialBuilding("Green Villa", 1200.0f, 2, 60, 2.5f, 1.5f, 1.0f, 30, 4.0f);
    resbuild.construct();
    resbuild.updateImpacts();
    resbuild.upgradeComfort(1.0f);
   // resbuild.calculateEconomicImpact();
    //resbuild.calculateResourceConsumption();
    //resbuild.calculateSatisfactionImpact();
    //resbuild.hostEvent(10);
    //resbuild.calculateEconomicImpact();
    //resbuild.calculateResourceConsumption();
    //resbuild.calculateSatisfactionImpact();
    resbuild.updateImpacts();

    resbuild.construct();
    resbuild.getType();
    
}

// Test CommercialBuildingBuilder
void testCommercialBuildingBuilder() {
    std::cout << "\nTesting CommercialBuildingBuilder\n";

    CommercialBuildingBuilder builder;
    builder.setName("Sunset Mall")
           .setArea(3000.0f)
           .setFloors(3)
           .setCapacity(200)
           .setCitizenSatisfaction(1.8f)
           .setEconomicGrowth(3.0f)
           .setResourceConsumption(2.5f);

builder.setBusinessUnits(50);
builder.setCustomerTraffic(500);
    auto commercialBuilding = builder.build();
    commercialBuilding->construct();
    commercialBuilding->updateImpacts();
}

// Test IndustrialBuildingBuilder
void testIndustrialBuildingBuilder() {
    std::cout << "\nTesting IndustrialBuildingBuilder\n";

    IndustrialBuildingBuilder builder;
    builder.setName("Tech Factory")
           .setArea(5000.0f)
           .setFloors(5)
           .setCapacity(300)
           .setCitizenSatisfaction(-1.0f)
           .setEconomicGrowth(4.5f)
           .setResourceConsumption(3.0f);

builder.setPollutionLevel(2.0f);
builder.setProductionCapacity(10.0f);
    auto industrialBuilding = builder.build();
    industrialBuilding->construct();
    industrialBuilding->updateImpacts();
}

// Test LandmarkBuildingBuilder
void testLandmarkBuildingBuilder() {
    std::cout << "\nTesting LandmarkBuildingBuilder\n";

    LandmarkBuildingBuilder builder;
    builder.setName("National Museum")
           .setArea(4000.0f)
           .setFloors(4)
           .setCapacity(250)
           .setCitizenSatisfaction(5.0f)
           .setEconomicGrowth(2.5f)
           .setResourceConsumption(1.5f);             
           // Landmark-specific method

builder.setVisitorCapacity(1000);
builder.setCulturalValue(10.0f);
builder.setIsHistoric(true);
    auto landmarkBuilding = builder.build();
    landmarkBuilding->construct();
    landmarkBuilding->updateImpacts();
}

//test Utilities water supply and waste management
void testUtilities() {
    std::cout << "\nTesting Utilities\n";

    // Create mediator
    UtilityMediator mediator;

    // Create water supply and waste management utilities
    WaterSupply waterSupply(&mediator);
    WasteManagement wasteManagement(&mediator);

    // Register buildings with utilities
    // Building building1("Building 1", 1000.0f, 2, 50, 3.0f, 2.0f, 1.0f);
    // Building building2("Building 2", 2000.0f, 3, 100, 2.5f, 1.5f, 1.5f);
    //registering buildings (commercial,landmark and industrial)
    CommercialBuildingBuilder builder;
    builder.setName("Sunset Mall")
           .setArea(3000.0f)
           .setFloors(3)
           .setCapacity(200)
           .setCitizenSatisfaction(1.8f)
           .setEconomicGrowth(3.0f)
           .setResourceConsumption(2.5f);
    
    builder.setBusinessUnits(50);
    builder.setCustomerTraffic(500);
    auto commercialBuilding = builder.build();
    commercialBuilding->construct();
    commercialBuilding->updateImpacts();
    // waterSupply.registerBuilding(commercialBuilding.get());

    LandmarkBuildingBuilder builder1;
    builder1.setName("National Museum")
           .setArea(4000.0f)
           .setFloors(4)
           .setCapacity(250)
           .setCitizenSatisfaction(5.0f)
           .setEconomicGrowth(2.5f)
           .setResourceConsumption(1.5f);             
           // Landmark-specific method
    
    builder1.setVisitorCapacity(1000);
    builder1.setCulturalValue(10.0f);
    builder1.setIsHistoric(true);
    auto landmarkBuilding = builder1.build();
    landmarkBuilding->construct();
    landmarkBuilding->updateImpacts();
    // waterSupply.registerBuilding(landmarkBuilding.get());


    waterSupply.registerBuilding(commercialBuilding.get());
    waterSupply.registerBuilding(landmarkBuilding.get());

    wasteManagement.registerBuilding(commercialBuilding.get());
    wasteManagement.registerBuilding(landmarkBuilding.get());

    // Supply resources to buildings
    waterSupply.supplyResources(commercialBuilding.get());
    waterSupply.supplyResources(landmarkBuilding.get());

    wasteManagement.supplyResources(commercialBuilding.get());
    wasteManagement.supplyResources(landmarkBuilding.get());

    // Adjust utilities based on citizens
    // Citizen citizen1("Citizen 1", 25, 1.0f, 1.0f, 1.0f);
    // Citizen citizen2("Citizen 2", 30, 1.5f, 1.5f, 1.5f);

    // waterSupply.adjustForCitizen(&citizen1);
    // waterSupply.adjustForCitizen(&citizen2);

    // wasteManagement.adjustForCitizen(&citizen1);
    // wasteManagement.adjustForCitizen(&citizen2);
}

void testResourceManager() {
    std::cout << "\nTesting ResourceManager\n";

    // Create a ResourceManager with an initial budget of 1000
    ResourceManager resourceManager(1000);

    // Create Resource objects
    Resource* waterResource = new Resource(ResourceType::Water, 200);
    Resource* powerResource = new Resource(ResourceType::Power, 300);

    // Add resources to the ResourceManager
    resourceManager.addResource(ResourceType::Water, waterResource);
    resourceManager.addResource(ResourceType::Power, powerResource);

    // Test getResource method
    Resource* retrievedWaterResource = resourceManager.getResource(ResourceType::Water);
    if (retrievedWaterResource) {
        std::cout << "Water resource found with quantity: " << retrievedWaterResource->getQuantity() << std::endl;
    } else {
        std::cout << "Water resource not found.\n";
    }

    // Allocate resources and test results
    bool allocationSuccess = resourceManager.allocateResources(ResourceType::Water, 50);
    std::cout << "Allocation of 50 units of Water: " << (allocationSuccess ? "Success" : "Failed") << std::endl;
    std::cout << "Remaining Water resource quantity: " << retrievedWaterResource->getQuantity() << std::endl;

    // Release resources and check quantity
    resourceManager.releaseResources(ResourceType::Water, 20);
    std::cout << "After releasing 20 units, Water resource quantity: " << retrievedWaterResource->getQuantity() << std::endl;

    // Clean up dynamically allocated resources
    delete waterResource;
    delete powerResource;
}
//=========================================================================================================
//                                            GOV TESTING :
//=========================================================================================================
void testGOVF1() {
    // Create a CityService instance
    CityService cityService("Public Transport", 1000.0);
    // Test setServiceName and getServiceName
    cityService.setServiceName("Healthcare");
    std::cout << "Service Name: " << cityService.getServiceName() << std::endl;
    // Test printDetails
    cityService.printDetails();
    // Test isWithinBudget
    std::cout << "Is within budget (500): " << cityService.isWithinBudget(500) << std::endl;
    std::cout << "Is within budget (1500): " << cityService.isWithinBudget(1500) << std::endl;
    // Test allocateAdditionalBudget
    try {
        cityService.allocateAdditionalBudget(200, 500);
        cityService.printDetails();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Test reduceBudget
    try {
        cityService.reduceBudget(300);
        cityService.printDetails();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Create a Business instance
    Business business(5000.0, 10.0);
    // Test addService and removeService
    business.addService("Consulting");
    business.addService("IT Support");
    business.printDetails();
    business.removeService("Consulting");
    business.printDetails();
    // Test addPolicy and removePolicy
    Policy policy1("Policy1", "High");
    Policy policy2("Policy2", "Medium");
    business.addPolicy(policy1);
    business.addPolicy(policy2);
    business.printDetails();
    business.removePolicy(policy1);
    business.printDetails();
    // Test calculateTax
    std::cout << "Calculated Tax: " << business.calculateTax() << std::endl;
    // Test payTax
    business.payTax(business.calculateTax());
    business.printDetails();
}

void TESTGOVCOMMAND() {

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

    std::shared_ptr<Building> residentialBuilding1 = std::move(residentialBuilding);
    // Create a Government instance
    Government government("City Government");
    // Create a CityService instance
    CityService cityService("Public Transport", 1000.0);
    // Create a Policy instance
    Policy policy("Policy1", "High");

    TaxType taxtype(150 , 'I')  ;
    // Create command instances
    SetTaxCommand setTaxCommand(&government, 15.0);
    EnforcePolicyCommand enforcePolicyCommand(&government, policy);
    AllocateBudgetCommand allocateBudgetCommand(&government, cityService, 500.0);
    CollectTaxesCommand collectTaxesCommand(&government ,residentialBuilding1, &taxtype);
    // Execute commands
    std::cout << "Executing SetTaxCommand..." << std::endl;
    setTaxCommand.execute();
    std::cout << "Executing EnforcePolicyCommand..." << std::endl;
    enforcePolicyCommand.execute();
    std::cout << "Executing AllocateBudgetCommand..." << std::endl;
    allocateBudgetCommand.execute();
    std::cout << "Executing CollectTaxesCommand..." << std::endl;
    collectTaxesCommand.execute();
    // Undo commands
    std::cout << "Undoing SetTaxCommand..." << std::endl;
    setTaxCommand.undo();
    std::cout << "Undoing AllocateBudgetCommand..." << std::endl;
    allocateBudgetCommand.undo();
    std::cout << "Undoing CollectTaxesCommand..." << std::endl;
    collectTaxesCommand.undo();
    // Test new command functions
    std::cout << "Testing new command functions..." << std::endl;
    // Test getName and getDescription for SetTaxCommand
    std::cout << "SetTaxCommand Name: " << setTaxCommand.getName() << std::endl;
    std::cout << "SetTaxCommand Description: " << setTaxCommand.getDescription() << std::endl;
    // Test canExecute for SetTaxCommand
    std::cout << "Can execute SetTaxCommand: " << setTaxCommand.canExecute() << std::endl;
    // Test executeWithValidation for AllocateBudgetCommand
    try {
        allocateBudgetCommand.executeWithValidation();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Test validateCollection for CollectTaxesCommand
    std::cout << "Can execute CollectTaxesCommand: " << collectTaxesCommand.validateCollection() << std::endl;
    // Test executeWithValidation for CollectTaxesCommand
    try {
        collectTaxesCommand.executeWithValidation();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    // Test isPolicyEnforced for EnforcePolicyCommand
    std::cout << "Is policy enforced: " << enforcePolicyCommand.isPolicyEnforced() << std::endl;
    // Test executeWithValidation for EnforcePolicyCommand
    try {
        enforcePolicyCommand.executeWithValidation();
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}


//=============================================================================================
//                                    END    GOV    TESTING
//=============================================================================================


//=========================================================================================================
//                                            CIT TESTING :
//=========================================================================================================
void testcit(){
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
                      << "Satisfaction Level: " << citizen->getSatisfactionLevel() << "% ," << "Job title: " << citizen->getJob()<< ")\n";
        }

        populationManager.simulatePopulationGrowth();
    }



    std::cout << "\n--- Final Population Summary ---\n";
    std::cout << "Total Population: " << populationManager.getPopulation() << "\n";

}
//=============================================================================================
//                                    END    CIT    TESTING
//=============================================================================================

//=============================================================================================
//                                    START TRANSPORTATION TESTING
//=============================================================================================

void TRANSPORTATION_TEST(){
    // ANSI escape codes for styles
    const std::string RESET = "\033[0m";
    const std::string BOLD = "\033[1m";
    const std::string DIM = "\033[2m";
    const std::string UNDERLINED = "\033[4m";
    const std::string BLINK = "\033[5m";
    const std::string REVERSE = "\033[7m";
    const std::string HIDDEN = "\033[8m";

    // ANSI escape codes for colors
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";

    // ANSI escape codes for background colors
    const std::string BG_RED = "\033[41m";
    const std::string BG_GREEN = "\033[42m";

    TransportManager transportManager;
    transportManager.createHighway('P',"N1", 120);
    transportManager.createInsideRoad('N',"N2", 2);
    transportManager.createBus('N', "Bus1", 50, 25);
    transportManager.createFreightTrain('P', "Train1", 100, 50);
    transportManager.createPassengerTrain('P', "Train2");
    transportManager.createTaxi('N', "Taxi1", "Company_1", 2);
    transportManager.createComercialAirport('P', "Airport1");
    transportManager.createCargoAirport('N', "Airport2");
    transportManager.createHighway('L',"N2", 250);
    transportManager.createInsideRoad('N',"N3", 2);
    transportManager.createBus('N', "Bus2", 50, 25);
    transportManager.createFreightTrain('P', "Train3", 100, 50);
    transportManager.createPassengerTrain('P', "Train4");
    transportManager.createTaxi('N', "Taxi1", "Company_2", 2);
    transportManager.createComercialAirport('P', "Airport3");
    transportManager.createCargoAirport('P', "Airport4");

    
    CityTraverser it(transportManager.getTransportation(0));

    Transportation* x = nullptr;

}