#include "LayerStack.hpp"

LayerStack::LayerStack()
{
    // TODO: Needs implementation
}

LayerStack::~LayerStack()
{
    // TODO: Needs implementation
}

void LayerStack::pushLayer(std::shared_ptr<Layer> layer)
{
    this->layers.push_back(layer);
}

std::shared_ptr<Layer> LayerStack::popLayer()
{
    return this->popLayerAt(this->layers.size() - 1);
}

std::shared_ptr<Layer> LayerStack::peekLayer(int index)
{
    return this->layers[index];
}

void LayerStack::pushLayerAt(std::shared_ptr<Layer> layer, int index)
{
    this->layers.insert(this->layers.begin() + index, layer);
}

std::shared_ptr<Layer> LayerStack::popLayerAt(int index)
{
    std::shared_ptr<Layer> layer = this->layers[index];
    this->layers.erase(this->layers.begin() + index);
    return layer;
}

void LayerStack::swapLayers(int index1, int index2)
{
    std::shared_ptr<Layer> temp = this->layers[index1];
    this->layers[index1] = this->layers[index2];
    this->layers[index2] = temp;
}

int LayerStack::size() const
{
    return this->layers.size();
}

std::vector<std::shared_ptr<Layer>>::iterator LayerStack::begin()
{
    return this->layers.begin();
}

std::vector<std::shared_ptr<Layer>>::iterator LayerStack::end()
{
    return this->layers.end();
}