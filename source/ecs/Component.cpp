#include "./Component.hpp"

ECS::Component::Component(ECS::ComponentID id) : ID(id)
{
	//
}

void ECS::Component::Initialize(const ECS::EntityID& parent)
{
	this->parentID = parent;
}

// ##########################################
// ########## Life cycle functions ##########
// ##########################################

//virtual
void ECS::Component::Start()
{
	printf("Component - Start()\n");
}

//virtual
void ECS::Component::Update()
{
	printf("Component - Update()\n");
}

//virtual
/*void Component::PhysicsUpdate()
{
	//
}*/

//virtual
void ECS::Component::Draw()
{
	printf("Component - Draw()\n");
}

//virtual
bool ECS::Component::Destroy()
{
	printf("Component - Destroy()\n");
}

// ##########################################
// ########## Management functions ##########
// ##########################################

ECS::ComponentID ECS::Component::GetID()
{
    return this->ID;
}

ECS::EntityID ECS::Component::GetParentID()
{
    return this->parentID;
}

void ECS::Component::SetParentID(ECS::EntityID parent)
{
    this->parentID = parent;
}

// #######################################
// ########## Utility functions ##########
// #######################################

//virtual
std::string ECS::Component::GetClassName(bool removeDigits)
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
/*std::string ECS::Component::GetLowestTypeName(bool removeDigits)
{
	std::string name = typeid(*this).name();		// Get the dirty name of class.
    printf("GET LOWEST TYPE NAME: %s\n", name);
	if (typeid(*this).__is_pointer_p())				// If it's a pointer remove prefix "P".
		name.erase(name.begin(), name.begin() + 1);
	if (removeDigits)								// Should remove digits?
	{
		int i = 0;
		while (isdigit(name.at(i))) i++;					// Find where digits end.
		name.erase(name.begin(), name.begin() + i);			// Remove them.
	}
	return name;									// Return pretty name.
}*/