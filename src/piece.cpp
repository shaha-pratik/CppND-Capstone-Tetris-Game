#include <algorithm>
#include <cmath>

#include "piece.h"

const double PI = std::acos(-1);

const int I[5][5] = {{0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0}};

const int L[5][5] = {{0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 1, 1, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0}};

const int Lm[5][5] = {{0, 0, 1, 0, 0},
                      {0, 0, 1, 0, 0},
                      {0, 1, 1, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0}};

const int N[5][5] = {{0, 0, 0, 0, 0},
                     {0, 0, 0, 1, 0},
                     {0, 0, 1, 1, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0}};

const int Nm[5][5] = {{0, 0, 0, 0, 0},
                      {0, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                      {0, 0, 1, 0, 0},
                      {0, 0, 0, 0, 0}};

const int S[5][5] = {{0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 0, 1, 1, 0},
                     {0, 0, 1, 1, 0},
                     {0, 0, 0, 0, 0}};

const int T[5][5] = {{0, 0, 0, 0, 0},
                     {0, 0, 0, 0, 0},
                     {0, 1, 1, 1, 0},
                     {0, 0, 1, 0, 0},
                     {0, 0, 1, 0, 0}};

Piece::Piece() : piece_type_(1), piece_rotation_(0) {
  UpdatePiece(piece_type_);
  RotatePiece(piece_rotation_);
}
Piece::Piece(int piece_type, int piece_rotation)
    : piece_type_(piece_type), piece_rotation_(piece_rotation) {
  UpdatePiece(piece_type_);
  RotatePiece(piece_rotation_);
}

int Piece::GetPieceType() const { return piece_type_; }

void Piece::UpdatePiece(int piece_type) {
  switch (PieceType(piece_type)) {
    case PieceType::IShape:
      std::copy(&I[0][0], &I[0][0] + 25, &piece_[0][0]);
      break;
    case PieceType::LShape:
      std::copy(&L[0][0], &L[0][0] + 25, &piece_[0][0]);
      break;
    case PieceType::LmShape:
      std::copy(&Lm[0][0], &Lm[0][0] + 25, &piece_[0][0]);
      break;
    case PieceType::NShape:
      std::copy(&N[0][0], &N[0][0] + 25, &piece_[0][0]);
      break;
    case PieceType::NmShape:
      std::copy(&Nm[0][0], &Nm[0][0] + 25, &piece_[0][0]);
      break;
    case PieceType::SquareShape:
      std::copy(&S[0][0], &S[0][0] + 25, &piece_[0][0]);
      break;
    case PieceType::TShape:
      std::copy(&T[0][0], &T[0][0] + 25, &piece_[0][0]);
      break;
  }
}

void Piece::RotatePiece(int piece_rotation) {
  if (piece_rotation == 0) {
    return;
  }

  double angle = piece_rotation * PI / 180;
  int x_origin = 3, y_origin = 3;
  int temp[5][5];
  std::copy(&piece_[0][0], &piece_[0][0] + 25, &temp[0][0]);

  for (int row = 0; row < SIZE; ++row) {
    for (int col = 0; col < SIZE; ++col) {
      int x_rotated = round((((row + 1) - x_origin) * cos(angle)) -
                            ((y_origin - (col + 1)) * sin(angle)) + x_origin) -
                      1;
      int y_rotated = round(((y_origin - (col + 1)) * cos(angle)) -
                            (((row + 1) - x_origin) * sin(angle)) + y_origin) -
                      1;
      piece_[row][col] = temp[x_rotated][y_rotated];
    }
  }
}

int Piece::GetInitialXPosition() const { return -2; }

int Piece::GetInitialYPosition() const {
  for (int i = 0; i < SIZE; i++) {
    if (piece_[3][i] == 1) return -3;
    if (piece_[4][i] == 1) return -4;
  }
  return -2;
}

int Piece::GetRotation() const {
  return piece_rotation_;
}