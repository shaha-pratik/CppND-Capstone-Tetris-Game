#ifndef _BOARD_H__
#define _BOARD_H__

#include <cstddef>
#include "piece.h"

#define BOARD_LINE_WIDTH 6
#define BLOCK_SIZE 20
#define BOARD_POSITION 300
#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define PIECE_BLOCKS 5

enum class BoardPixel { POS_FREE, POS_FILLED };

class Board {
 public:
  Board() = default;
  Board(Piece& piece, const std::size_t& screen_width,
        const std::size_t& screen_height);
  int GetXPostionInPixel(int pos_x) const;
  int GetYPositionInPixel(int pos_y) const;
  bool IsBlockFree(int pos_x, int pos_y) const;

  bool IsMovementPossibleInBlock(int pos_x, int pos_y) const;
  void StorePieceInBoard(int pos_x, int pos_y);
  int DeletePossibleLines();
  bool IsGameOver() const;
  void UpdateCurrentPiece(const Piece& piece);
  void ClearBoard();
  Piece piece_;

 private:
  int screen_height_{};
  int screen_width_{};

  int board_[BOARD_WIDTH][BOARD_HEIGHT];

  void InitBoard();
  void DeleteLine(int pY);
};

#endif  // __BOARD_H_
