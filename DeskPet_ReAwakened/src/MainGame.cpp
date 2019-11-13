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

  animationManager->getUpset().render(0, 0);
  animationManager->getEating().render(0, 100);
  animationManager->getSleep().render(0, 200);
  animationManager->getSick().render(160, 0);
  animationManager->getIdle().render(160, 100);
  pet->save();

  //textureManager->getBorder().render();
}