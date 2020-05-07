#pragma once

#include <stack>
#include <vector>
#include <functional>

#include "sdl/Window.h"
#include "sdl/SoundManager.h"
#include "sdl/Texture.h"
#include "sdl/TextureManager.h"
#include "sdl/SpritesheetManager.h"
#include "sdl/AnimationManager.h"

#include "Pet.h"

class GameState;

class Game {
private:
  std::stack<GameState*> states;
  Uint64 currentTime = SDL_GetPerformanceCounter();
  Uint64 previousTime = 0;
  double deltaTimeAccumMs = 0.0;

  std::vector<std::function<void ()>> postLoopTriggers;

protected:
  sdl::Window window;
  sdl::SoundManager soundManager;
  sdl::TextureManager textureManager;
  sdl::SpritesheetManager spritesheetManager;
  sdl::AnimationManager animationManager;
  Pet pet;

public:
  Game();

  GameState* currentState();

  void pushState(GameState* state);
  void popState();
  void clearStates();

  bool isRunning();
  void handleInput();
  void update();
  void render();
  void runPostLoopTriggers();
  void save();
};