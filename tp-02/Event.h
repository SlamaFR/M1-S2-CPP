#pragma once

#include <string>
#include <utility>
#include <iostream>

// Contains the number of minutes first, and then the number of seconds.
using Time = std::pair<unsigned int, unsigned int>;

class Event
{
public:
    Event(const Time& notif_time, const std::string& message)
        : _notif_time { notif_time }
        , _message { message }
    {}

    bool notify_time(unsigned int current_min, unsigned int current_sec)
    {
        if (this->_notif_time.first == current_min && this->_notif_time.second == current_sec) {
            std::cout << this->_message << std::endl;
            return true;
        }
        return false;
    }

private:
    Time        _notif_time;
    std::string _message;
};
