#include "includes.hpp"

int main() {
  const char *winName{"Ray Bird"};
  const unsigned short winSize[2]{288, 512};

  ray::InitWindow(winSize[0], winSize[1], winName);

  ray::SetTargetFPS(60);

  // game objects
  Entity bird("../media/sprites/bird-upflap.png", 100.f, 100.f);
  Entity background("../media/sprites/background-day.png", 0.f, 0.f);

  while (!ray::WindowShouldClose()) {
    ray::BeginDrawing();

    ray::ClearBackground(ray::RAYWHITE);

    background.draw();

    bird.draw();
    bird.sety(bird.gety() + 5);

    if (bird.gety() > winSize[1]) {
      bird.sety(-24);
    }

    ray::EndDrawing();
  }

  ray::CloseWindow();

  return 0;
}
