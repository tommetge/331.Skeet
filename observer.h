/***********************************************************************
 * Header File:
 *    Observable : Defines an observer class
 * Author:
 *    Team 1
 * Summary:
 *    Defines a observer (pattern) class
 ************************************************************************/

#pragma once
#include <list>

enum Message {
    ObservableIsDead = 0,
};

class Observable;

class Observer
{
public:
    virtual void notify(Message message, Observable *obj) = 0;
};

/**********************
 * Observable: Defines an observer (pattern) class
 **********************/
class Observable
{
public:
    void subscribe(Observer *observer)
    {
        auto it = std::find(subscribers.begin(), subscribers.end(), observer);
        if (it == subscribers.end()) {
            subscribers.push_back(observer);
        }
    }

    void unsubscribe(Observer *observer)
    {
        for (auto it = subscribers.begin(); it != subscribers.end();)
        {
            if (*it == observer) {
                it = subscribers.erase(it);
            } else {
                ++it;
            }
        }
    }

    void notify(Message message)
    {
        for (auto subscriber: subscribers) {
            subscriber->notify(message, this);
        }
    }

protected:
    std::list<Observer *> subscribers;
};
