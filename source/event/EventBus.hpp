#pragma once

#include <string>
#include <functional>
#include <unordered_map>

//#include "rx.hpp"

#include "./Event.hpp"

class EventBus
{
public:
    //static const rxcpp::subjects::subject<Event> subject;

    /**
     * Emits an event on the eventbus.
     * 
     * @param event - Event - Event to emit.
     * 
     * @returns - boolean - "true" if broadcasted, "false" otherwise.
     */
    static bool emit(Event event);

    /**
     * Function for subscribing to an event on the eventbus.
     * 
     * @param event - Event.Events - Event type.
     * @param action - any - Callback action.
     * 
     * @returns - cpp::subscription - Subscription to this event.
     */
    static void /*rxcpp::subscription*/ onEvent(EventType type, std::function<void(Event event)> action);
};