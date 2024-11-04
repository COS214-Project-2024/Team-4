// Jobs.cpp

#include "Jobs.h"
#include <iostream>

// Constructor initializes job title and income based on provided salary
Jobs::Jobs(const std::string& jobTitle, double salary)
    : title(jobTitle), income(std::make_shared<Income>(salary)) {}

// Marks the job as occupied when an employee is hired
void Jobs::hireEmployee() {
    if (!occupied) {
        occupied = true;
        std::cout << "Job " << title << " has been filled." << std::endl;
    } else {
        std::cout << "Job " << title << " is already occupied." << std::endl;
    }
}

// Releases the job, marking it as available
void Jobs::releaseEmployee() {
    if (occupied) {
        occupied = false;
        std::cout << "Job " << title << " is now available." << std::endl;
    } else {
        std::cout << "Job " << title << " is already available." << std::endl;
    }
}

// Displays job information for debugging or informational purposes
void Jobs::displayJobInfo() const {
    std::cout << "Job Title: " << title << std::endl;
    std::cout << "Monthly Income: " << income->calculateMonthlyIncome() << std::endl;
    std::cout << "Status: " << (occupied ? "Occupied" : "Available") << std::endl;
}

void Jobs::unOcuppy() {
    occupied = false;
}
