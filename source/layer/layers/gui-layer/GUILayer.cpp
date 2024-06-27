#include "GUILayer.hpp"

GUILayer::GUILayer(const std::string& name = "GUILayer")
{
    this->name = name;
}

void GUILayer::Begin()
{
    //
}

void GUILayer::Update()
{
    //
}

void GUILayer::End()
{
    //
}

void GUILayer::OnAttach()
{
    //
}

void GUILayer::OnDetach()
{
    //
}

//void Layer::OnEvent(Event& event)
//{
//    //
//}

const std::string& GUILayer::GetName() const
{
    return this->name;
}