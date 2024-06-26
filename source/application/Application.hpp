#pragma once

#include "_sdl.hpp"

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

    int init();
    int run();

private:
    LayerStack layerStack;

    // Main application window and glContext
    SDL_Window* window;
    SDL_GLContext glContext;
};
