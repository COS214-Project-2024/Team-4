/**
 * @file Jobs.h
 * @brief Definition of the Jobs class.
 * @version 1.0
 * @date 2024-11-04
 * This file contains the definition of the Jobs class, which manages job-related operations
 * such as hiring and releasing employees, and displaying job information.
 */

#ifndef JOBS_H
#define JOBS_H

#include <memory>
#include "Income.h"
#include <string>
#include <memory>

/**
 * @class Jobs
 * @brief Manages job-related operations.
 * 
 * The Jobs class manages job-related operations such as hiring and releasing employees,
 * and displaying job information.
 */
class Jobs {
private:
    std::string title;              ///< Job title, e.g., "Engineer", "Manager"
    bool occupied = false;          ///< Employment status; true if filled
    std::shared_ptr<Income> income; ///< Income object associated with the job

public:
    /**
     * @brief Constructor that initializes a job with a title and salary.
     * @param jobTitle The title of the job.
     * @param salary The salary for the job.
     */
    Jobs(const std::string& jobTitle, double salary);

    // Getters
    /**
     * @brief Gets the job title.
     * @return The job title.
     */
    std::string getTitle() const { return title; }

    /**
     * @brief Gets the income associated with the job.
     * @return A shared pointer to the Income object.
     */
    std::shared_ptr<Income> getIncome() const { return income; }

    /**
     * @brief Checks if the job is occupied.
     * @return True if the job is occupied, false otherwise.
     */
    bool isOccupied() const { return occupied; }

    /**
     * @brief Marks the job as occupied when an employee is hired.
     */
    void hireEmployee(); 

    /**
     * @brief Releases the job, marking it as available.
     */
    void releaseEmployee();

    /**
     * @brief Displays job information for debugging or informational purposes.
     */
    void displayJobInfo() const;

    /**
     * @brief Marks the job as unoccupied.
     */
    void unOcuppy();
};

#endif // JOBS_H