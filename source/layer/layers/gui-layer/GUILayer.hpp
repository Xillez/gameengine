#pragma once
#include <string>

#include "Layer.hpp"

class GUILayer : public Layer
{
public:
    GUILayer(SDL_Window* window, SDL_GLContext& glContext);
    virtual ~GUILayer() = default;

    virtual void Init();
    virtual void Update();
    virtual void Destroy();

    virtual void OnAttach();
    virtual void OnDetach();
    //virtual void OnEvent(Event& event);

    const std::string& GetName() const;
protected:
    std::string name;

    // Main application window and glContext
    SDL_Window* window;
    SDL_GLContext glContext;
};