#pragma once
#include <iostream>
#include <memory>

#include "_sdl.hpp"

#include "LayerStack.hpp"
#include "GUILayer.hpp"
#include "Logging.hpp"

class Point
{
public:
    Point(float x, float y) : x(x), y(y) {};

    float x, y;
};

DEFINE_FORMATTER(Point, {
    std::cout << "Formatting Point with presentation_: " << this->presentation_ << std::endl;
    switch (this->presentation_) {
        case 'e':
            return fmt::format_to(ctx.out(), "Point: ({:e}, {:e})", value.x, value.y);
        case 'f':
        default:
            return fmt::format_to(ctx.out(), "Point: ({:f}, {:f})", value.x, value.y);
    }
})

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

    std::shared_ptr<GUILayer> guiLayer;
};
