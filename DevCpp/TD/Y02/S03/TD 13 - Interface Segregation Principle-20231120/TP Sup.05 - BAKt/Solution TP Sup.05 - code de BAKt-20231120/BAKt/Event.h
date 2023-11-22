#pragma once
class CKeyboardEvent
{
private:
  bool m_bDown;
  int m_nKeyCode;
public:
  CKeyboardEvent(bool bDown, int nKeyCode)
    : m_bDown(bDown)
    , m_nKeyCode(nKeyCode)
  {}
  bool isDown() const { return m_bDown; }
  int keyCode() const { return m_nKeyCode; }
};

class CMouseEvent
{
public:
  enum class EvtType {
    MouseMove,
    MouseDown,
    MouseUp
  };
  enum class Button {
    Left,
    Middle,
    Right
  };
private:
  EvtType m_nType;
  union {
    Button m_nBtn;
    struct {
      int m_nPosX;
      int m_nPosY;
    };
  };
public:
  CMouseEvent(int nPosX, int nPosY)
    : m_nPosX(nPosX)
    , m_nPosY(nPosY)
    , m_nType(EvtType::MouseMove)
  {}
  CMouseEvent(bool bDown, Button button)
    : m_nType(bDown ? EvtType::MouseDown : EvtType::MouseUp)
    , m_nBtn(button)
  {}
  EvtType type() const { return m_nType; }
  int x() const { return m_nPosX; }
  int y() const { return m_nPosY; }
  Button button() const { return m_nBtn; }
};

class CTickEvent
{
};

