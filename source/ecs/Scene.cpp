#include "Scene.hpp"
#include <queue>

Scene::Scene()
{
    Entity();
}

// ##########################################
// ########## Life cycle functions ##########
// ##########################################

void Scene::Start()
{
	printf("Scene - Start()\n");
    std::queue<Entity*> queue;
    for (Entity*& entity : this->children)
        queue.push(entity);

    while (!queue.empty())
    {
        Entity* entity = queue.front();
        queue.pop();
        if (!entity->HasStarted())
            entity->Start();
        
        for (Entity*& child : entity->GetChildren())
            queue.push(child);
    }
}

void Scene::Update()
{
    std::queue<Entity*> queue;
    for (Entity* entity : this->children)
        queue.push(entity);

    while (!queue.empty())
    {
        Entity* entity = queue.front();
        queue.pop();
        entity->Update();
        
        for (Entity*& child : entity->GetChildren())
            queue.push(child);
    }
}

void Scene::Destroy()
{
    std::queue<Entity*> queue;
    for (Entity* entity : this->children)
        queue.push(entity);

    while (!queue.empty())
    {
        Entity* entity = queue.front();
        queue.pop();
        entity->Destroy();
        
        for (Entity*& child : entity->GetChildren())
            queue.push(child);
    }
}