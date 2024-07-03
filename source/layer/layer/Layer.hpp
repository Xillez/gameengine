#pragma once
#include <string>

class Layer
{
public:
    Layer(const std::string& name);
    virtual ~Layer() = default;

    virtual void Init();
    virtual void Update();
    virtual void Destroy();

    virtual void OnAttach();
    virtual void OnDetach();
    //virtual void OnEvent(Event& event);

    const std::string& GetName() const;
protected:
    std::string name;
};