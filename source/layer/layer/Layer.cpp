#include "Layer.hpp"

Layer::Layer(const std::string& name = "Layer")
{
    this->name = name;
}

void Layer::Init()
{
    //
}

void Layer::Update()
{
    //
}

void Layer::Destroy()
{
    //
}

void Layer::OnAttach()
{
    //
}

void Layer::OnDetach()
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