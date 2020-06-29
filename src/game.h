#ifndef __GAME_H__
#define __GAME_H__

#include <random>
#include "board.h"
#include "controller.h"
#include "renderer.h"

const int rotation_value[7]{-270, -180, -90, 0, 90, 180, 270};

class Game {
 public:
  Game(Renderer &renderer);
  void Run(Controller &controller, const std::size_t &target_frame_duration);
  int GetScore() const;

 private:
  void DrawScene();
  void GenerateNewPiece();
  bool RestartGame();
  void Init();
  void DrawPiece(int pX, int pY, const Piece &piece);
  void DrawBoard();

  int position_x_{}, position_y_{};
  const int next_position_x_, next_position_y_;
  int piece_type_{}, piece_rotation_{}, next_piece_type_{},
      next_piece_rotation_{};

  Board board_;
  Piece piece_, next_piece_;
  int game_score_{};
  int screen_height{};

  Renderer renderer_;

  std::random_device device;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_shape;
  std::uniform_int_distribution<int> random_rotation;
};

#endif  // _GAME_
