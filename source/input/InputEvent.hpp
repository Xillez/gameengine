#pragma once

#include <string>
#include <functional>

#include "../event/Event.hpp"

/**
 * Event class.
 */
class InputEvent : public Event
{
public:
    InputEvent(EventType type, void* data = nullptr);
    ~InputEvent();
};