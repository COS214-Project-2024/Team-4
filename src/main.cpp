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

int main() {
    // // Testing each builder class separately
    // testResidentialBuildingBuilder();
    // testCommercialBuildingBuilder();
    // testIndustrialBuildingBuilder();
    // testLandmarkBuildingBuilder();
    // testUtilities();
    // testResourceManager();

    std::cout << "All tests completed.\n";

    return 0;
}
