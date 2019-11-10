#include "MainGame.h"

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
  window->render(textureManager->getDayBackground());
  window->render(textureManager->getBorder());
  //game.getWindow().render(game.getDayBackground());
}
