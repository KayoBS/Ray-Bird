#pragma once

#include "objects/entity.hpp"
namespace ray {
#include <raylib.h>
}

class Window {
private:
  void updatePhysics();

  unsigned short screenHeight;
  unsigned short screenWidth;

  float deltaTime; // Esse deltaTime é arbitrário

public:
  Window();

  Entity bird;
  Entity background;

  void init(), update(), draw(), keys();
};
