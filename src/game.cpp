#include "game.h"
#include <QLabel>

Game::Game(QWidget* parent) : QWidget(parent)
{
  gridLayout_ = new QGridLayout(this);
  gridLayout_->setSpacing(0); 

  createBoard();
  setLayout(gridLayout_);

  resize(800, 800);
}

void Game::createBoard()
{
  for (int row = 0; row < 8; ++row)
  {
    for (int col = 0; col < 8; ++col)
    {
      QLabel* square = new QLabel(this);
      square->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      // Determine the color
      if ((row + col) % 2 == 0)
      {
        square->setStyleSheet("QLabel { background-color : white; }");
      }
      else
      {
        square->setStyleSheet("QLabel { background-color : black; }");
      }

      gridLayout_->addWidget(square, row, col);
    }
  }
}
