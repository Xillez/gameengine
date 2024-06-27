#pragma once

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <type_traits>

#include "typedef.hpp"
#include "Entity.hpp"

// ################################################################################################
// #                                                                                              #
// #                                       Entity Management                                      #
// #                                                                                              #
// ################################################################################################

/**
 * @brief Entity manager class. Manages entities.
 */
class Scene : public Entity
{
public:
    /**
     * @brief Constructor of EntityMgr.
     */
    Scene();

    // ##########################################
    // ########## Life cycle functions ##########
    // ##########################################

    /**
     * @brief Start all entities in the scene.
     */
    void Start();

    /**
     * @brief Update all entities in the scene.
     */
    void Update();

    /**
     * @brief Destroys all entities in the scene.
     */
    void Destroy();

    // ##########################################
    // ########## Management functions ##########
    // ##########################################

    // #######################################
    // ########## Utility functions ##########
    // #######################################

protected:
    //
};