#pragma once
#include "magicball.h"
#include "Event.h"
#include "IEventListener.h"

class CVeryMagicBall
  : public CMagicBall
  //Solution
  , public ITickListener
  //Fin Solution
{
public:
  CVeryMagicBall(int nRadius);

  void MouseDown(CMouseEvent::Button button);
  void Tick();
};

