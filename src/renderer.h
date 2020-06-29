#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <cstddef>
#include <iostream>

#include <SDL2/SDL.h>

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height);
  ~Renderer();
  void DrawBlock(int pos_x, int pos_y, int w, int h);
  void ClearScreen();
  void UpdateScreen();
  int MessageBox();

 private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;
  const std::size_t screen_width_{};
  const std::size_t screen_height_{};
};

#endif  // __RENDERER_H__