#pragma once
#include "../public/typedef.hpp"
#include "./Entity.hpp"

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <type_traits>

// ################################################################################################
// #                                                                                              #
// #                                       Entity Management                                      #
// #                                                                                              #
// ################################################################################################

/**
 * @brief Entity manager class. Manages entities.
 */
class EntityMgr
{
public:
    /**
     * @brief Constructor of EntityMgr.
     */
    EntityMgr();

    // ##########################################
    // ########## Life cycle functions ##########
    // ##########################################

    /**
     * @brief Start all entities.
     */
    void Start();

    /**
     * @brief Update all entities.
     */
    void Update();

    /**
     * @brief Draw all entities. 
     */
    void Draw();

    // ##########################################
    // ########## Management functions ##########
    // ##########################################

    /**
     * @brief Create new Entity. The entity's id goes from 2 and upwards. 1 is Player entity id.
     * 
     * @tparam Class - The subclass of Entity to be made.
     * 
     * @return EntityID - The ID to the newly created entity.
     */
    template<class Tclass>       // In header because of cmake undefined error! DO NOT MOVE BACK!!
    EntityID CreateEntity()
    {
        if (!std::is_base_of<Entity, Tclass>::value)     // Class does NOT extend Entity.
        {
            std::cout << "CreateEntity() accepts only classes derived from Entity\n";
            return 0;
        }

        EntityID tempID = this->NextID();       // Ready for next entity registration.
        Entity* temp = new Tclass(tempID);      // Make new Entity with new ID.
        this->entityIDs.push_back(tempID);      // Add id.
        this->entities[tempID] = temp;          // Save entity pointer.
        temp = nullptr;
        return this->entities[tempID]->GetID(); // Return the new entities id.
    }

    /**
     * @brief Get the Entity by ID.
     * 
     * @param id - id of given entity.
     * 
     * @return Entity* - Pointer to entity found. If nothing found, nullptr returned.
     */
    Entity* GetEntityByID(EntityID id);

    /**
     * @brief Get the Entity ID.
     * 
     * @param entity - entity to get id of.
     * 
     * @return EntityID - ID of entity. 0 if not found.
     */
    EntityID GetEntityID(Entity* entity);

    /**
     * @brief Get the Entity By Type
     * 
     * @tparam Tclass - Class extending Entity.
     * 
     * @return std::vector<Entity> 
     */
    template<class Tclass>    
    std::vector<Entity> GetEntityByType();
    
    /**
     * @brief Removes an entity by ID, all components without an owner gets removed aswell.
     * 
     * @param id - ID of entity to be removed.
     */
    void DestroyEntityByID(EntityID id);

    /**
     * @brief Destroy an entity by id.
     */
    void DestroyByID(EntityID id);

    /**
     * @brief Destroy by entity.
     * 
     * @param entity - Pointer to entity to be destroyed.
     */
    void Destroy(Entity* entity);
    /**
     * @brief Destroys all entities and readys for destruction.
     * 
     * @return true - All Entities was destroyed.
     * @return false - Failed to destroy entities. 
     */
    bool DestroyAll();

    // #######################################
    // ########## Utility functions ##########
    // #######################################

    /**
     * @brief A built-in ForEachEntity loop calling given function for every object registered (with respective id).
     * 
     * @param func - Function to call for each object. Function signature: void(*func)(EntityID, Entity*).
     */
    void ForEachEntity(std::function<void(EntityID, Entity*)> func);

protected:
    //
private:
    /**
     * @brief Function for increasing next entity id. DO NOT USE.
     * 
     * @return EntityID (int) - ID of next entity to be added.
     */
    EntityID NextID();

    std::vector<EntityID> entityIDs;      //!< A vector of all entities registered.
    std::unordered_map<EntityID, Entity*> entities;     //!< A unordered map mapping entities to ids.

    EntityID nextID = 0;


protected:
    //
private:
    //
};