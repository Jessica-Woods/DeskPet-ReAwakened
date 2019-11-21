#include "HelpHungerGame.h"
#include "sdl/Spritesheet.h"

#include "Game.h"
#include <vector>

HelpHungerGame::HelpHungerGame() {
}

HelpHungerGame::~HelpHungerGame() {
  delete helpButton;
}

void HelpHungerGame::initialize() {
  helpButton = new Button(textureManager->getIconHelpBack(), 410, 10);
  helpButton->onClick([&]() { onHelpClicked(); });
}

void HelpHungerGame::handleInput(SDL_Event e) {
  helpButton->handleInput(e);
}

void HelpHungerGame::update(double deltaTime) {
  soundManager->playSleepSong();
}

void HelpHungerGame::render() {
  textureManager->getHelpScreenGame().render();
  textureManager->getBorder().render();
  helpButton->render();
}

void HelpHungerGame::onHelpClicked() {
  game->popState();
}