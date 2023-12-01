#include "./TextureAsset.hpp"

TextureAsset::TextureAsset(const std::string &filepath)
{
    if (filepath != "")
        this->Load(filepath);
}

TextureAsset::~TextureAsset()
{
    SOIL_free_image_data(this->texture.image);
}

Texture &TextureAsset::Get()
{
    return this->texture;
}

Texture &TextureAsset::Load(const std::string &filepath)
{
    this->texture.image = SOIL_load_image(
        filepath.c_str(),
        &this->texture.width,
        &this->texture.height,
        &this->texture.channels,
        SOIL_LOAD_RGBA
    );
    return this->texture;
}