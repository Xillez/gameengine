#include "Entity.hpp"

#include <iostream>
#include <algorithm>

Entity::Entity() : ID(DEFAULT_ENTITY_ID)
{
	//
}

Entity::Entity(EntityID id) : ID(id)
{
	//
}

//virtual
Entity::~Entity()
{
	//
}

// ##########################################
// ########## Life cycle functions ##########
// ##########################################

//virtual
void Entity::Start()
{
	for (std::pair<const ComponentID, Component*>& comp : this->components)
		comp.second->Start();
}

//virtual
void Entity::Update()
{
	for (std::pair<const ComponentID, Component*>& comp : this->components)
		comp.second->Update();
}

//virtual
/*void Entity::PhysicsUpdate()
{
	//
}*/

//virtual
void Entity::Draw()
{
	for (std::pair<const ComponentID, Component*>& comp : this->components)
		comp.second->Draw();
}

//virtual
bool Entity::Destroy()
{
	for (std::pair<const ComponentID, Component*>& comp : this->components)
	{
		comp.second->Destroy();
		delete this->components[comp.first];
		this->components[comp.first] = nullptr;
	}

	this->componentIDs.clear();
	this->components.clear();

    return (this->componentIDs.size() == 0);
}

// ##########################################
// ########## Management functions ##########
// ##########################################

//virtual
Component* Entity::GetComponentByID(ComponentID id)
{
	/*auto it = std::find(this->componentIDs.begin(), this->componentIDs.end(), id);    // Does the id exist.
    if (it != this->componentIDs.end())            // Found component, delete it.
    {
        // Add parent / initialize with current object as parent.
		//component->Initialize(this);
		// Add it to current Entity's component list.
		this->componentIDs.push_back(id);
    }

	// Tell whether it was added or not.
	return (id);*/
}

// ##########################################
// ########## Utility functions ##########
// ##########################################

int Entity::GetID()
{
	return this->ID;
}

//virtual
std::string Entity::GetClassName(bool removeDigits)
{
	std::string name = typeid(*this).name();	// Get dirty class name.
	if (typeid(*this).__is_pointer_p())			// If it's a pointer remove prefix "P".
		name.erase(name.begin(), name.begin() + 1);
	if (removeDigits)							// Should remove digits?
	{
		int i = 0;
		while (isdigit(name.at(i))) i++;		// Find where digits end.
		name.erase(name.begin(), name.begin() + i);	// Remove digits.
	}
	return name;								// Return pretty name.
}

//virtual
/*std::string Entity::GetLowestTypeName(bool removeDigits)
{
	std::string name = typeid(*this).name();				// Get the dirty name of class.
	//printf("GET LOWEST TYPE NAME: %s\n", name.c_str());
	if (typeid(*this).__is_pointer_p())						// If it's a pointer remove prefix "P".
		name.erase(name.begin(), name.begin() + 1);
	if (removeDigits)										// Should remove digits?
	{
		int i = 0;
		while (isdigit(name.at(i))) i++;					// Find where digits end.
		name.erase(name.begin(), name.begin() + i);			// Remove them.
	}
	return name;											// Return pretty name.
}*/

ComponentID Entity::NextCompID()
{
    return this->nextCompId++;
}