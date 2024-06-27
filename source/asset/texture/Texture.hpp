#pragma once

#include "Config.hpp"

#include <string>
#include <map>
#include <functional>

#include "uuid.hpp"

#include "Asset.hpp"

class TextureAsset;

class Texture
{
    friend class TextureAsset;

public:
    Texture();

    ~Texture();

private:
    unsigned char* image;
    int width;
    int height;
    int channels;
};