#include "snake.h"
#include <cmath>
#include <iostream>

//void Capstone::Snake::SetDifficulty() {
//Sets snake initial speed to 0.2,0.4 or 0.6
void Capstone::Snake::SetDifficulty()
{
  float userSpeed;
  char rangeBuffer[25];
  char userAnswer[25];
  
  sprintf(rangeBuffer, "%0.1f and %0.1f", minStartSpeed, maxStartSpeed);
  std::string rangeStr(rangeBuffer);

  std::cout << "-----------------------" << std::endl;
  std::cout << "Select a difficulty " << rangeStr << std::endl;
  std::cout << "1.Easy , 2.Medium , 3.Hard" << std::endl;

while (true)
  {
    int input = scanf("%f", &userSpeed);
    switch (input)
    {
      case 1: 
      {
        if(userSpeed == 1.0)
        {  
          speed = 0.2;
          std::cout << "Snake speed set to 0.2" << std::endl;
          return;
        }
      }  
      
      case 2: 
      {
        if(userSpeed == 2.0)
        {  
          speed = 0.2;
          std::cout << "Snake speed set to 0.4" << std::endl;
          return;
        }
      }
      
      case 3: 
      {
        if(userSpeed == 3.0)
        {  
          speed = 0.2;
          std::cout << "Snake speed set to 0.6" << std::endl;
          return;
        }
      }
    
   }
    
    std::cerr << "\n\n\nOoops!! Please provide a valid decimal between " << rangeStr << std::endl;
    break;
   
  };
}
  
void Capstone::Snake::Update() {
  SDL_Point prev_cell{
      static_cast<int>(head_x),
      static_cast<int>(
          head_y)};  // We first capture the head's cell before updating.
  UpdateHead();
  SDL_Point current_cell{
      static_cast<int>(head_x),
      static_cast<int>(head_y)};  // Capture the head's cell after updating.

  // Update all of the body vector items if the snake head has moved to a new
  // cell.
  if (current_cell.x != prev_cell.x || current_cell.y != prev_cell.y) {
    UpdateBody(current_cell, prev_cell);
  }
}

void Capstone::Snake::UpdateHead() {
  switch (direction) {
    case Direction::kUp:
      head_y -= speed;
      break;

    case Direction::kDown:
      head_y += speed;
      break;

    case Direction::kLeft:
      head_x -= speed;
      break;

    case Direction::kRight:
      head_x += speed;
      break;
  }

  // Wrap the Snake around to the beginning if going off of the screen.
  head_x = fmod(head_x + grid_width, grid_width);
  head_y = fmod(head_y + grid_height, grid_height);
}

void Capstone::Snake::UpdateBody(SDL_Point &current_head_cell, SDL_Point &prev_head_cell) {
  // Add previous head location to vector
  body.push_back(prev_head_cell);

  if (!growing) {
    // Remove the tail from the vector.
    body.erase(body.begin());
  } else {
    growing = false;
    size++;
  }

  // Check if the snake has died.
  for (auto const &item : body) {
    if (current_head_cell.x == item.x && current_head_cell.y == item.y) {
      alive = false;
    }
  }
}

void Capstone::Snake::GrowBody() { growing = true; }

// Inefficient method to check if cell is occupied by snake.
bool Capstone::Snake::SnakeCell(int x, int y) {
  if (x == static_cast<int>(head_x) && y == static_cast<int>(head_y)) {
    return true;
  }
  for (auto const &item : body) {
    if (x == item.x && y == item.y) {
      return true;
    }
  }
  return false;
}

int Capstone::Snake::GetSnakeId() const { return snake_id_; }//-----------------