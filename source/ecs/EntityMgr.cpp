#include "EntityMgr.hpp"

ECS::EntityMgr::EntityMgr()
{
    //
}

// ##########################################
// ########## Life cycle functions ##########
// ##########################################

void ECS::EntityMgr::Start()
{
    for (auto& entity : this->entities)         // Run through every entity.
        entity.second->Start();                 // Call start on entity.
}

void ECS::EntityMgr::Update()
{
    for (auto& entity : this->entities)         // Run through every entity.
        entity.second->Update();                // Call draw on entity.
}

void ECS::EntityMgr::Draw()
{
    for (auto& entity : this->entities)         // Run through every entity.
        entity.second->Draw();                  // Call draw on entity.
}

// ##########################################
// ########## Management functions ##########
// ##########################################

ECS::Entity* ECS::EntityMgr::GetEntityByID(ECS::EntityID id)
{
    // Has the given id been registered.
    if (std::find(this->entityIDs.begin(), this->entityIDs.end(), id) == this->entityIDs.end())
        return nullptr;                         // Found nothing.
    return this->entities[id];                  // Found entity.
}

ECS::EntityID ECS::EntityMgr::GetEntityID(ECS::Entity* entity)
{
    for (auto& item : entities)                 // Loop through all entities.
        if (item.second != entity)              // I pointer the same.
            return item.first;                  // Give key.
    return 0;                                   // Found nothing.
}

void ECS::EntityMgr::DestroyEntityByID(ECS::EntityID id)
{
    auto it = std::find(this->entityIDs.begin(), this->entityIDs.end(), id);    // Does the id exist.
    if (it != this->entityIDs.end())            // Found entity, delete it.
    {
        this->entities[id]->Destroy();          // Trigger removal of entity.
        delete this->entities[id];              // Delete entity pointer.
        this->entities.erase(id);               // Remove the entity entry.
        this->entityIDs.erase(it);              // Remove entity id.
    }
}

bool ECS::EntityMgr::DestroyAll()
{
    for (auto& entity : this->entities)         // Run through all entities
        this->DestroyEntityByID(entity.first);   // Remove the entity.
    return (this->entities.size() == 0);
}

// #######################################
// ########## Utility functions ##########
// #######################################

void ECS::EntityMgr::ForEachEntity(std::function<void(ECS::EntityID, ECS::Entity*)> func)
{
    for (auto& entity : this->entities)         // Run through every entity.
        func(entity.first, entity.second);      // Call function on object.
}

ECS::EntityID ECS::EntityMgr::NextID()
{
    return nextID++;
}