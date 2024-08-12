#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGridLayout>

class Game : public QWidget
{
  Q_OBJECT

public:
  explicit Game(QWidget* parent = nullptr);

private:
  void createBoard();

  QGridLayout* gridLayout_;
};

#endif  // GAME_H
