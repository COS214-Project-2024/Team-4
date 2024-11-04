/**
 * @file ResourceType.h
 * @brief Header file for the ResourceType enumeration.
 * 
 * This file contains the definition of the ResourceType enumeration, which 
 * represents different types of resources that can be managed.
 * 
 * @version 1.0
 * @date 2024-11-04
 */

#ifndef RESOURCETYPE_H
#define RESOURCETYPE_H

/**
 * @enum ResourceType
 * @brief Enumeration of different resource types.
 * 
 * The ResourceType enumeration represents different types of resources that can be managed.
 */
enum class ResourceType {
    Water,      ///< Water resource.
    Power,      ///< Power resource.
    Materials,  ///< Materials resource (e.g., wood, steel, concrete).
    Budget,     ///< Budget resource.
    Waste,      ///< Waste resource.
    Sewage,     ///< Sewage resource.
    Recycling   ///< Recycling resource.
};

#endif // RESOURCETYPE_H