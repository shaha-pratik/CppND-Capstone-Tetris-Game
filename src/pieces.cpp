#include "pieces.h"
#include <cmath>
#include <iostream>

const double PI = std::acos(-1);

Pieces::Pieces() : 
shape_(PieceType::I_Shape),
rotation_(0)
{}
Pieces::Pieces(PieceType shape, int rotation)  : shape_(shape), rotation_(rotation)
{}

void Pieces::SetShape(PieceType shape) {
    shape_ = shape;
}

void Pieces::SetRotation(int rotation) {
    rotation_ = rotation;
}

PieceType Pieces::GetShape() const {
    return shape_;
}

int Pieces::GetRotation() const {
    return rotation_;
};

std::pair<int, int> Pieces::RotatePosition(const std::pair<int, int> &point) const {
    double angle = rotation_ * PI / 180;
    int x_origin = 3, y_origin = 3;

    auto x_rotated = ((point.first - x_origin) * cos(angle)) - ((y_origin - point.second) * sin(angle)) + x_origin;
    auto y_rotated = ((y_origin - point.second) * cos(angle)) - ((point.first - x_origin) * sin(angle)) + y_origin;
    return std::make_pair(round(x_rotated), round(y_rotated));
}

void Pieces::Rotate(std::vector<std::vector<int>>& piece) const {
    if (rotation_ == 0) {
        return;
    }
    auto temp = piece;
    for (int row = 0; row < piece.size(); ++row) {
        for (int col = 0; col < piece[0].size(); ++col) {
            auto update_point = RotatePosition(std::make_pair(row+1, col+1));
            piece[row][col] = temp[update_point.first - 1][update_point.second - 1];
        }
    }
}

std::vector<std::vector<int>> Pieces::GetPieces() const {
    std::vector<std::vector<int>> piece(5, std::vector<int>(5,0));

    switch (shape_)
    {
    case Square_Shape:
        piece = square_shape_;
        break;
    case L_Shape:
        piece = L_shape_;
        break;
    case L_Mirror_Shape:
        piece = L_M_shape_;
        break;
    case N_Shape:
        piece = N_shape_;
        break;
    case N_Mirror_Shape:
        piece = N_M_shape_;
        break;
    case T_Shape:
        piece = T_shape_;
        break;
    case I_Shape:
    default:
        piece = I_shape_;
        break;
    }
    Rotate(piece);
    return piece;
};
