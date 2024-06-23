#pragma once

#include "Event.hpp"

class IEventListener {
public:
    virtual void handleEvent(const Event& event) = 0;
};