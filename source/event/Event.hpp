#pragma once

#include <string>
#include <functional>

/**
 * Available events
 */
enum EventType
{
    BatchEvent,
    RenderEvent,
    ResizeEvent,
    TransformUpdate,
    DestructionEvent
};
enum EventPhase
{
    Decending,
    Ascending
};

/**
 * Event class.
 */
class Event
{
public:
    EventType type;
    EventType phase;
    void* data = nullptr;
    void* sender = nullptr;
    void* target = nullptr;

    Event(EventType type, void* data = nullptr);
    ~Event();
};