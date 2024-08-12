#include "game.h"
#include <QLabel>
#include <QDebug>

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
    std::vector<ClickableLabel*> rowSquares;
    for (int col = 0; col < 8; ++col)
    {
      ClickableLabel* square = new ClickableLabel(this);
      square->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

      square->setPosition(row, col);

      // Determine the color
      if ((row + col) % 2 == 0)
      {
        square->setStyleSheet("QLabel { background-color : white; }");
      }
      else
      {
        square->setStyleSheet("QLabel { background-color : black; }");
      }

      // Connect the click signal to the slot
      connect(square, &ClickableLabel::clicked, this, &Game::handleSquareClicked);

      // Add the square to the grid layout
      gridLayout_->addWidget(square, row, col);
      rowSquares.push_back(square);
    }
    squares_.push_back(rowSquares);
  }
}

void Game::handleSquareClicked(int row, int col)
{
  qDebug() << "Square clicked at position:" << row << "," << col;
}
