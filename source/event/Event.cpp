#include <string>
#include <functional>

#include "Event.hpp"

Event::Event(EventType type, void* data)
{
    this->type = type;
    if (data != nullptr)
        this->data = data;
}

Event::~Event()
{
    delete this->data;
}