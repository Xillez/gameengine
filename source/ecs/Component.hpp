#pragma once
#include "../public/typedef.hpp"
#include <algorithm>
#include <type_traits>
#include <typeinfo>
#include <string>

/**
 * @brief Namespace of Entity Component System.
 */
namespace ECS
{
	/**
	 * @brief Base class for components. To make component, make new class extendng from this one. 
	 */
	class Component
	{
	public:
		/**
		 * @brief Constructor of Component.
		 * 
		 * @param id - Id of new component.
		 */
		Component(ComponentID id);

		/**
		 * @brief initialize function to give component parent object for updating and possibly drawing.
		 *  
		 * @param parent - Parent object I exist inside.
		 */
		virtual void Initialize(const EntityID& parent);

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
		 * @brief Draw - Draw the mesh on the screen.
		 */
		virtual void Draw();

		/**
		 * @brief Destory - Make ready for removal. 
		 */
		virtual bool Destroy();

		// ##########################################
		// ########## Management functions ##########
		// ##########################################

		/**
		 * @brief Get the Component id.
		 * 
		 * @return ComponentID - The id of the component.
		 */
		ComponentID GetID();

		/**
		 * @brief Get the entity parent ID
		 * 
		 * @return EntityID 
		 */
		EntityID GetParentID();

		/**
		 * @brief Set the Parent ID
		 * 
		 * @param parent - EntityID (int) - id of parent entity.
		 */
		void SetParentID(EntityID parent);

		// #######################################
		// ########## Utility functions ##########
		// #######################################

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
		
	private: 
		const ComponentID ID;			//!< Component's id.
		EntityID parentID;		//!< Parent id exists inside.
	};
}