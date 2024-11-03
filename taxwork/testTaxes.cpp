#include "Government.h"
#include "TaxSystem.h"
#include "CommercialBuilding.h"
#include "Business.h"
#include "Income.h" // Assuming Income is derived from TaxType
#include "Property.h" // Assuming Property is derived from TaxType
#include "Sales.h" // Assuming Sales is derived from TaxType
#include <thread>
#include <chrono>
#include <iostream>
#include <memory>

// Function to display a loading bar
void showLoadingBar(int duration) {
    const int barWidth = 50;
    std::cout << "[";
    for (int i = 0; i < barWidth; ++i) {
        std::cout << " ";
    }
    std::cout << "]\r[";
    std::cout.flush();

    for (int i = 0; i < barWidth; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(duration / barWidth));
        std::cout << "=";
        std::cout.flush();
    }
    std::cout << "] Done!\n";
}

int main() {
    // Create government
    Government gov("City Government");

    // Create tax system and assign government
    TaxSystem taxSystem;
    taxSystem.addGovernment(&gov);

    // Create TaxTypes using unique pointers
    auto incomeTax = std::make_unique<Income>(0.1); // Assuming 10% income tax rate
    auto propertyTax = std::make_unique<Property>(0.05, 0.5, 100.0); // Assuming 5% property tax rate, 50% exemption, and $100 minimum tax
    auto salesTax = std::make_unique<Sales>(0.07, 2, 4); // Assuming 7% sales tax rate
    taxSystem.addTaxRate(incomeTax.get());
    taxSystem.addTaxRate(propertyTax.get());
    taxSystem.addTaxRate(salesTax.get());

    // Create Commercial Building
    CommercialBuilding comBuilding("Downtown Plaza", 2000.0f, 20, 100, 80.0f, 0.0f, 0.0f, 20, 15.0f);

    // Create Business using unique pointer
    auto business = std::make_unique<Business>(1000000, 0.1); // Revenue: 1,000,000, Tax Rate: 10%
    comBuilding.setBusiness(business.get());

    // Collect income taxes first time
    std::cout << "First income tax collection:\n";
    taxSystem.collectTaxes(&comBuilding, 'I'); // 'I' for Income Tax

    // Collect property taxes immediately after income taxes
    std::cout << "\nFirst property tax collection:\n";
    taxSystem.collectTaxes(&comBuilding, 'P'); // 'P' for Property Tax

    // Collect sales taxes immediately after property taxes
    std::cout << "\nFirst sales tax collection:\n";
    taxSystem.collectTaxes(&comBuilding, 'S'); // 'S' for Sales Tax

    // Try to collect income taxes again immediately (business should be on cooldown)
    std::cout << "\nAttempting to collect income taxes again immediately:\n";
    taxSystem.collectTaxes(&comBuilding, 'I');

    // Wait for cooldown to expire with a loading bar
    std::cout << "\nWaiting for cooldown to expire...\n";
    showLoadingBar(10000); // Wait for 10 seconds with a loading bar

    // Collect income taxes again
    std::cout << "\nCollecting income taxes after cooldown:\n";
    taxSystem.collectTaxes(&comBuilding, 'I');

    // No need to manually delete the unique pointers, they will be automatically cleaned up

    return 0;
}