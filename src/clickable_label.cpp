#include "clickable_label.h"

ClickableLabel::ClickableLabel(QWidget* parent) : QLabel(parent), row_(0), col_(0)
{
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
  if (event->button() == Qt::LeftButton)
  {
    emit clicked(row_, col_);
  }
}

void ClickableLabel::setPosition(int row, int col)
{
  row_ = row;
  col_ = col;
}
