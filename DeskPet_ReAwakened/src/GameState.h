#pragma once
#include <iostream>
#include <string>
#include <SDL.h>

#include "sdl/TextureManager.h"
#include "sdl/SpritesheetManager.h"
#include "sdl/AnimationManager.h"

#include "Pet.h"

class Game;

class GameState {
protected:
  Game* game = nullptr;
  sdl::Window* window = nullptr;
  sdl::TextureManager* textureManager = nullptr;
  sdl::SpritesheetManager* spritesheetManager = nullptr;
  sdl::AnimationManager* animationManager = nullptr;
  Pet* pet = nullptr;

public:
  GameState(); 
  virtual ~GameState();

  void setGame(Game& game);
  void setWindow(sdl::Window& window);
  void setTextureManager(sdl::TextureManager& textureManager);
  void setSpritesheetManager(sdl::SpritesheetManager& spritesheetManager);
  void setAnimationManager(sdl::AnimationManager& animationManager);
  void setPet(Pet& pet);

  virtual void initialize() = 0;
  virtual void handleInput(SDL_Event e) = 0;
  virtual void update(double deltaTime) = 0;
  virtual void render() = 0;
};