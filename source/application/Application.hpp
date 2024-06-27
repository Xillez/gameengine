#pragma once

#include "LayerStack.hpp"

class Application
{
public:
    Application();
    virtual ~Application();

    // Delete copy constructor & copy assignment operator
    Application(const Application &other) = delete;
    Application(Application &&other) = delete;
    Application &operator=(const Application &other) = delete;
    Application &operator=(Application &&other) = delete;

    void init();
    int run();

private:
    LayerStack layerStack;
};
