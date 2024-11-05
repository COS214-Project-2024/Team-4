/**
 * @file Jobs.cpp
 * @brief Implementation of the Jobs class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the implementation of the Jobs class, which manages job-related operations
 * such as hiring and releasing employees, and displaying job information.
 */

#include "Jobs.h"
#include <iostream>

/**
 * @brief Constructor initializes job title and income based on provided salary.
 * @param jobTitle The title of the job.
 * @param salary The salary for the job.
 */
Jobs::Jobs(const std::string& jobTitle, double salary)
    : title(jobTitle), income(std::make_shared<Income>(salary)) {}

/**
 * @brief Marks the job as occupied when an employee is hired.
 */
void Jobs::hireEmployee() {
    if (!occupied) {
        occupied = true;
        std::cout << "Job " << title << " has been filled." << std::endl;
    } else {
        std::cout << "Job " << title << " is already occupied." << std::endl;
    }
}

/**
 * @brief Releases the job, marking it as available.
 */
void Jobs::releaseEmployee() {
    if (occupied) {
        occupied = false;
        std::cout << "Job " << title << " is now available." << std::endl;
    } else {
        std::cout << "Job " << title << " is already available." << std::endl;
    }
}

/**
 * @brief Displays job information for debugging or informational purposes.
 */
void Jobs::displayJobInfo() const {
    std::cout << "Job Title: " << title << std::endl;
    std::cout << "Monthly Income: " << income->calculateMonthlyIncome() << std::endl;
    std::cout << "Status: " << (occupied ? "Occupied" : "Available") << std::endl;
}

/**
 * @brief Marks the job as unoccupied.
 */
void Jobs::unOcuppy() {
    occupied = false;
}