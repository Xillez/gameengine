#pragma once
#include "../public/typedef.hpp"
#include <algorithm>
#include <type_traits>
#include <typeinfo>
#include <string>

class Entity;

/**
 * @brief Base class for components. To make component, make new class extendng from this one. 
 */
class Component
{
public:
	/**
	 * @brief Constructs a new empty component.
	 */
	Component();

	// ##########################################
	// ########## Life cycle functions ##########
	// ##########################################

	/**
	 * @brief Start - Function to setup component. Runs once at program start.
	 */
	virtual void Start();

	/**
	 * @brief Update function for components. Called every frame.
	 */
	virtual void Update();

	/**
	 * @brief PhysicsUpdate - Physics update function.
	 */
	//virtual void PhysicsUpdate();

	/**
	 * @brief Destory - Make ready for removal. 
	 */
	virtual void Destroy();

	// ##########################################
	// ########## Management functions ##########
	// ##########################################

	/**
	 * @brief Get the Component id.
	 * 
	 * @return std::string - The id of the component.
	 */
	std::string GetID();

	/**
	 * @brief Get the entity parent.
	 * 
	 * @return Entity* - Parent entity. 
	 */
	Entity* GetParent();

	/**
	 * @brief Sets parent entity.
	 * 
	 * @param parent - Entity* - Parent entity.
	 */
	void SetParent(Entity* parent);

	/**
	 * @brief Whether the component has been started or not.
	 * 
	 * @return true - Component has been stated.
	 * @return false - Component hasn't been stated yet.
	 */
	bool HasStarted();

private: 
	std::string id;

	Entity* parent;

	bool started;
};