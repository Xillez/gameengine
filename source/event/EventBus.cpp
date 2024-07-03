#include <string>
#include <functional>
#include <unordered_map>

//#include "rx.hpp"

#include "Logging.hpp"
#include "EventBus.hpp"
#include "Event.hpp"

// static
bool EventBus::emit(Event event)
{
    Log::Info("Emitting event: " + event.type);
    //EventBus::subject.get_subscriber().on_next(event);
    return true;
}

// static
/*rxcpp::subscription*/ void EventBus::onEvent(EventType type, std::function<void(Event event)> action)
{
    /*return EventBus::subject.get_observable()
        .filter([type](Event e){ return e.type == type; })
        .map([](Event e){ return e.data; })
        .subscribe(action);*/
}