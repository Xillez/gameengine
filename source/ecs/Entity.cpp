#include "Entity.hpp"

#include "../utils/Utils.hpp"

#include <iostream>
#include <algorithm>

Entity::Entity()
{
	this->id = uuid();
	this->started = false;
	this->parent = nullptr;
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
	printf("Entity - Start()\n");
	for (Component*& comp : this->components)
		if (!comp->HasStarted())
			comp->Start();

	this->started = true;
}

//virtual
void Entity::Update()
{
	for (Component*& comp : this->components)
	{
		// Component hasn't been started yet, starting before we update it.
		if (!comp->HasStarted())
			comp->Start();

		comp->Update();
	}
}

//virtual
/*void Entity::PhysicsUpdate()
{
	//
}*/

//virtual
void Entity::Destroy()
{
	for (Component*& comp : this->components)
		comp->Destroy();

	this->components.clear();
}

// ##########################################
// ########## Management functions ##########
// ##########################################

//virtual
Component* Entity::GetComponentByID(std::string id)
{
	/*auto it = std::find(this->std::strings.begin(), this->std::strings.end(), id);    // Does the id exist.
    if (it != this->std::strings.end())            // Found component, delete it.
    {
        // Add parent / initialize with current object as parent.
		//component->Initialize(this);
		// Add it to current Entity's component list.
		this->std::strings.push_back(id);
    }

	// Tell whether it was added or not.
	return (id);*/
	return nullptr;
}

Entity* Entity::GetChildByID(std::string id)
{
    auto itr = std::find_if(
        this->children.begin(),
        this->children.end(),
        [id](Entity* e){ return e->GetID() == id; }
    );

    // Found entity.
    if (itr != this->children.end())
        return *itr;

    // Found nothing.
    return nullptr;
}

std::vector<Entity*>& Entity::GetChildren()
{
    return this->children;
}

void Entity::Add(Entity* entity)
{
	entity->SetParent(this);
	this->children.push_back(entity);
}

void Entity::Remove(Entity* entity)
{
	this->children.erase(
		std::remove(this->children.begin(), this->children.end(), entity),
		this->children.end()
	);
}

void Entity::SetParent(Entity* parent)
{
	if (this->parent)
		this->parent->Remove(this);

	this->parent = parent;
}

// ##########################################
// ########## Utility functions ##########
// ##########################################

std::string Entity::GetID()
{
	return this->id;
}

bool Entity::HasStarted()
{
    return this->started;
}
