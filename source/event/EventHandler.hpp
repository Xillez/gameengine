#pragma once

#include <string>
#include <functional>
#include <unordered_map>
#include <vector>

#include "./Event.hpp"
#include "./EventListener.hpp"

class EventHandler : public IEventListener
{
public:
    /**
     * Emits an event to all or one of it's event listeners.
     * 
     * @param event - Event - Event to emit.
     * 
     * @returns - boolean - "true" if broadcasted, "false" otherwise.
     */
    virtual void emit(const Event& event, IEventListener* target = nullptr);

    /**
     * Function for handling events, should be called inside emit and broadcast.
     * 
     * @param event - Event.Events - Event type.
     * @param action - any - Callback action.
     */
    void registerListener(EventType type, IEventListener& listener);

    /**
     * Function for handling events, should be called inside emit and broadcast.
     * 
     * @param event - Event.Events - Event type.
     * @param action - any - Callback action.
     */
    void registerListener(EventType type, std::function<void(Event event)>& action);
    /*template<typename Tevent>
    void registerListener(EventType type, std::function<void(Tevent event)>& action);*/

private: 
    std::unordered_map<EventType, std::vector<IEventListener>> listeners_obj;
    std::unordered_map<EventType, std::vector<std::function<void(Event event)>>> listeners_func;
};