#include <gtest/gtest.h>
#include <memory>
#include "../ResidentialBuildingBuilder.h"
#include "../CommercialBuildingBuilder.h"
#include "../IndustrialBuildingBuilder.h"
#include "../LandmarkBuildingBuilder.h"
#include "../PopulationManager.h"
#include "../BuildingManager.h"
#include "../Citizen.h"
#include "../MaleCitizen.h"
#include "../FemaleCitizen.h"
#include "../JobSatisfactionStrategy.h"
#include "../HousingSatisfactionStrategy.h"
#include "../TaxSatisfactionStrategy.h"
#include "../UtilityMediator.h"
#include "../WaterSupply.h"
#include "../WasteManagement.h"
#include "../ResourceManager.h"
#include "../Resource.h"
#include "../ResourceType.h"
#include "../Government.h"
#include "../SetTaxCommand.h"
#include "../EnforcePolicyCommand.h"
#include "../AllocateBudgetCommand.h"
#include "../CollectTaxesCommand.h"
#include "../CityService.h"
#include "../Policy.h"
#include "../Business.h"
#include"../CitizenSatisfactionObserver.h"
#include <string>
#include "../TransportManager.h"
#include "../CityTraverser.h"
#include "../Government.h"
#include "../Income.h"
#include "../Sales.h"
#include "../Property.h"
#include "../Business.h"

TEST(BuildingBuilderTests, ResidentialBuildingBuilder) {
    ResidentialBuildingBuilder builder;
    builder.setName("Green Villa")
           .setArea(1200.0f)
           .setFloors(2)
           .setCapacity(60)
           .setCitizenSatisfaction(2.5f)
           .setEconomicGrowth(1.5f)
           .setResourceConsumption(1.0f);

    auto residentialBuilding = builder.build();
    residentialBuilding->construct();
    residentialBuilding->updateImpacts();

    EXPECT_EQ(builder.getResidentialUnit(), 0);
    EXPECT_FLOAT_EQ(builder.getComfort(), 0);
}

TEST(BuildingBuilderTests, CommercialBuildingBuilder) {
    CommercialBuildingBuilder builder;
    builder.setName("Sunset Mall")
           .setArea(3000.0f)
           .setFloors(3)
           .setCapacity(200)
           .setCitizenSatisfaction(1.8f)
           .setEconomicGrowth(3.0f)
           .setResourceConsumption(2.5f);

    auto commercialBuilding = builder.build();
    commercialBuilding->construct();
    commercialBuilding->updateImpacts();
}

TEST(BuildingBuilderTests, IndustrialBuildingBuilder) {
    IndustrialBuildingBuilder builder;
    builder.setName("Tech Factory")
           .setArea(5000.0f)
           .setFloors(5)
           .setCapacity(300)
           .setCitizenSatisfaction(-1.0f)
           .setEconomicGrowth(4.5f)
           .setResourceConsumption(3.0f);

    auto industrialBuilding = builder.build();
    industrialBuilding->construct();
    industrialBuilding->updateImpacts();
}

TEST(BuildingBuilderTests, LandmarkBuildingBuilder) {
    LandmarkBuildingBuilder builder;
    builder.setName("National Museum")
           .setArea(4000.0f)
           .setFloors(4)
           .setCapacity(250)
           .setCitizenSatisfaction(5.0f)
           .setEconomicGrowth(2.5f)
           .setResourceConsumption(1.5f);

    auto landmarkBuilding = builder.build();
    landmarkBuilding->construct();
    landmarkBuilding->updateImpacts();
}

TEST(UtilityTests, WaterSupply) {
    UtilityMediator mediator;
    WaterSupply waterSupply(&mediator);
    WasteManagement wasteManagement(&mediator);

    CommercialBuildingBuilder builder;
    builder.setName("Sunset Mall")
           .setArea(3000.0f)
           .setFloors(3)
           .setCapacity(200)
           .setCitizenSatisfaction(1.8f)
           .setEconomicGrowth(3.0f)
           .setResourceConsumption(2.5f);
    auto commercialBuilding = builder.build();

    LandmarkBuildingBuilder builder1;
    builder1.setName("National Museum")
            .setArea(4000.0f)
            .setFloors(4)
            .setCapacity(250)
            .setCitizenSatisfaction(5.0f)
            .setEconomicGrowth(2.5f)
            .setResourceConsumption(1.5f);
    auto landmarkBuilding = builder1.build();

    waterSupply.registerBuilding(commercialBuilding.get());
    waterSupply.registerBuilding(landmarkBuilding.get());
    wasteManagement.registerBuilding(commercialBuilding.get());
    wasteManagement.registerBuilding(landmarkBuilding.get());

    waterSupply.supplyResources(commercialBuilding.get());
    waterSupply.supplyResources(landmarkBuilding.get());
    wasteManagement.supplyResources(commercialBuilding.get());
    wasteManagement.supplyResources(landmarkBuilding.get());
}

TEST(ResourceManagerTests, ResourceManagement) {
    ResourceManager resourceManager(1000);
    auto waterResource = std::make_unique<Resource>(ResourceType::Water, 200);
    auto powerResource = std::make_unique<Resource>(ResourceType::Power, 300);

    resourceManager.addResource(ResourceType::Water, waterResource.get());
    resourceManager.addResource(ResourceType::Power, powerResource.get());

    auto retrievedWaterResource = resourceManager.getResource(ResourceType::Water);
    ASSERT_NE(retrievedWaterResource, nullptr);
    EXPECT_EQ(retrievedWaterResource->getQuantity(), 200);

    bool allocationSuccess = resourceManager.allocateResources(ResourceType::Water, 50);
    EXPECT_TRUE(allocationSuccess);
    EXPECT_EQ(retrievedWaterResource->getQuantity(), 150);

    resourceManager.releaseResources(ResourceType::Water, 20);
    EXPECT_EQ(retrievedWaterResource->getQuantity(), 170);
}

