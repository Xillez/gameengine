#pragma once

#include <string>
#include <functional>
#include <unordered_map>

#include "InputEvent.hpp"

class InputHandler
{
public:
    /**
     * Emits an event on the eventbus.
     * 
     * @param event - Event - Event to emit.
     * 
     * @returns - boolean - "true" if broadcasted, "false" otherwise.
     */
    void emit(InputEvent event);

    /**
     * Emits an event on the eventbus.
     * 
     * @param event - Event - Event to emit.
     * 
     * @returns - boolean - "true" if broadcasted, "false" otherwise.
     */
    void broadcast(InputEvent event);

    /**
     * Function for handling events, should be called inside emit and broadcast.
     * 
     * @param event - Event.Events - Event type.
     * @param action - any - Callback action.virtual
     */
    void onEvent(EventType type, std::function<void(Event event)> action);
};