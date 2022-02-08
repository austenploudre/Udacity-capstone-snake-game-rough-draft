#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

namespace SDL {
  
class Controller {
 public:
  // Initialize pause state
  //Controller(): _pause(false){}
  //void HandleInput(bool &running, Snake &snake);
  void HandleInput(bool &running,
                   std::vector<std::shared_ptr<Capstone::Snake>> &snakes) const;
  
  //void ChangePauseState();
  //bool GetPauseState() const;

 private:
  // Manage pause state
  bool _pause;  
  //void ChangeDirection(Snake &snake, Snake::Direction input,
                       //Snake::Direction opposite) const;
  void ChangeDirection(std::shared_ptr<Capstone::Snake> snake,
                       Capstone::Snake::Direction input,
                       Capstone::Snake::Direction opposite) const;
};
}
#endif
