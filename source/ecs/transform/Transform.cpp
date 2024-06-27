#include <queue>

#include "Transform.hpp"

#include "Entity.hpp"

Transform::Transform()
{
    this->scale = glm::vec3(1.0f);
	this->parent = nullptr;
    this->UpdateMatrix();
}

void Transform::Start()
{
    this->UpdateMatrix();
}

void Transform::Update()
{
    this->UpdateMatrix();
}

glm::vec3 Transform::GetPosition()
{
    return this->position;
}

void Transform::SetPosition(glm::vec3 pos)
{
    this->position = pos;
    this->isDirty = true;
}

glm::vec3 Transform::GetWorldPosition()
{
    /*
    TODO: Look into whether this is necessary. Matrix should be up-to-date
    before this function can be called by any components.
    */
    if (this->isDirty) {
        this->UpdateMatrix();
    }
    return glm::vec3(this->worldMatrix[3]);
}

glm::quat Transform::GetRotation()
{
    return this->rotation;
}

void Transform::SetRotation(glm::quat rot)
{
    this->rotation = rot;
    this->isDirty = true;
}

glm::vec3 Transform::GetEulerRotation()
{
    return glm::eulerAngles(this->rotation);
}

void Transform::SetEulerRotation(glm::vec3 rot)
{
    this->rotation = glm::quat(rot);
    this->isDirty = true;
}

glm::vec3 Transform::GetScale()
{
    return this->scale;
}

void Transform::SetScale(glm::vec3 scale)
{
    this->scale = scale;
    this->isDirty = true;
}

void Transform::MarkAsDirty()
{
    this->isDirty = true;

    std::queue<Entity*> queue;
    for (Entity* entity : this->children)
        queue.push(entity);

    while (!queue.empty())
    {
        Entity* entity = queue.front();
        queue.pop();
        entity->transform.MarkAsDirty();

        for (Entity*& child : entity->GetChildren())
            queue.push(child);
    }
}

void Transform::SetEntity(Entity* entity)
{
    this->entity = entity;
}

void Transform::UpdateMatrix(bool updateChildren)
{
    if (this->isDirty) {
        this->worldMatrix = glm::mat4(1.0f);

        // Apply scale
        this->worldMatrix = glm::scale(this->worldMatrix, this->scale);

        // Apply rotation
        this->worldMatrix *= glm::mat4_cast(this->rotation);

        // Apply translation
        this->worldMatrix = glm::translate(this->worldMatrix, this->position);

        if (this->parent != nullptr) {
            this->worldMatrix *= this->parent->transform.worldMatrix;
        }
    }

    if (updateChildren)
    {
        for (Entity*& entity : this->children)
            entity->transform.UpdateMatrix();
    }
}