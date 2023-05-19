#include "../Entity.hpp"
#include "../Component.hpp"

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>

class Transform : public Component
{
private:
    glm::vec3 position;
    glm::quat rotation;
    glm::vec3 scale;
};