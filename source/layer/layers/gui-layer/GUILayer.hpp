#pragma once
#include <string>

class GUILayer
{
public:
    GUILayer(const std::string& name);
    virtual ~GUILayer() = default;

    virtual void Begin();
    virtual void Update();
    virtual void End();

    virtual void OnAttach();
    virtual void OnDetach();
    //virtual void OnEvent(Event& event);

    const std::string& GetName() const;
protected:
    std::string name;
};