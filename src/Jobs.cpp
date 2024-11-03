#include "Jobs.h"

// Constructor
Jobs::Jobs(const std::string& title, float income, int availablePositions)
    : title(title), income(income), availablePositions(availablePositions), isEmployed(false) {}

// Getter methods
std::string Jobs::getTitle() const { return title; }
float Jobs::getIncome() const { return income; }
int Jobs::getAvailablePositions() const { return availablePositions; }
bool Jobs::getEmploymentStatus() const { return isEmployed; }

// Hire an employee, if available positions > 0
bool Jobs::hireEmployee() {
    if (availablePositions > 0) {
        --availablePositions;
        isEmployed = true;
        return true;
    }
    return false;  // No available positions
}

// Release an employee, increasing available positions
void Jobs::releaseEmployee() {
    ++availablePositions;
    if (availablePositions > 0) {
        isEmployed = false;
    }
}

// Display job information
void Jobs::displayJobInfo() const {
    std::cout << "Title: " << title << ", Income: " << income
              << ", Available Positions: " << availablePositions
              << ", Employment Status: " << (isEmployed ? "Employed" : "Available") << std::endl;
}