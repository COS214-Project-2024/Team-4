#include <iostream>
#include <memory>
#include "ResidentialBuildingBuilder.h"
#include "CommercialBuildingBuilder.h"
#include "IndustrialBuildingBuilder.h"
#include "LandmarkBuildingBuilder.h"

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
#include "CitizenManager.h"


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
    PowerPlant powerPlant(&mediator);

    // Create CitizenManager
    CitizenManager citizenManager;

    // Register buildings with utilities
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
    commercialBuilding->setOwner("John Doe");
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
    landmarkBuilding->setOwner("Jane Smith");
    landmarkBuilding->construct();
    landmarkBuilding->updateImpacts();
    // waterSupply.registerBuilding(landmarkBuilding.get());


    powerPlant.registerBuilding(commercialBuilding.get());
    powerPlant.registerBuilding(landmarkBuilding.get());

    powerPlant.supplyResources(commercialBuilding.get());
    powerPlant.supplyResources(landmarkBuilding.get());

    // Track charges in CitizenManager
    citizenManager.addCharge(commercialBuilding->getOwner(), powerPlant.getCharges(commercialBuilding->getOwner()));
    citizenManager.addCharge(landmarkBuilding->getOwner(), powerPlant.getCharges(landmarkBuilding->getOwner()));

    std::cout << "Total charges for John Doe: $" << citizenManager.getTotalCharges("John Doe") << std::endl;
    std::cout << "Total charges for Jane Smith: $" << citizenManager.getTotalCharges("Jane Smith") << std::endl;
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
    // Create a Government instance
    Government government("City Government");
    // Create a CityService instance
    CityService cityService("Public Transport", 1000.0);
    // Create a Policy instance
    Policy policy("Policy1", "High");
    // Create command instances
    SetTaxCommand setTaxCommand(&government, 15.0);
    EnforcePolicyCommand enforcePolicyCommand(&government, policy);
    AllocateBudgetCommand allocateBudgetCommand(&government, cityService, 500.0);
    CollectTaxesCommand collectTaxesCommand(&government);
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

int main() {
    // Testing each builder class separately
    testResidentialBuildingBuilder();
    testCommercialBuildingBuilder();
    testIndustrialBuildingBuilder();
    testLandmarkBuildingBuilder();
    testUtilities();
    testResourceManager();

    std::cout << "============================GOVT1========================" << std::endl;
    TESTGOVCOMMAND();
    std::cout << "============================GOVT2========================" << std::endl;
    testGOVF1();
  
    std::cout << "All tests completed.\n";
  
    return 0;
}
