#ifndef HV_EVENT_HPP_
#define HV_EVENT_HPP_

#include <functional>
#include <memory>

#include "hloop.h"

namespace hv {

struct Event;
struct Timer;

typedef uint64_t            TimerID;
#define INVALID_TIMER_ID    ((TimerID)-1)

typedef std::function<void(Event*)>     EventCallback;
typedef std::function<void(TimerID)>    TimerCallback;

struct Event {
    hevent_t        event;
    EventCallback   cb;

    Event(EventCallback cb = NULL) {
        memset(&event, 0, sizeof(hevent_t));
        this->cb = cb;
    }
};

struct Timer {
    htimer_t*       timer;
    TimerCallback   cb;
    int             repeat;

    Timer(htimer_t* timer = NULL, TimerCallback cb = NULL, int repeat = INFINITE) {
        this->timer = timer;
        this->cb = cb;
        this->repeat = repeat;
    }
};

typedef std::shared_ptr<Event> EventPtr;
typedef std::shared_ptr<Timer> TimerPtr;

}

#endif // HV_EVENT_HPP_
