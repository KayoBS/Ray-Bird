#include "Window.hpp"

Window::Window() : screenHeight(512), screenWidth(288), deltaTime(0) {
  ray::InitWindow(screenWidth, screenHeight, "Ray Bird");
  ray::SetTargetFPS(60);
}

void Window::init() {
  bird.setSprite("media/sprites/bird-upflap.png");
  bird.setx(100.f);
  bird.sety(100.f);

  background.setSprite("media/sprites/background-day.png");
  background.setx(0.f);
  background.sety(0.f);
}

void Window::update() {
  while (!ray::WindowShouldClose()) {
    ray::BeginDrawing();
    keys();
    updatePhysics();
    draw();
    ray::EndDrawing();
  }

  ray::CloseAudioDevice();
  ray::CloseWindow();
}

void Window::draw() {
  ray::ClearBackground(ray::WHITE);
  background.draw();
  bird.draw();
}

void Window::updatePhysics() {
  bird.sety(bird.gety() + (5 * deltaTime));
  deltaTime += 0.03f;

  // Para o pássaro não sumir do jogo, isso deverá ser substituido por uma
  // mecânica de morte
  if (bird.gety() > screenHeight) {
    bird.sety(-24);
  } else if (bird.gety() < 0) {
    bird.sety(8); // sumir com esse número mágico, fazer método para pegar o
                  // tamanho do sprite
  }
}

void Window::keys() {
  if (ray::IsKeyPressed(ray::KEY_SPACE)) {
    bird.sety(bird.gety() - 60);
    deltaTime = 0;
  }
}
