#include <gtest/gtest.h>

#define private public
#include "pieces.h"


TEST(PiecesTest, ConstructorTest) {
    Pieces default_pieces;
    EXPECT_EQ(default_pieces.GetShape(), PieceType::I_Shape);
    EXPECT_EQ(default_pieces.GetRotation(), 0);

    Pieces pieces(PieceType::Square_Shape, 270);
    EXPECT_EQ(pieces.GetShape(), PieceType::Square_Shape);
    EXPECT_EQ(pieces.GetRotation(), 270);
}

TEST(PiecesTest, SetterGetterTest) {
    Pieces default_pieces;
    default_pieces.SetShape(PieceType::L_Shape);
    EXPECT_EQ(default_pieces.GetShape(), PieceType::L_Shape);
    default_pieces.SetRotation(90);
    EXPECT_EQ(default_pieces.GetRotation(), 90);
}

TEST(PiecesTest, Rotate_90) {
    Pieces pieces(PieceType::L_Shape, 0);
    std::vector<std::vector<int>> test_vector{{1, 2, 3, 4, 5},
                                              {6, 7, 8, 9, 10},
                                              {11, 12, 13, 14, 15},
                                              {16, 17, 18, 19, 20},
                                              {21, 22, 23, 24, 25}};
    std::vector<std::vector<int>> expected_out{{5, 10, 15, 20, 25},
                                              {4, 9, 14, 19, 24},
                                              {3, 8, 13, 18, 23},
                                              {2, 7, 12, 17, 22},
                                              {1, 6, 11, 16, 21}};
    pieces.SetRotation(90);
    pieces.Rotate(test_vector);
    EXPECT_EQ(test_vector, expected_out);
}

TEST(PiecesTest, Rotate_180) {
    Pieces pieces(PieceType::L_Shape, 0);
    std::vector<std::vector<int>> test_vector{{1, 2, 3, 4, 5},
                                              {6, 7, 8, 9, 10},
                                              {11, 12, 13, 14, 15},
                                              {16, 17, 18, 19, 20},
                                              {21, 22, 23, 24, 25}};
    std::vector<std::vector<int>> expected_out{{21, 22, 23, 24, 25},
                                              {16, 17, 18, 19, 20},
                                              {11, 12, 13, 14, 15},
                                              {6, 7, 8, 9, 10},
                                              {1, 2, 3, 4, 5}};

    pieces.SetRotation(180);
    pieces.Rotate(test_vector);
    EXPECT_EQ(test_vector, expected_out);
}

TEST(PiecesTest, Rotate_270) {
    Pieces pieces(PieceType::L_Shape, 0);
    std::vector<std::vector<int>> test_vector{{1, 2, 3, 4, 5},
                                              {6, 7, 8, 9, 10},
                                              {11, 12, 13, 14, 15},
                                              {16, 17, 18, 19, 20},
                                              {21, 22, 23, 24, 25}};

    std::vector<std::vector<int>> expected_out{{21, 16, 11, 6, 1},
                                              {22, 17, 12, 7, 2},
                                              {23, 18, 13, 8, 3},
                                              {24, 19, 14, 9, 4},
                                              {25, 20, 15, 10, 5}};

    pieces.SetRotation(270);
    pieces.Rotate(test_vector);
    EXPECT_EQ(test_vector, expected_out);
}

TEST(PiecesTest, Rotate_0) {
    Pieces pieces(PieceType::L_Shape, 0);
    std::vector<std::vector<int>> test_vector{{1, 2, 3, 4, 5},
                                              {6, 7, 8, 9, 10},
                                              {11, 12, 13, 14, 15},
                                              {16, 17, 18, 19, 20},
                                              {21, 22, 23, 24, 25}};
    std::vector<std::vector<int>> expected_out{{1, 2, 3, 4, 5},
                                              {6, 7, 8, 9, 10},
                                              {11, 12, 13, 14, 15},
                                              {16, 17, 18, 19, 20},
                                              {21, 22, 23, 24, 25}};

    pieces.SetRotation(0);
    pieces.Rotate(test_vector);
    EXPECT_EQ(test_vector, expected_out);
}

TEST(PiecesTest, GetPiece_LShape_90) {
    Pieces piece(PieceType::L_Shape, 90);
    std::vector<std::vector<int>> expected_output {{ 0, 0, 0, 0, 0 },
                                            { 0, 0, 1, 0, 0 },
                                            { 1, 1, -1, 0, 0 },
                                            { 0, 0, 0, 0, 0 },
                                            { 0, 0, 0, 0, 0 }};
    auto actual_output = piece.GetPieces();
    
    EXPECT_EQ(expected_output, actual_output);
}

TEST(PiecesTest, GetPiece_SquareShape_180) {
    Pieces piece(PieceType::Square_Shape, 180);
    std::vector<std::vector<int>> expected_output {{ 0, 0, 0, 0, 0 },
                                                 { 0, 0, 0, 0, 0 },
                                                 { 0, 0, -1, 1, 0 },
                                                 { 0, 0, 1, 1, 0 },
                                                 { 0, 0, 0, 0, 0 }};
    auto actual_output = piece.GetPieces();
    
    EXPECT_EQ(expected_output, actual_output);
}

TEST(PiecesTest, GetPiece_LMirrorShape_180) {
    Pieces piece(PieceType::L_Mirror_Shape, 180);
    std::vector<std::vector<int>> expected_output{{ 0, 0, 0, 0, 0 },
                                            { 0, 0, 0, 0, 0 },
                                            { 0, 1, -1, 0, 0 },
                                            { 0, 0, 1, 0, 0 },
                                            { 0, 0, 1, 0, 0 }};
    auto actual_output = piece.GetPieces();
    
    EXPECT_EQ(expected_output, actual_output);
}