#pragma once
#include <SDL.h>
#include <functional>
#include <vector>
#include "sdl/Texture.h"

class Button {
private:
  sdl::Texture& texture;
  int x;
  int y;

  std::vector<std::function<void ()>> callbacks;

public:
  Button(sdl::Texture& texture, int x, int y);
  void onClick(std::function<void ()> callback);

  void handleInput(SDL_Event e);
  void render();
};
