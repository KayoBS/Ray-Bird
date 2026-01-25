#include "includes.hpp"

float deltaTime = 0;

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
    bird.sety(bird.gety() + (5 * deltaTime));

    if (ray::IsKeyPressed(ray::KEY_SPACE)) {
      bird.sety(bird.gety() - 60);
      deltaTime = 0;
    }

    deltaTime += 0.03f;

    if (bird.gety() > winSize[1]) {
      bird.sety(-24);
    } else if (bird.gety() < 0) {
      bird.sety(8); // sumir com esse número mágico, fazer método para pegar o
                    // tamanho do sprite
    }

    ray::EndDrawing();
  }

  ray::CloseWindow();

  return 0;
}
