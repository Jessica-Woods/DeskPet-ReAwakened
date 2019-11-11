#include "MainGame.h"
#include "sdl/Spritesheet.h"

#include "Game.h"

MainGame::MainGame() {
}

MainGame::~MainGame() {
}

void MainGame::handleInput(SDL_Event e) {
}

void MainGame::update() {
}

void MainGame::render() {
  textureManager->getDayBackground().render();

  animationManager->getChomp().render(25, 80);
  textureManager->getBorder().render();
}