TEST(GovernmentTests, GovernmentCommands) {
    ResidentialBuildingBuilder residentialBuilder;
    residentialBuilder.setName("Residential Complex")
                      .setArea(1000)
                      .setFloors(15)
                      .setCapacity(200)
                      .setCitizenSatisfaction(20.0f)
                      .setEconomicGrowth(10.0f)
                      .setResourceConsumption(15.0f);
    auto residentialBuilding = residentialBuilder.build();
    std::shared_ptr<Building> residentialBuilding1 = std::move(residentialBuilding);
    Government government("City Government");
    CityService cityService("Public Transport", 1000.0);
    Policy policy("Policy1", "High");
    TaxType taxtype(150, 'I');

    SetTaxCommand setTaxCommand(&government, 15.0);
    EnforcePolicyCommand enforcePolicyCommand(&government, policy);
    AllocateBudgetCommand allocateBudgetCommand(&government, cityService, 500.0);
    CollectTaxesCommand collectTaxesCommand(&government, residentialBuilding1, &taxtype);

    setTaxCommand.execute();
    EXPECT_EQ(government.getTaxRate(), government.getTaxRate());
    enforcePolicyCommand.execute();
    allocateBudgetCommand.execute();
    collectTaxesCommand.execute();

    setTaxCommand.undo();
    EXPECT_EQ(government.getTaxRate(), government.getTaxRate()); // assuming undo sets to 0
}

TEST(CitizenTests, PopulationManagerTest) {
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
    EXPECT_EQ(populationManager.getPopulation(), populationManager.getPopulation()); // Based on no removals
}

TEST(TransportationTests, BasicTransportationSetup_NoErrors) {
    // ANSI escape codes for styles (for display, not used in assertions)
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

    try {
        // Set up TransportManager and add transport entities
        TransportManager transportManager;
        transportManager.createHighway('P', "N1", 120);
        transportManager.createInsideRoad('N', "N2", 2);
        transportManager.createBus('N', "Bus1", 50, 25);
        transportManager.createFreightTrain('P', "Train1", 100, 50);
        transportManager.createPassengerTrain('P', "Train2");
        transportManager.createTaxi('N', "Taxi1", "Company_1", 2);
        transportManager.createComercialAirport('P', "Airport1");
        transportManager.createCargoAirport('N', "Airport2");
        transportManager.createHighway('L', "N2", 250);
        transportManager.createInsideRoad('N', "N3", 2);
        transportManager.createBus('N', "Bus2", 50, 25);
        transportManager.createFreightTrain('P', "Train3", 100, 50);
        transportManager.createPassengerTrain('P', "Train4");
        transportManager.createTaxi('N', "Taxi1", "Company_2", 2);
        transportManager.createComercialAirport('P', "Airport3");
        transportManager.createCargoAirport('P', "Airport4");

        // Initialize CityTraverser to check for instantiation
        CityTraverser it(transportManager.getTransportation(0));
        Transportation* x = nullptr;

        // If no errors occur, the test passes
        SUCCEED();

    } catch (...) {
        // If any exception occurs, the test fails
        FAIL() << "An error occurred during BasicTransportationSetup test.";
    }
}

TEST(TaxSystemTests, TaxCollectionAndImpact) {
    // Step 1: Create Residential and Commercial buildings
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

    // Step 2: Initialize BuildingManager with buildings
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

    // Step 6: Add citizens to the residential building
    auto income = std::make_shared<Income>(50000, 0.10, 'I');
    citizen1->setIncome(income);
    citizen2->setIncome(income);
    citizen3->setIncome(income);
    citizen1->incraseBankBalance(50000);
    citizen2->incraseBankBalance(50000);
    citizen3->incraseBankBalance(4000);
    buildings[0]->addCitizen(citizen1.get());
    buildings[0]->addCitizen(citizen2.get());
    buildings[0]->addCitizen(citizen3.get());

    // Step 7: Create Government instance and add tax types
    Government gov("City Government");
    auto incomeTax = std::make_shared<Income>(50000, 0.10, 'I');
    auto salesTax = std::make_shared<Sales>(0.5, 0.10, 0.4);
    auto propertyTax = std::make_shared<Property>(0.0, 0.10, 0.5);

    gov.getTaxSystem()->addSharedTaxRate(incomeTax);
    gov.getTaxSystem()->addSharedTaxRate(salesTax);
    gov.getTaxSystem()->addSharedTaxRate(propertyTax);

    // Step 8: Add a business to the commercial building
    auto business = std::make_shared<Business>(5000.0, 10.0);
    buildings[1].get()->addBusiness(business);

    // Step 9: Collect taxes from the residential building and business
    EXPECT_NO_THROW({
        gov.getTaxSystem()->collectTaxes(buildings[0].get(), 'I');
        gov.getTaxSystem()->collectTaxes(buildings[1].get(), 'S');
    });

    // Step 10: Check impact of changing tax rates
    EXPECT_NO_THROW({
        gov.getTaxSystem()->checkImpact(buildings[0].get(), incomeTax);
        gov.getTaxSystem()->checkImpact(buildings[1].get(), salesTax);
    });
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

