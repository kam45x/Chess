#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGridLayout>
#include <vector>

#include "clickable_label.h"
#include "chess_board.h"

class Game : public QWidget
{
  Q_OBJECT

public:
  explicit Game(QWidget* parent = nullptr);

private slots:
  void handleSquareClicked(int row, int col);

private:
  void createBoard();

  void setPieceOnSquare(int row, int col, const QPixmap& pixmap);

  QGridLayout* gridLayout_;
  std::vector<std::vector<ClickableLabel*>> squares_;

  ChessBoard board_;
};

#endif  // GAME_H
