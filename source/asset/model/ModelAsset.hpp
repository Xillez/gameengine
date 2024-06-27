#pragma once

#include <string>
#include <map>

#include "Asset.hpp"
#include "Model.hpp"

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