#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include <vector>
#include <string>

class ChessBoard
{
public:
  ChessBoard();
  ChessBoard(const std::vector<std::vector<std::string>>& board);

  std::string getPiece(int row, int col) const;

  void makeMove(int fromRow, int fromCol, int toRow, int toCol);

private:
  std::vector<std::vector<std::string>> board_;
};

#endif  // CHESS_BOARD_H