#pragma once

#include "../public/typedef.hpp"
#include "./Component.hpp"

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <functional>
#include <unordered_map>
#include <algorithm>
#include <type_traits>

#define DEFAULT_ENTITY_ID -1

/* TODO:
    - Implement PhysicsUpdate for physx compatibility.
 */

/**
 * @brief Generic Entity with components.
 */
class Entity// : BaseEntity
{
public:
    /**
     * @brief Basic Entity constructur, Default Entity ID.
     * !!Note!! Ment to be a temporary instantiation! Make sure you use Instantiate() to get legal id.
     */
    Entity();

    /**
     * @brief Entity constructor. Should NOT be used for new entity generation except for EntityMgr.
     * 
     * @param id - Id of new entity.
     */
    Entity(EntityID id);

    /**
     * @brief Entity deconstructor.
     */
    virtual ~Entity();

    // ##########################################
    // ########## Life cycle functions ##########
    // ##########################################

    /**
     * @brief Start function, called once at the very start of the lifecycle.
     */
    virtual void Start();

    /**
     * @brief Updates state for next frame.
     */
    virtual void Update();

    /**
     * @brief Physics update function for Entities.
     */
    //virtual void PhysicsUpdate();    

    /**
     * @brief Draw the entity and possible subcomponents.
     */
    virtual void Draw();

    /**
     * @brief Used for destroying an entity.
     * 
     * @return true - Entity was destroyed.
     * @return false - Failed to destroy.
     */
    virtual bool Destroy();

    // ##########################################
    // ########## Management functions ##########
    // ##########################################

    /**
     * @brief Create new Component with next local (to entity) component id.
     * 
     * @tparam Class - The subclass of Component.
     * 
    @return ComponentID - The ID to the newly created component.
    */
    template<class Tclass>
    Tclass* CreateComponent()
    {
        if (!std::is_base_of<Component, Tclass>::value)   // Class does NOT extend Component
        {
            std::cout << "CreateComponent() accepts only classes derived from Component";
            return 0;
        }

        ComponentID tempID = this->NextCompID();    // Get id and increase.
        Tclass* temp = new Tclass(tempID);            // Make new component.
        temp->SetParentID(this->GetID());            // Set Parent id in component to mine.
        this->componentIDs.push_back(tempID);       // Add id.
        this->components[tempID] = temp;            // Save component pointer.
        return temp;
        
        return 0;
    }

    /**
     * @brief Get internal component on entity based on type, 
     * !NOTE! Template class given as type "Component" class will return any component, no guarrantee what you will get.
     * 
     * @tparam Tclass - Class extended from Component.
     * 
     * @return Component* - Pointer to internal component.
     */
    template<class Tclass>
    Tclass* GetComponent()
    {
        if (!std::is_base_of<Component, Tclass>::value)
        {
            std::cout << "GetComponent() accepts only Component class and subclasses of it!\n";
            return nullptr;
        }
        auto findByType = [](std::pair<ComponentID, Component*> entry){ return (typeid(Tclass) == typeid(entry.second)); };
        auto it = std::find_if(this->components.begin(), this->components.end(), findByType);
        if (it != this->components.end());
            printf("%s was similar to %s: %d", typeid(Tclass).name(), this->components[it].second->GetLowestTypeName(), (it != this->components.end()));
    }

    /**
     * @brief Get internal component on entity.
     * 
     * @tparam Tclass - Class extended from Component.
     * 
     * @return std::vector<Component*> - Vector of pointer to internal component.
     */
    template<class Tclass>
    std::vector<Tclass*> GetComponents()
    {
        if (!std::is_base_of<Component, Tclass>::value)
        {
            std::cout << "GetComponent() accepts only Component class and subclasses of it!\n";
            return nullptr;
        }
        std::vector<Component*> comps;
        for (std::pair<ComponentID, Component*>& comp : this->components)
            if (typeid(comp.second) == typeid(Tclass))
                comps.push_back(comp.second);
    }

    /**
     * @brief Get the Component via ID
     * 
     * @param id - Id of the component you want.
     * 
     * @return Component* - Pointer to component found. If nothing found, nullptr returned.
     */
    virtual Component* GetComponentByID(ComponentID id);

    /**
     * @brief Removes an component by ID, all components without an owner gets removed aswell.
     * 
     * @param component - Pointer to component to be removed.
     */
    void RemoveComponent(Component* component);

    /**
     * @brief Removes an component by ID, all components without an owner gets removed aswell.
     * 
     * @param id - ID of component to be removed.
     */
    void RemoveComponentByID(ComponentID id);

    // #######################################
    // ########## Utility functions ##########
    // #######################################
    
    /**
     * @brief A function for getting id.
     * 
     * @return id - id for entity.
     */
    virtual int GetID();

    /**
     * @brief Get the name of the current class.
     * 
     * @return std::string - Name of the current class.
     */
    virtual std::string GetClassName(bool removeDigit = true);

    /**
     * @brief Get the name of the lowest class in the hierarchy.
     * 
     * @return std::string - Name of the lowest class in the hierarchy.
     */
    //virtual std::string GetLowestTypeName(bool removeDigit = true);

protected:
    std::vector<ComponentID> componentIDs;    //!< List of Component IDs.    

    //int nextID = INPUT_COMPONENT_ID + 1;


    //std::vector<ComponentID> componentIDs;      //!< A vector of all components registered.
    std::unordered_map<ComponentID, Component*> components;     //!< A unordered map, mapping components to ids.

private:
    /**
     * @brief Function for increasing next entity id. DO NOT USE.
     * 
     * @return EntityID (int) - ID of next entity to be added.
     */
    EntityID NextCompID();

    EntityID ID;                        //!< Id of Entity.

    ComponentID nextCompId = 0;            //!< Next Id of components.

    void* mgr;                            //!< Pointer back to EntityMgr.
};
