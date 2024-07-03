#include <string>
#include <functional>
#include <unordered_map>

#include "InputHandler.hpp"
#include "InputEvent.hpp"
#include "../utils/Logging.hpp"

// virtual
void InputHandler::emit(InputEvent event)
{
    Log::Info("Emitting event: {}", event.type);
}

// virtual
void InputHandler::broadcast(InputEvent event)
{
    Log::Info("Broadcasting event: {}", event.type);
}

// virtual
void InputHandler::onEvent(EventType type, std::function<void(Event event)> action)
{
    /*return EventBus::subject.get_observable()
        .filter([type](Event e){ return e.type == type; })
        .map([](Event e){ return e.data; })
        .subscribe(action);*/
}