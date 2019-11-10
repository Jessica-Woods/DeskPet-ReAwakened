#pragma once
#include <iostream>
#include <string>
#include <SDL.h>

#include "sdl/TextureManager.h"

class Game;

class GameState {
protected:
  Game* game = nullptr;
  sdl::Window* window = nullptr;
  sdl::TextureManager* textureManager = nullptr;
public:
  GameState(); 
  virtual ~GameState();

  void setGame(Game& game);
  void setWindow(sdl::Window& window);
  void setTextureManager(sdl::TextureManager& textureManager);

  virtual void handleInput(SDL_Event e) = 0;
  virtual void update() = 0;
  virtual void render() = 0;
};