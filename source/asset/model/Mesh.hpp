#pragma once

#include <vector>

#include "_glm.hpp"

class ModelAsset;
class Model;

class Mesh
{
    friend class ModelAsset;
    friend class Model;

public:
    Mesh();
    ~Mesh();

    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<glm::vec2> texCoords;
    std::vector<unsigned int> indices;
};