#ifndef __PIECES_H__
#define __PIECES_H__

#include <vector>
#include <string>
#include <map>

enum PieceType {
    Square_Shape,
    L_Shape,
    L_Mirror_Shape,
    N_Shape,
    N_Mirror_Shape,
    T_Shape,
    I_Shape
};

class Pieces {
    public:
    // Constructor
    Pieces();
    Pieces(const PieceType shape, int rotation);

    // Setter and getter method
    void SetShape(const PieceType shape);
    void SetRotation(int rotation);

    PieceType GetShape() const;
    int GetRotation() const;
    // Other method
    std::vector<std::vector<int>> GetPieces() const;

    private:
    std::pair<int, int> RotatePosition(const std::pair<int, int> &point) const;
    void Rotate(std::vector<std::vector<int>>& piece) const;
    
    PieceType shape_{};
    int rotation_{};
    std::vector<std::vector<int>> square_shape_ {{ 0, 0, 0, 0, 0 },
                                                 { 0, 0, 1, 1, 0 },
                                                 { 0, 0, -1, 1, 0 },
                                                 { 0, 0, 0, 0, 0 },
                                                 { 0, 0, 0, 0, 0 }};
    std::vector<std::vector<int>> L_shape_ {{ 0, 0, 1, 0, 0 },
                                            { 0, 0, 1, 0, 0 },
                                            { 0, 0, -1, 1, 0 },
                                            { 0, 0, 0, 0, 0 },
                                            { 0, 0, 0, 0, 0 }};
    std::vector<std::vector<int>> L_M_shape_ {{ 0, 0, 1, 0, 0 },
                                            { 0, 0, 1, 0, 0 },
                                            { 0, 1, -1, 0, 0 },
                                            { 0, 0, 0, 0, 0 },
                                            { 0, 0, 0, 0, 0 }};
    std::vector<std::vector<int>> N_shape_ {{ 0, 0, 0, 0, 0 },
                                            { 0, 0, 0, 1, 0 },
                                            { 0, 0, -1, 1, 0 },
                                            { 0, 0, 1, 0, 0 },
                                            { 0, 0, 0, 0, 0 }};
    std::vector<std::vector<int>> N_M_shape_ {{ 0, 0, 0, 0, 0 },
                                            { 0, 0, 1, 0, 0 },
                                            { 0, 0, -1, 1, 0 },
                                            { 0, 0, 0, 1, 0 },
                                            { 0, 0, 0, 0, 0 }};
    std::vector<std::vector<int>> T_shape_ {{ 0, 0, 0, 0, 0 },
                                            { 0, 0, 0, 0, 0 },
                                            { 0, 1, -1, 1, 0 },
                                            { 0, 0, 1, 0, 0 },
                                            { 0, 0, 1, 0, 0 }};
    std::vector<std::vector<int>> I_shape_ {{ 0, 0, 0, 0, 0 },
                                            { 0, 0, 1, 0, 0 },
                                            { 0, 0, -1, 0, 0 },
                                            { 0, 0, 1, 0, 0 },
                                            { 0, 0, 1, 0, 0 }};
};

#endif // __PIECES_H__