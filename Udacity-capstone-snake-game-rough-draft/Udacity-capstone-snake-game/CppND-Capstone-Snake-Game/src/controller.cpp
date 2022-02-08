#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

//void Controller::ChangeDirection(Snake &snake, Snake::Direction input,
//                                 Snake::Direction opposite) const {
void SDL::Controller::ChangeDirection(std::shared_ptr<Capstone::Snake> snake,
                                      Capstone::Snake::Direction input,
                                      Capstone::Snake::Direction opposite) const {
//  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
//    return;
  if (snake->direction != opposite || snake->size == 1)
    snake->direction = input;
}

//void SDL::Controller::ChangePauseState() { _pause = !_pause; }

//bool SDL::Controller::GetPauseState() const { return _pause; }

//void Controller::HandleInput(bool &running, Snake &snake) {
void SDL::Controller::HandleInput(bool &running,
                                  std::vector<std::shared_ptr<Capstone::Snake>> &snakes) const {
  SDL_Event e;
  auto snake_left = snakes[0];//---------
  auto snake_right = snakes[1];//-------
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
          using namespace Capstone;
        case SDLK_UP:
          ChangeDirection(snake_right, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake_right, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake_right, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake_right, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
        
        case SDLK_w:
          ChangeDirection(snake_left, Snake::Direction::kUp,
                          Snake::Direction::kDown);
          break;

        case SDLK_s:
          ChangeDirection(snake_left, Snake::Direction::kDown,
                          Snake::Direction::kUp);
          break;

        case SDLK_a:
          ChangeDirection(snake_left, Snake::Direction::kLeft,
                          Snake::Direction::kRight);
          break;

        case SDLK_d:
          ChangeDirection(snake_left, Snake::Direction::kRight,
                          Snake::Direction::kLeft);
          break;
        
//        case SDLK_p:
//          ChangePauseState();
//          std::cout << "Game paused" << std::endl;
//          break;
                
//        case SDLK_q:
//          std::cout << "Game Quit" << std::endl;
//          running = false;
      }
    }
  }
}
