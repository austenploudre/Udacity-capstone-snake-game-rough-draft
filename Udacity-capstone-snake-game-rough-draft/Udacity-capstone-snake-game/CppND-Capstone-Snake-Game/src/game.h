#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"
#include <string>
#include <vector>
#include <memory>

class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height);
  
//  void Run(Controller &controller, Renderer &renderer,
//           std::size_t target_frame_duration);
  void Run(SDL::Controller const &controller, SDL::Renderer &renderer,
           std::size_t target_frame_duration);
 
  std::string GetPlayerName();
  //int GetScore() const;
  //int GetSize() const;
  void SetPlayerName();
  void UpdateDifficulty();

  
  int GetLeftScore() const;
  
  int GetLeftSize() const;
  
  int GetRightScore() const;
  
  int GetRightSize() const;  
  
  bool GetLeftStatus() const;
  
  bool GetRightStatus() const;

 private:
//  Snake snake;
//  SDL_Point food;
//  std::string player_name;
  
  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;
  
  int score{0};
  void PlaceFood(SDL_Point &food);
  void PlacePoison(SDL_Point &poison);
  //void Update(const Controller &controller);
  void Update();
  void PoisonTimer();
  
  std::vector<std::shared_ptr<Capstone::Snake>> snakes_;
  std::vector<SDL_Point> foods;
  const int food_size = 5;
  std::vector<SDL_Point> poisons;
  const int poison_size = 3;  
  
  int score_left{0};
  int score_right{0};

  bool left_alive = true;
  bool right_alive = true;
  

};

#endif
