#include "HelpMainGame.h"
#include "sdl/Spritesheet.h"

#include "Game.h"
#include <vector>

HelpMainGame::HelpMainGame() {
}

HelpMainGame::~HelpMainGame() {
  delete helpButton;
}

void HelpMainGame::initialize() {
  helpButton = new Button(textureManager->getIconHelpBack(), 410, 10);
  helpButton->onClick([&]() { onHelpClicked(); });
}

void HelpMainGame::handleInput(SDL_Event e) {
  helpButton->handleInput(e);
}

void HelpMainGame::update(double deltaTime) {
  soundManager->playSleepSong();
}

void HelpMainGame::render() {
  textureManager->getHelpScreenMain().render();
  textureManager->getBorder().render();
  helpButton->render();
}

void HelpMainGame::onHelpClicked() {
  game->popState();
}