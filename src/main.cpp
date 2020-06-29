#include <iostream>
#include "game.h"
#include "controller.h"
#include "renderer.h"

int main(int argc, char* args[]) {
  constexpr std::size_t kScreenWidth{600};
  constexpr std::size_t kScreenHeight{500};
  constexpr std::size_t kFramesPerSecond{2};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};

  Renderer renderer(kScreenWidth, kScreenHeight);

  Controller controller;
  Game game(renderer);

  game.Run(controller, kMsPerFrame);
  std::cout << "Game has terminated successfully\n";
  std::cout << "Score: " << game.GetScore() << std::endl;
  return 0;
}
