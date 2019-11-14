#include "MainGame.h"
#include "sdl/Spritesheet.h"

#include "Game.h"

MainGame::MainGame() {
}

MainGame::~MainGame() {
}

void MainGame::handleInput(SDL_Event e) {
  pet->handleInput(e);
}

void MainGame::update() {
}

void MainGame::render() {
  textureManager->getDayBackground().render();
  pet->render();
  //pet->save();

  textureManager->getBorder().render();
}