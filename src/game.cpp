#include "game.h"

#include <QLabel>
#include <QDebug>
#include <QPixmap>

Game::Game(QWidget* parent) : QWidget(parent)
{
  gridLayout_ = new QGridLayout(this);
  gridLayout_->setSpacing(0);

  createBoard();
  setLayout(gridLayout_);

  resize(800, 800);

  // Create a chess board
  board_ = ChessBoard();
  for (int row = 0; row < 8; ++row)
  {
    for (int col = 0; col < 8; ++col)
    {
      std::string piece = board_.getPiece(row, col);
      if (piece != "__")
      {
        QPixmap pixmap("../images/" + QString::fromStdString(piece) + ".png");
        setPieceOnSquare(row, col, pixmap);
      }
    }
  }
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
        square->setStyleSheet("QLabel { background-color : gray; }");
      }

      square->setAlignment(Qt::AlignCenter);

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

void Game::setPieceOnSquare(int row, int col, const QPixmap& pixmap)
{
  QSize squareSize = squares_[row][col]->size() * 2.5;
  QPixmap scaledPixmap = pixmap.scaled(squareSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

  squares_[row][col]->setPixmap(scaledPixmap);
}
