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

  // Create a chess board object
  board_ = ChessBoard();
  updateBoard();
}

void Game::createBoard()
{
  squares_.clear();
  
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
  if (squareClicked_[0] == -1 && squareClicked_[1] == -1)
  {
    squareClicked_ = {row, col};
  }
  else
  {
    board_.makeMove(squareClicked_[0], squareClicked_[1], row, col);
    createBoard();
    updateBoard();
    squareClicked_ = {-1, -1};
  }
}

void Game::setPieceOnSquare(int row, int col, const QPixmap& pixmap)
{
  QSize squareSize = squares_[row][col]->size() * 2.5;
  QPixmap scaledPixmap = pixmap.scaled(squareSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);

  squares_[row][col]->setPixmap(scaledPixmap);
}

void Game::updateBoard()
{
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
      else
      {
        squares_[row][col]->clear();
      }
    }
  }
}
