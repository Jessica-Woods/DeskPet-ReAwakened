#include "MainGame.h"
#include "sdl/Spritesheet.h"

#include "Game.h"
#include "HungerGame.h"

MainGame::MainGame() {
}

MainGame::~MainGame() {
  delete feedButton;
  delete mediButton;
  delete sleepButton;
  delete helpButton;
}

void MainGame::initialize() {
  feedButton = new Button(textureManager->getIconFeed(), 260, 10);
  feedButton->onClick([&]() { onFeedClicked(); });

  mediButton = new Button(textureManager->getIconMedi(), 310, 10);
  mediButton->onClick([&]() { onMediClicked(); });

  sleepButton = new Button(textureManager->getIconSleep(), 360, 10);
  sleepButton->onClick([&]() { onSleepClicked(); });

  helpButton = new Button(textureManager->getIconHelp(), 410, 10);
  helpButton->onClick([&]() { onHelpClicked(); });
}

void MainGame::handleInput(SDL_Event e) {
  feedButton->handleInput(e);
  mediButton->handleInput(e);
  sleepButton->handleInput(e);
  helpButton->handleInput(e);

  if (e.type == SDL_KEYDOWN) {
    if (e.key.keysym.sym == SDLK_1) {}
    else if (e.key.keysym.sym == SDLK_2) {}
    else if (e.key.keysym.sym == SDLK_3) {}
    else if (e.key.keysym.sym == SDLK_4) {}
  }
}

void MainGame::update(double deltaTime) {
  pet->update(deltaTime);
  updateMusic();
}

void MainGame::render() {
  if (pet->getState() == Pet::State::SLEEP) {
    textureManager->getNightBackground().render();
  } else { textureManager->getDayBackground().render(); }

  pet->render();
  
  textureManager->getBorder().render();

  feedButton->render();
  mediButton->render();
  sleepButton->render();
  helpButton->render();

  renderHungerBar();
  renderHealthBar();

  auto name = pet->getName();
  window->renderText(name, (238 - ( 5 * name.size())), 275);
}

void MainGame::onFeedClicked() {
  if (pet->getState() != Pet::State::SICK) {
    game->pushState(new HungerGame);
  }
}

void MainGame::onMediClicked() {
  if (pet->getState() == Pet::State::SICK) {
    pet->addHealth(1);
  }
}

void MainGame::onSleepClicked() {
  if (pet->getState() != Pet::State::SLEEP){
    pet->sleep();
  } else { pet->idle(); }
}

void MainGame::onHelpClicked() {
  // draw a help screen to the game
  std::cout << "You asked for help" << std::endl;
}

void MainGame::renderHealthBar() {
  //  i |     0     |     1     |     2     |     3     |     4
  // ---+-----------+-----------+-----------+-----------+------------
  //  h | [0, 1, 2] | [2, 3, 4] | [4, 5, 6] | [6, 7, 8] | [8, 9, 10]
  //  x | 0 + 10    | 45 + 10   | 90 + 10   | 135 + 10  | 180 + 10 
  //  y | 10        | 5         | 10        | 5         | 10    

  // Start 10 away from border,
  // 45 units between hearts.
  int health = pet->getHealth();
  int x = 0;
  int y = 0;

  for (int i = 0; i < 5; i++){
    x = (i * 45) + 10;
    y = 10 - (5*(i % 2));

    if (health <= (i * 2)) {
      textureManager->getheartEmpty().render(x, y);
    } else if (health == (i * 2) + 1) {
      textureManager->getheartHalf().render(x, y);
    } else if (health >= (i * 2) + 2) {
      textureManager->getheartFull().render(x, y);
    }
  }
}

void MainGame::renderHungerBar() {
  int hunger = pet->getHunger();
  int x = 0;
  int y = 0;

  for (int i = 0; i < 5; i++) {
    x = (i * 30) + 10;
    y = 265;

    if (hunger <= i ) {
      textureManager->getHungerEmpty().render(x, y);
    } else if (hunger > i) {
      textureManager->getHungerFull().render(x, y);
    }
  }
}

void MainGame::updateMusic() {
  if (pet->getState() == Pet::State::IDLE) {
    soundManager->playIdleSong();
  } else if(pet->getState() == Pet::State::UPSET) {
    soundManager->playSadSong();
  } else if (pet->getState() == Pet::State::SLEEP) {
    soundManager->playSleepSong();
  } else if (pet->getState() == Pet::State::SICK) {
    soundManager->playSickSong();
  }
}