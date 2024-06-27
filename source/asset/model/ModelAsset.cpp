#include <functional>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "ModelAsset.hpp"

ModelAsset::ModelAsset(const std::string& filepath)
{
    if (filepath != "")
        this->Load(filepath);
}

ModelAsset::~ModelAsset()
{
    //SOIL_free_image_data(this->texture.image);
}

Model &ModelAsset::Get()
{
    return this->model;
}

Model &ModelAsset::Load(const std::string &filepath)
{
    Assimp::Importer importer;
    this->model.scene = importer.ReadFile(filepath, aiProcess_Triangulate);
    return this->model;
}