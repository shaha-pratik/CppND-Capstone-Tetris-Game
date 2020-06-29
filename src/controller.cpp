#include "controller.h"

#include <SDL2/SDL.h>

int Controller::HandleInput(bool &running) {
  SDL_Event event;
  int value{-1};
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
      case SDL_KEYDOWN:
        value = event.key.keysym.sym;
        break;
      case SDL_WINDOWEVENT_CLOSE:
        exit(3);
        break;
      case SDL_QUIT:
        running = false;
        break;
    }
  }
  return value;
}
