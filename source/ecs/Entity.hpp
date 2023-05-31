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

/* TODO:
    - Implement PhysicsUpdate for physx compatibility.
 */

/**
 * @brief Generic Entity with components.
 */
class Entity
{
public:
    /**
     * @brief Basic Entity constructur, Default Entity ID.
     */
    Entity();

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
     * @brief Used for destroying an entity.
     * 
     * @return true - Entity was destroyed.
     * @return false - Failed to destroy.
     */
    virtual void Destroy();

    // ##########################################
    // ########## Management functions ##########
    // ##########################################

    /**
     * @brief Create new Component with next local (to entity) component id.
     * 
     * @tparam Class - The subclass of Component.
     * 
    @return std::string - The ID to the newly created component.
    */
    template<class Tclass>
    Tclass* CreateComponent()
    {
        if (!std::is_base_of<Component, Tclass>::value)   // Class does NOT extend Component
        {
            std::cout << "CreateComponent() accepts only classes derived from Component";
            return nullptr;
        }

        Tclass* component = new Tclass();
        component->SetParent(this);
        this->components.push_back(component);
        return component;
    }

    /**
     * @brief Add a pre-defined component.
     * 
     * @param component Component - Some component
     */
    template<class Tclass>
    void AddComponent(Tclass& component)
    {
        if (!std::is_base_of<Component, Tclass>::value)   // Class does NOT extend Component
        {
            std::cout << "AddComponent() accepts only classes derived from Component";
        }

        component.SetParent(this);
        this->components.push_back(&component);
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
        auto findByType = [](std::pair<std::string, Component*> entry){ return (typeid(Tclass) == typeid(entry.second)); };
        auto itr = std::find_if(this->components.begin(), this->components.end(), findByType);
        if (itr != this->components.end());
            return *itr;
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
        for (Component* comp : this->components)
            if (typeid(comp) == typeid(Tclass))
                comps.push_back(comp);
        return comps;
    }

    /**
     * @brief Get the Component via ID
     * 
     * @param id - Id of the component you want.
     * 
     * @return Component* - Pointer to component found. If nothing found, nullptr returned.
     */
    virtual Component* GetComponentByID(std::string id);

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
    void RemoveComponentByID(std::string id);

    /**
     * @brief Get child entity by ID.
     * 
     * @param id - Id of wanted entity.
     * 
     * @return Entity* - Pointer to entity found. If nothing found, nullptr returned.
     */
    Entity* GetChildByID(std::string id);

    /**
     * @brief Get children.
     * 
     * @return std::vector<Entity*>& - List of all children.
     */
    std::vector<Entity*>& GetChildren();

    /**
     * @brief Get chile entity by ID.
     * 
     * @param id - Id of wanted entity.
     * 
     * @return Entity* - Pointer to entity found. If nothing found, nullptr returned.
     */
    void Add(Entity* entity);

    /**
     * @brief Removed the given entity from the 
     * 
     * @param entity Entity* - Entity to be removed.
     */
    void Remove(Entity* entity);

    /**
     * @brief Set the parent entity.
     * 
     * @param entity Entity* - parent entity.
     */
    void SetParent(Entity* entity);

    // #######################################
    // ########## Utility functions ##########
    // #######################################
    
    /**
     * @brief A function for getting id.
     * 
     * @return id - id for entity.
     */
    virtual std::string GetID();

    /**
     * @brief Returns state telling wether this entity is started or not.
     * 
     * @return true - Entity has been started.
     * @return false - Entity has only been initialized.
     */
    bool HasStarted();

protected:
    std::string id;                        //!< Id of Entity.

    std::vector<Component*> components;     //!< A unordered map, mapping components to ids.

    std::vector<Entity*> children;      //!< A vector of all children registered.

    Entity* parent;

    bool started;
};