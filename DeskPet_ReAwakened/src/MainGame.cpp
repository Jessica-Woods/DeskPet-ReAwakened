#include "MainGame.h"
#include "sdl/Spritesheet.h"

#include "Game.h"

MainGame::MainGame() {
}

MainGame::~MainGame() {
  delete feedButton;
  delete mediButton;
  delete sleepButton;
}

void MainGame::initialize() {
  feedButton = new Button(textureManager->getIconFeed(), 300, 20);
  feedButton->onClick([&]() { onFeedClicked(); });

  mediButton = new Button(textureManager->getIconMedi(), 350, 20);
  mediButton->onClick([&]() { onMediClicked(); });

  sleepButton = new Button(textureManager->getIconSleep(), 400, 20);
  sleepButton->onClick([&]() { onSleepClicked(); });
}

void MainGame::handleInput(SDL_Event e) {
  feedButton->handleInput(e);
  mediButton->handleInput(e);
  sleepButton->handleInput(e);

  if (e.type == SDL_KEYDOWN) {
    if (e.key.keysym.sym == SDLK_1) {
      if (pet->getState() == Pet::State::IDLE) { pet->sleep(); }
      else { pet->idle(); }
    }
    else if (e.key.keysym.sym == SDLK_2) {}
    else if (e.key.keysym.sym == SDLK_3) {}
    else if (e.key.keysym.sym == SDLK_4) {}
  }
}

void MainGame::update(double deltaTime) {
  pet->update(deltaTime);
}

void MainGame::render() {
  textureManager->getDayBackground().render();
  pet->render();
  
  textureManager->getBorder().render();

  feedButton->render();
  mediButton->render();
  sleepButton->render();

  auto name = pet->getName();
  window->renderText(name, (238 - ( 5 * name.size())), 275);
}

void MainGame::onFeedClicked() {
  //pet->incHealth(1);
  pet->save();
}

void MainGame::onMediClicked() {
  if (pet->getState() == Pet::State::SICK) {
    pet->incHealth(3);
  }
}

void MainGame::onSleepClicked() {
  if (pet->getState() != Pet::State::SLEEP){
    pet->sleep();
  } else { pet->idle(); }
}