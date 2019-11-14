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

void MainGame::update(double deltaTime) {
  pet->update(deltaTime);
}

void MainGame::render() {
  textureManager->getDayBackground().render();
  pet->render();
  //pet->save();
  window->renderText("WWWW", 20, 20);
  window->renderText("llll", 20, 60);
  textureManager->getBorder().render();
}