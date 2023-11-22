#pragma once
//Solution
#include "Event.h"
#include <memory>

class IKeyboardListener
{
public:
  void OnEvent(const CKeyboardEvent& evt);

public:
  virtual void KeyDown(int nKeyCode) {};
  virtual void KeyUp(int nKeyCode) {};
};

class IMouseListener
{
public:
  void OnEvent(const CMouseEvent& evt);

public:
  virtual void MouseMove(int nPosX, int nPosY) {};
  virtual void MouseDown(CMouseEvent::Button nBtn) {};
  virtual void MouseUp(CMouseEvent::Button nBtn) {};
};

class ITickListener
{
public:
  void OnEvent(const CTickEvent& evt);

public:
  virtual void Tick() = 0;
};
//Fin Solution