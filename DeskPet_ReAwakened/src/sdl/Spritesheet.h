#pragma once

#include "Texture.h"
#include <SDL.h>
#include <string>

class Spritesheet {
private:
  sdl::Texture& texture;
  std::map<std::string, SDL_Rect> sprites;

public:
  Spritesheet(sdl::Texture& texture);
  void addSprite(std::string name, int x, int y, int width, int height);
  void render(std::string name, int targetX, int targetY);
};