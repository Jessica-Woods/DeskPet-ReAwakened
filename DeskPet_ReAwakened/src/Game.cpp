#include "Game.h"
#include "GameState.h"

Game::Game() : 
  window("DeskPet ReAwakened", 477, 300), 
  textureManager(window),
  soundManager(),
  spritesheetManager(textureManager),
  animationManager(spritesheetManager),
  pet(animationManager) {
}

GameState* Game::currentState() {
  if (!states.empty()) {
    return states.top();
  } else {
    return nullptr;
  }
}

void Game::pushState(GameState* state) {
  state->setGame(*this);
  state->setWindow(window);
  state->setSoundManager(soundManager);
  state->setTextureManager(textureManager);
  state->setSpritesheetManager(spritesheetManager);
  state->setAnimationManager(animationManager);
  state->setPet(pet);
  state->initialize();
  states.push(state);
}

void Game::popState() {
  postLoopTriggers.push_back([&]() {
    delete states.top();
    states.pop();
  });
}

void Game::clearStates() {
  postLoopTriggers.push_back([&]() {
    while (!states.empty()) {
      popState();
    }
  });
}

bool Game::isRunning() {
  return window.isOpen() && currentState() != nullptr;
}

void Game::handleInput() {
  if(currentState() != nullptr) { 
    SDL_Event e;
    while (window.pollEvent(e)) {
      currentState()->handleInput(e);
    }
  }
}

void Game::update() {
  if (currentState() != nullptr) {
    previousTime = currentTime;
    currentTime = SDL_GetPerformanceCounter();
    double deltaTimeMs = (double)((currentTime - previousTime)*1000 / (double)SDL_GetPerformanceFrequency());

    // TO-DO semi fixed timestep test with more animation
    deltaTimeAccumMs += deltaTimeMs;
    while (deltaTimeAccumMs > 8.0) {
      deltaTimeAccumMs -= 8.0;
      currentState()->update(8.0);
    }
  }
}

void Game::render() {
  if(currentState() != nullptr) { 
    window.renderClear();
    currentState()->render(); 
    window.renderPresent();
  }
}

void Game::runPostLoopTriggers() {
  for (auto trigger : postLoopTriggers) {
    trigger();
  }
  postLoopTriggers.clear();
}
