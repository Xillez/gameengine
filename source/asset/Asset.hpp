#pragma once

#include <string>
#include <map>
#include <functional>

class ModelAsset;
class TextureAsset;

// Base class for all assets
template<typename Tdata>
class Asset
{
public:
    virtual Tdata& Load(const std::string& filePath) = 0;
    virtual Tdata& Get() = 0;
};