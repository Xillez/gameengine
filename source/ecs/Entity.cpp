#include "Entity.hpp"

#include "../utils/Utils.hpp"

#include <iostream>
#include <algorithm>

Entity::Entity()
{
	this->id = uuid();
	this->started = false;
	this->transform.SetEntity(this);
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
	if (!this->started)
	{
		this->transform.Start();

		for (Component*& comp : this->components)
			if (!comp->HasStarted())
				comp->Start();
	}

	this->started = true;
}

//virtual
void Entity::Update()
{
	// Entity hasn't been started before update start it before continuing.
	if (!this->started)
		this->Start();

	// Make sure the matrix is updated before the components are called.
	this->transform.Update();

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
	this->transform.Destroy();

	for (Component*& comp : this->components)
	{
		comp->Destroy();
		delete comp;
	}

	this->components.clear();
}

bool Entity::HasStarted()
{
    return this->started;
}

// ##########################################
// ########## Management functions ##########
// ##########################################

Component* Entity::GetComponentByID(std::string id)
{
	auto itr = std::find_if(
        this->components.begin(),
        this->components.end(),
        [id](Component* e){ return e->GetID() == id; }
    );

    // Found entity.
    if (itr != this->components.end())
        return *itr;

    // Found nothing.
    return nullptr;
}

Entity* Entity::GetChildByID(std::string id)
{
    auto itr = std::find_if(
        this->transform.children.begin(),
        this->transform.children.end(),
        [id](Entity* e){ return e->GetID() == id; }
    );

    // Found entity.
    if (itr != this->transform.children.end())
        return *itr;

    // Found nothing.
    return nullptr;
}

std::vector<Entity*>& Entity::GetChildren()
{
    return this->transform.children;
}

void Entity::Add(Entity* entity)
{
	entity->SetParent(this);
}

void Entity::Remove(Entity* entity)
{
	this->transform.children.erase(
		std::remove(
			this->transform.children.begin(),
			this->transform.children.end(),
			entity
		),
		this->transform.children.end()
	);
}

void Entity::SetParent(Entity* parent)
{
	if (this->transform.parent)
		this->transform.parent->Remove(this);

	this->transform.parent = parent;

	if (parent != nullptr)
		parent->transform.children.push_back(this);
}

void Entity::RemoveFromParent()
{
	this->SetParent(nullptr);
}

// ##########################################
// ############ Utility functions ###########
// ##########################################

std::string Entity::GetID()
{
	return this->id;
}