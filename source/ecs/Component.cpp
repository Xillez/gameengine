#include "./Component.hpp"
#include "Component.hpp"

// REMEMBER: Forward declared in hpp file!
#include "./Entity.hpp"

#include "../utils/Utils.hpp"

Component::Component()
{
	this->id = uuid();
	this->started = false;
	this->parent = nullptr;
}

// ##########################################
// ########## Life cycle functions ##########
// ##########################################

//virtual
void Component::Start()
{
	this->started = true;
}

//virtual
void Component::Update()
{
	//
}

//virtual
/*void Component::PhysicsUpdate()
{
	//
}*/

//virtual
void Component::Destroy()
{
	//
}

// ##########################################
// ########## Management functions ##########
// ##########################################

std::string Component::GetID()
{
    return this->id;
}

Entity* Component::GetParent()
{
    return this->parent;
}

void Component::SetParent(Entity* parent)
{
    this->parent = parent;
}

bool Component::HasStarted()
{
    return this->started;
}
