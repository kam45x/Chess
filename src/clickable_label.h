#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
  Q_OBJECT

public:
  explicit ClickableLabel(QWidget* parent = nullptr);

signals:
  void clicked(int row, int col);

protected:
  void mousePressEvent(QMouseEvent* event) override;

public:
  void setPosition(int row, int col);

private:
  int row_;
  int col_;
};

#endif  // CLICKABLELABEL_H
