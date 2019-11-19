#include "HungerGame.h"
#include "sdl/Spritesheet.h"

#include "Game.h"
#include <vector>

HungerGame::HungerGame() {
}

HungerGame::~HungerGame() {
  delete feedButton;
  delete helpButton;

  for (auto apple : apples) {
    delete apple;
  }
}

void HungerGame::initialize() {
  feedButton = new Button(textureManager->getIconFeed(), 360, 10);
  feedButton->onClick([&]() { onFeedClicked(); });

  helpButton = new Button(textureManager->getIconHelp(), 410, 10);
  helpButton->onClick([&]() { onHelpClicked(); });

  for (int i = 0; i < 30; i++) {
    createApple();
  }
  
  pet->eating();
}

void HungerGame::handleInput(SDL_Event e) {
  feedButton->handleInput(e);
  helpButton->handleInput(e);
  appleHit(e);
}

void HungerGame::update(double deltaTime) {
  pet->update(deltaTime);
  spawnApples(deltaTime);
  applesMove(deltaTime);
  soundManager->playFoodGameSong();

  if (greenApplesHit >= 5) {
    soundManager->playGameOverSound();
    game->popState();
    pet->idle();
  }
}

void HungerGame::render() {
  textureManager->getDayBackground().render();
  pet->render();
  
  textureManager->getBorder().render();

  feedButton->render();
  helpButton->render();

  renderHungerBar();
  renderHealthBar();

  for (auto apple : apples) {
    apple->texture.render(apple->x, apple->y);
  }

  auto name = pet->getName();
  window->renderText(name, (238 - ( 5 * name.size())), 275);
}

void HungerGame::onFeedClicked() {
  game->popState();
  pet->idle();
}

void HungerGame::onHelpClicked() {
  // draw a help screen to the game
  std::cout << "You asked for help in food game" << std::endl;
}

void HungerGame::renderHealthBar() {
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
    y = 10 - (5 * (i % 2));

    if (health <= (i * 2)) {
      textureManager->getheartEmpty().render(x, y);
    } else if (health == (i * 2) + 1) {
      textureManager->getheartHalf().render(x, y);
    } else if (health >= (i * 2) + 2) {
      textureManager->getheartFull().render(x, y);
    }
  }
}

void HungerGame::renderHungerBar() {
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

void HungerGame::createApple() {
  auto a = static_cast<appleType>(std::rand() % 2);
  apple* apple = nullptr;
  if (a == appleType::redApple) {
    apple = new HungerGame::apple{ HungerGame::appleType::redApple, textureManager->getAppleRed(), 0, 0, 0 };
  } else {
    apple = new HungerGame::apple{ HungerGame::appleType::greenApple, textureManager->getAppleGreen(), 0, 0, 0 };
  }

  apple->x = (40 + (std::rand() % (300 - 80 - apple->texture.getWidth())));
  apple->y = (-100 - (std::rand() % 400));
  apple->dy = (1 + (std::rand() % 2));

  apples.push_back(apple);
}

void HungerGame::spawnApples(double deltaTimeMs) {
  appleTimerMs += deltaTimeMs;
  if (appleTimerMs > 5000.0) {
    appleTimerMs = 0;
    for (int i = 0; i < 30; ++i) {
      createApple();
    }
  }
}

void HungerGame::applesMove(double deltaTimeMs) {
  double timeMs = 1000.0;
  moveTimerMs += deltaTimeMs;
  if (moveTimerMs > timeMs){
    for (auto apple : apples) {
      if (apple->y < 400) {
        apple->y += apple->dy;
      }
    }
  }
}

void HungerGame::appleHit(SDL_Event e) {
  for (auto apple : apples){
    if (e.button.type == SDL_MOUSEBUTTONDOWN
      && e.button.button == SDL_BUTTON_LEFT
      && e.button.x > apple->x
      && e.button.x < apple->x + apple->texture.getWidth()
      && e.button.y > apple->y
      && e.button.y < apple->y + apple->texture.getHeight()) {
      
      apple->x = 500;
      apple->y = 500;

      if (apple->type == appleType::redApple) { 
        pet->addHunger(1); 
        soundManager->playRedAppleSound(); 
      } else if (apple->type == appleType::greenApple) { 
        pet->addHunger(-1); 
        soundManager->playGreenAppleSound();
        greenApplesHit += 1;
      }
    }
  }
}

