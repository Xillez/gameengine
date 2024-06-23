#include <string>
#include <functional>
#include <unordered_map>

#include "./EventHandler.hpp"
#include "./Event.hpp"
#include "./EventListener.hpp"
#include "../utils/Logging.hpp"

// virtual
/*void EventHandler::emit(Event event, IEventListener* target = nullptr)
{
    LOG_INFO("Emitting event: " + event.type);
}

// virtual
void EventHandler::broadcast(Event event)
{
    LOG_INFO("Broadcasting event: " + event.type);
}

// virtual
void EventHandler::onEvent(EventType type, std::function<void(Event event)> action)
{
    /*return EventBus::subject.get_observable()
        .filter([type](Event e){ return e.type == type; })
        .map([](Event e){ return e.data; })
        .subscribe(action);*
}*/