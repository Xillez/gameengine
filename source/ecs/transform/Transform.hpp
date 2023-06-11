#pragma once

#include "../Component.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

class Entity;

class Transform : public Component {
    friend class Entity;

public:
    Transform();

    void Start();

    void Update();

    glm::vec3 GetPosition();

    void SetPosition(glm::vec3 pos);

    glm::vec3 GetWorldPosition();

    glm::quat GetRotation();

    void SetRotation(glm::quat rot);

    glm::vec3 GetEulerRotation();

    void SetEulerRotation(glm::vec3 rot);
    
    glm::vec3 GetScale();

    void SetScale(glm::vec3 scale);

    void MarkAsDirty();

    void UpdateMatrix(bool updateChildren = true);

private:
    void SetEntity(Entity* entity);

    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;

    glm::mat4 worldMatrix;

    std::vector<Entity*> children;  //!< A vector of all children registered.
    Entity* parent;

    Entity* entity; //!< Entity this transform is a part of.

    bool isDirty = false;
};
