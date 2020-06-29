#ifndef __PIECE_H__
#define __PIECE_H__

#define SIZE 5

enum class PieceType {
  ZERO,
  IShape,
  LShape,
  LmShape,
  NShape,
  NmShape,
  SquareShape,
  TShape
};

class Piece {
 public:
  Piece();
  Piece(int piece_type, int piece_rotation);

  void RotatePiece(int piece_rotation = 1);

  int GetInitialXPosition() const;
  int GetInitialYPosition() const;

  int piece_[5][5];
  int GetPieceType() const;
  int GetRotation() const;
 private:
  int piece_type_{};
  int piece_rotation_{};
  void UpdatePiece(int piece_type);
};

#endif  // __PIECE_H__
