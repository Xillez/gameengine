#pragma once

#include "Config.hpp"

#include <string>
#include <map>
#include <functional>

#include "Asset.hpp"
#include "Texture.hpp"

class TextureAsset : public Asset<Texture>
{
public:
    TextureAsset(const std::string& filepath = "");

    ~TextureAsset();

    Texture& Get();

    Texture& Load(const std::string& filepath);

private:
    Texture texture;
};