#include <string>
#include <functional>

#include "InputEvent.hpp"

InputEvent::InputEvent(EventType type, void* data) : Event(type, data)
{
    this->type = type;
    if (data != nullptr)
        this->data = data;
}

InputEvent::~InputEvent()
{
    //
}