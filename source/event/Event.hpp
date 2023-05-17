#pragma once

#include <string>
#include <functional>

/**
 * Available events
 */
enum EventType
{
    BatchEvent,

    AssetsLoadAllEvent,
    AssetLoadingEvent,
    AssetLoadedEvent,
    AssetUpdatedEvent,
    AllAssetsLoadedEvent,

    WorldCreatedEvent,

    SceneCreatedEvent,
    SceneContentUpdateEvent,

    PageResizeEvent,

    ValidationEvent,

    DestructionEvent,

    CanvasCreatedEvent,
    CanvasResizeEvent,
    CanvasUpdateEvent, 
    CanvasReassignedEvent, 
    CanvasDestroyedEvent,

    RendererResizeEvent,
    RenderEvent
};

/**
 * Event class.
 */
class Event
{
public:
    EventType type;
    void* data = nullptr;

    Event(EventType type, void* data = nullptr);
    ~Event();
};