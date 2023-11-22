#pragma once
//Solution

#include "IEventListener.h"
#include <set>
#include <cassert>
#include <memory>

template<typename EventType, typename EventListenerType>
class TEventManager
{
  using EventListenerPointerType = std::shared_ptr<EventListenerType>;
  using LstnrCollType = std::set<EventListenerPointerType>;
  LstnrCollType m_Listeners;

public:
  void registerListener(EventListenerPointerType listener)
  {
    if(listener != nullptr)
      m_Listeners.insert(listener);
  }
  void unregisterListener(EventListenerPointerType listener)
  {
    if (listener != nullptr)
      m_Listeners.erase(listener);
  }
  virtual void notifyEvent(const EventType& evt) const 
  {
    for(auto& listener : m_Listeners)
    {
      listener->OnEvent(evt);
    }
  };
};

using CMouseManager = TEventManager<CMouseEvent, IMouseListener>;
using CTickManager = TEventManager<CTickEvent, ITickListener>;
using CKeyboardManager = TEventManager<CKeyboardEvent, IKeyboardListener>;
//Fin Solution