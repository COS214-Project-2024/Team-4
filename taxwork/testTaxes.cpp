// testTaxes.cpp

#include "ResidentialBuilding.h"
#include "FemaleCitizen.h"
#include "MaleCitizen.h"
#include "TaxType.h"
#include "Income.h"
#include "Government.h"
#include "TaxSystem.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <memory>

int main() {
    // Create Government instance
    std::shared_ptr<Government> government = std::make_shared<Government>("City Government");

    // Create TaxSystem instance and add the government
    TaxSystem taxSystem;
    taxSystem.addGovernment(government);

    // Create TaxType instance for income tax
    std::shared_ptr<TaxType> incomeTax = std::make_shared<Income>(0.1); // Example rate: 10%
    taxSystem.addTaxRate(incomeTax);

    // Create ResidentialBuilding
    std::shared_ptr<ResidentialBuilding> resBuilding = std::make_shared<ResidentialBuilding>("Sunset Apartments", 5000.0f, 10, 100, 80.0f,
                                    2.0f, 1.5f, 50, 7.5f);

    // Add the building to the tax system
    taxSystem.addIncomeTaxBuilding(resBuilding);

    // Create Citizens
    std::shared_ptr<Citizen> citizen1 = std::make_shared<FemaleCitizen>("Alice", 30, "Single", "Engineer");
    std::shared_ptr<Citizen> citizen2 = std::make_shared<MaleCitizen>("Bob", 45, "Single", "Teacher");

    // Set income for citizens
    citizen1->setIncome(50000.0); // Ensure income is set
    citizen2->setIncome(60000.0); // Ensure income is set

    // Add residents to the building
    resBuilding->addResidents(citizen1);
    resBuilding->addResidents(citizen2);

    // Simulate tax collection through the tax system
    std::cout << "First tax collection:\n";
    taxSystem.collectTaxes(resBuilding, 'I'); // 'I' for Income Tax

    std::cout << "\nAttempting immediate second tax collection (should be on cooldown):\n";
    taxSystem.collectTaxes(resBuilding, 'I'); // 'I' for Income Tax

    // Wait for the cooldown period to expire (e.g., 60 seconds)
    std::cout << "\nWaiting for cooldown to expire...\n";
    std::this_thread::sleep_for(std::chrono::seconds(60));

    std::cout << "\nAttempting tax collection after cooldown:\n";
    taxSystem.collectTaxes(resBuilding, 'I'); // 'I' for Income Tax

    return 0; // Ensure main function returns an int
}