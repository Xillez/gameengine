#pragma once

#include <string>
#include <map>
#include <functional>
#include <vector>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "./Mesh.hpp"

class ModelAsset;

class Model
{
    friend class ModelAsset;

public:
    Model();

    ~Model();

    const aiScene* scene;

    std::vector<Mesh> meshes;
};