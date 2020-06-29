#include "renderer.h"

Renderer::Renderer(const std::size_t screen_width,
                   const std::size_t screen_height)
    : screen_width_(screen_width), screen_height_(screen_height) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL could not initialize.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  sdl_window_ = SDL_CreateWindow("Tetris Game", SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED, screen_width_,
                                 screen_height_, SDL_WINDOW_OPENGL);

  if (nullptr == sdl_window_) {
    std::cerr << "Window could not be created.\n";
    std::cerr << " SDL_Error: " << SDL_GetError() << "\n";
  }

  sdl_renderer_ = SDL_CreateRenderer(
      sdl_window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (nullptr == sdl_renderer_) {
    std::cerr << "Renderer could not be created.\n";
    std::cerr << "SDL_Error: " << SDL_GetError() << "\n";
  }

  UpdateScreen();
}

Renderer::~Renderer() {
  SDL_DestroyRenderer(sdl_renderer_);
  SDL_DestroyWindow(sdl_window_);
  SDL_Quit();
}

void Renderer::UpdateScreen() { SDL_RenderPresent(sdl_renderer_); }

void Renderer::DrawBlock(int pos_x, int pos_y, int w, int h) {
  SDL_Rect rect{pos_x, pos_y, w, h};

  SDL_SetRenderDrawColor(sdl_renderer_, 255, 255, 255, 255);
  SDL_RenderFillRect(sdl_renderer_, &rect);
}

void Renderer::ClearScreen() {
  SDL_SetRenderDrawColor(sdl_renderer_, 0, 0, 0, 0);
  SDL_RenderClear(sdl_renderer_);
}

int Renderer::MessageBox() {
  const SDL_MessageBoxButtonData buttons[] = {
      {0, 0, "NO"}, {SDL_MESSAGEBOX_BUTTON_RETURNKEY_DEFAULT, 1, "YES"},
  };

  const SDL_MessageBoxColorScheme colorScheme = {
      {{0, 0, 0}, {0, 0, 255}, {255, 255, 0}, {205, 205, 205}, {255, 0, 255}}};
  const SDL_MessageBoxData messageboxdata = {SDL_MESSAGEBOX_INFORMATION,
                                             NULL,
                                             "GAME OVER!",
                                             "Would you like to play again?",
                                             SDL_arraysize(buttons),
                                             buttons,
                                             &colorScheme};

  int buttonid;
  if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
    SDL_Log("error displaying message box");
    return 1;
  }
  if (buttonid == -1) {
    SDL_Log("no selection");
  } else {
    return buttonid;
  }
  return 0;
}
