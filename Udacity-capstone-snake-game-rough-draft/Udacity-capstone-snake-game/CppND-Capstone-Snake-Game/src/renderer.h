#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

namespace SDL {

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height);
  ~Renderer();

  //void Render(Snake const snake, SDL_Point const &food);
  void Render(const std::vector<std::shared_ptr<Capstone::Snake>> &snakes,
              const std::vector<SDL_Point> &foods,
              const std::vector<SDL_Point> &poisons);  
  //void UpdateWindowTitle(int score, int fps);
 void UpdateWindowTitle(int score_left, int score_right, int fps);
 
 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
};
}
#endif