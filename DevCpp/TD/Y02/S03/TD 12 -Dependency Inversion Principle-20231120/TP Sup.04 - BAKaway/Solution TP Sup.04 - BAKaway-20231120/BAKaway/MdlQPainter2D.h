#pragma once
#include "ModeleGraphique.h"
#include <QPainter>

class CMdlQPainter2D
  : public CModeleGraphique
{
  QPainter& m_painter;
  const QPixmap& m_pixmap;
  QSize m_size;

  CMdlQPainter2D(QPainter& painter, const QPixmap& pixmap, QSize size)
    : m_painter(painter)
    , m_pixmap(pixmap)
    , m_size(size)
  {}
  CMdlQPainter2D(const CMdlQPainter2D&) = default;

public:
  using ptr = std::shared_ptr<CMdlQPainter2D>;
  using const_ptr = std::shared_ptr<const CMdlQPainter2D>;

  static ptr create(QPainter& painter, const QPixmap& pixmap, QSize size)
  {
    return ptr(new CMdlQPainter2D(painter, pixmap, size));
  }

  //Solution
  void afficher(CPosition::const_ptr pos = nullptr) const override;
  /*
  //Fin Solution
  void afficher() const override;
  //Solution
  */
  //Fin Solution
};
