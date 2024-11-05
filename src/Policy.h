/**
 * @file Policy.h
 * @brief Definition of the Policy class.
 * @version 1.0
 * 
 * This file contains the definition of the Policy class, which represents a policy
 * with specific attributes and behaviors.
 */

#ifndef POLICY_H
#define POLICY_H

#include <string>

/**
 * @class Policy
 * @brief Represents a policy with specific attributes and behaviors.
 * 
 * The Policy class provides methods to implement and revoke a policy, as well as to get
 * the policy's name and impact level.
 */
class Policy {

private:
    std::string policyName;   ///< Name of the policy
    std::string impactLevel;  ///< Impact level of the policy

public:
    /**
     * @brief Default constructor for Policy.
     */
    Policy();

    /**
     * @brief Constructor for Policy with parameters.
     * @param name The name of the policy.
     * @param impact The impact level of the policy.
     */
    Policy(const std::string& name, const std::string& impact);

    /**
     * @brief Implements the policy.
     * 
     * Prints a message indicating the policy implementation with its impact level.
     */
    void implement();

    /**
     * @brief Revokes the policy.
     * 
     * Prints a message indicating the policy revocation with its impact level.
     */
    void revoke();

    /**
     * @brief Gets the name of the policy.
     * @return The name of the policy.
     */
    std::string getPolicyName() const;

    /**
     * @brief Gets the impact level of the policy.
     * @return The impact level of the policy.
     */
    std::string getImpactLevel() const;
};

#endif // POLICY_H