#pragma once

#include <string>
#include <map>
#include <functional>

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "../Asset.hpp"
#include "./Model.hpp"

class ModelAsset : public Asset<Model>
{
public:
    ModelAsset(const std::string& filepath = "");

    ~ModelAsset();

    Model& Get();
    
    Model& Load(const std::string& filepath);

//private:
    Model model;
};