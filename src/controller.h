#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

class Controller {
 public:
  Controller() = default;
  int HandleInput(bool& running);
};

#endif  // __CONTROLLER_H__
