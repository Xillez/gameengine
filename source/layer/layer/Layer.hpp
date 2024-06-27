#pragma once
#include <string>

class Layer
{
public:
    Layer(const std::string& name);
    virtual ~Layer() = default;

    virtual void OnAttach();
    virtual void OnDetach();
    virtual void OnUpdate();
    //virtual void OnEvent(Event& event);

    const std::string& GetName() const;
protected:
    std::string name;
};