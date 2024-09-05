#include "chess_board.h"

ChessBoard::ChessBoard()
{
  // Make the board start chess position
  board_ = { { "bR", "bN", "bB", "bQ", "bK", "bB", "bN", "bR" }, { "bP", "bP", "bP", "bP", "bP", "bP", "bP", "bP" },
             { "__", "__", "__", "__", "__", "__", "__", "__" }, { "__", "__", "__", "__", "__", "__", "__", "__" },
             { "__", "__", "__", "__", "__", "__", "__", "__" }, { "__", "__", "__", "__", "__", "__", "__", "__" },
             { "wP", "wP", "wP", "wP", "wP", "wP", "wP", "wP" }, { "wR", "wN", "wB", "wQ", "wK", "wB", "wN", "wR" } };
}

ChessBoard::ChessBoard(const std::vector<std::vector<std::string>>& board)
{
  board_ = board;
}

std::string ChessBoard::getPiece(int row, int col) const
{
  return board_[row][col];
}