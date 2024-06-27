#include "Layer.hpp"

Layer::Layer(const std::string& name = "Layer")
{
    this->name = name;
}

void Layer::OnAttach()
{
    //
}

void Layer::OnDetach()
{
    //
}

void Layer::OnUpdate()
{
    //
}

//void Layer::OnEvent(Event& event)
//{
//    //
//}

const std::string& Layer::GetName() const
{
    return this->name;
}