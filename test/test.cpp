#include <gtest/gtest.h>

#define private public
#include "piece.h"

TEST(PiecesTest, ConstructorTest) {
  Piece default_piece;
  EXPECT_EQ(default_piece.GetPieceType(), 1);
  EXPECT_EQ(default_piece.GetRotation(), 0);

  Piece piece(int(PieceType::SquareShape), 270);
  EXPECT_EQ(piece.GetPieceType(), 6);
  EXPECT_EQ(piece.GetRotation(), 270);
}

TEST(PiecesTest, Rotate_90) {
  Piece pieces;

  int test_vector[5][5] = {{1, 2, 3, 4, 5},
                           {6, 7, 8, 9, 10},
                           {11, 12, 13, 14, 15},
                           {16, 17, 18, 19, 20},
                           {21, 22, 23, 24, 25}};
  int expected_out[5][5] = {{5, 10, 15, 20, 25},
                            {4, 9, 14, 19, 24},
                            {3, 8, 13, 18, 23},
                            {2, 7, 12, 17, 22},
                            {1, 6, 11, 16, 21}};
  std::copy(&test_vector[0][0], &test_vector[0][0] + 25, &pieces.piece_[0][0]);
  pieces.RotatePiece(90);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      EXPECT_EQ(pieces.piece_[i][j], expected_out[i][j]);
    }
  }
}

TEST(PiecesTest, Rotate_180) {
  Piece pieces;
  int test_vector[5][5]{{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}};
  int expected_out[5][5]{{21, 22, 23, 24, 25},
                         {16, 17, 18, 19, 20},
                         {11, 12, 13, 14, 15},
                         {6, 7, 8, 9, 10},
                         {1, 2, 3, 4, 5}};

  std::copy(&test_vector[0][0], &test_vector[0][0] + 25, &pieces.piece_[0][0]);
  pieces.RotatePiece(180);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      EXPECT_EQ(pieces.piece_[i][j], expected_out[i][j]);
    }
  }
}

TEST(PiecesTest, Rotate_270) {
  Piece pieces;
  int test_vector[5][5]{{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}};

  int expected_out[5][5]{{21, 16, 11, 6, 1},
                         {22, 17, 12, 7, 2},
                         {23, 18, 13, 8, 3},
                         {24, 19, 14, 9, 4},
                         {25, 20, 15, 10, 5}};

  std::copy(&test_vector[0][0], &test_vector[0][0] + 25, &pieces.piece_[0][0]);
  pieces.RotatePiece(270);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      EXPECT_EQ(pieces.piece_[i][j], expected_out[i][j]);
    }
  }
}

TEST(PiecesTest, Rotate_0) {
  Piece pieces;
  int test_vector[5][5]{{1, 2, 3, 4, 5},
                        {6, 7, 8, 9, 10},
                        {11, 12, 13, 14, 15},
                        {16, 17, 18, 19, 20},
                        {21, 22, 23, 24, 25}};
  int expected_out[5][5]{{1, 2, 3, 4, 5},
                         {6, 7, 8, 9, 10},
                         {11, 12, 13, 14, 15},
                         {16, 17, 18, 19, 20},
                         {21, 22, 23, 24, 25}};

  std::copy(&test_vector[0][0], &test_vector[0][0] + 25, &pieces.piece_[0][0]);
  pieces.RotatePiece(0);
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      EXPECT_EQ(pieces.piece_[i][j], expected_out[i][j]);
    }
  }
}

TEST(PiecesTest, GetPiece_LShape_90) {
  Piece piece(int(PieceType::LShape), 90);
  int expected_output[5][5]{{0, 0, 0, 0, 0},
                            {0, 0, 1, 0, 0},
                            {1, 1, 1, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0}};

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      EXPECT_EQ(piece.piece_[i][j], expected_output[i][j]);
    }
  }
}

TEST(PiecesTest, GetPiece_LMirrorShape_180) {
  Piece piece(int(PieceType::LmShape), 180);
  int expected_output[5][5]{{0, 0, 0, 0, 0},
                            {0, 0, 0, 0, 0},
                            {0, 1, 1, 0, 0},
                            {0, 0, 1, 0, 0},
                            {0, 0, 1, 0, 0}};

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      EXPECT_EQ(piece.piece_[i][j], expected_output[i][j]);
    }
  }
}