#include "IEventListener.h"
//Solution
#include <cassert>

void IKeyboardListener::OnEvent(const CKeyboardEvent& evt)
{
  if (evt.isDown())
    KeyDown(evt.keyCode());
  else
    KeyUp(evt.keyCode());
}

void IMouseListener::OnEvent(const CMouseEvent& evt)
{
  switch (evt.type())
  {
  case CMouseEvent::EvtType::MouseMove:
    MouseMove(evt.x(), evt.y());
    break;
  case CMouseEvent::EvtType::MouseDown:
    MouseDown(evt.button());
    break;
  case CMouseEvent::EvtType::MouseUp:
    MouseUp(evt.button());
    break;
  }
}

void ITickListener::OnEvent(const CTickEvent& evt)
{
  Tick();
}

//Fin Solution