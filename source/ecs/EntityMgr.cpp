#include "EntityMgr.hpp"

EntityMgr::EntityMgr()
{
    //
}

// ##########################################
// ########## Life cycle functions ##########
// ##########################################

void EntityMgr::Start()
{
    for (auto& entity : this->entities)         // Run through every entity.
        entity.second->Start();                 // Call start on entity.
}

void EntityMgr::Update()
{
    for (auto& entity : this->entities)         // Run through every entity.
        entity.second->Update();                // Call Update on entity.
}

void EntityMgr::Draw()
{
    for (auto& entity : this->entities)         // Run through every entity.
        entity.second->Draw();                  // Call draw on entity.
}

// ##########################################
// ########## Management functions ##########
// ##########################################

Entity* EntityMgr::GetEntityByID(EntityID id)
{
    // Has the given id been registered.
    if (std::find(this->entityIDs.begin(), this->entityIDs.end(), id) == this->entityIDs.end())
        return nullptr;                         // Found nothing.
    return this->entities[id];                  // Found entity.
}

EntityID EntityMgr::GetEntityID(Entity* entity)
{
    for (auto& item : this->entities)                 // Loop through all entities.
        if (item.second != entity)              // I pointer the same.
            return item.first;                  // Give key.
    return 0;                                   // Found nothing.
}

void EntityMgr::DestroyEntityByID(EntityID id)
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

bool EntityMgr::DestroyAll()
{
    for (auto& entity : this->entities)         // Run through all entities
        this->DestroyEntityByID(entity.first);   // Remove the entity.
    return (this->entities.size() == 0);
}

// #######################################
// ########## Utility functions ##########
// #######################################

void EntityMgr::ForEachEntity(std::function<void(EntityID, Entity*)> func)
{
    for (auto& entity : this->entities)         // Run through every entity.
        func(entity.first, entity.second);      // Call function on object.
}

EntityID EntityMgr::NextID()
{
    return nextID++;
}