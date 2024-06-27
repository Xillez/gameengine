#pragma once

#include <vector>
#include <memory>

#include "Layer.hpp"

class LayerStack
{
public:
    LayerStack();
    ~LayerStack();

    void pushLayer(std::shared_ptr<Layer> layer);
    std::shared_ptr<Layer> popLayer();
    std::shared_ptr<Layer> peekLayer(int index = -1);
    void pushLayerAt(std::shared_ptr<Layer> layer, int index = -1);
    std::shared_ptr<Layer> popLayerAt(int index = -1);
    void swapLayers(int index1, int index2);

    std::vector<std::shared_ptr<Layer>>::iterator begin();
    std::vector<std::shared_ptr<Layer>>::iterator end();

private:
    std::vector<std::shared_ptr<Layer>> layers;
};