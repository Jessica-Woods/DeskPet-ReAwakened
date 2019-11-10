#pragma once
#include <SDL.h>
#include <SDL_Image.h>
#include <string>
#include <vector>
#include <map>

#include "Window.h"

namespace sdl {
  class Texture {
  private:
    SDL_Texture* texture;
    int width;
    int height;
  public:
    Texture(SDL_Texture* texture, int width, int height);
    ~Texture();

    void setColor(Uint8 red, Uint8 green, Uint8 blue);

    void setAlpha(Uint8 alpha);

    SDL_Texture& getTexture();
    int getWidth();
    int getHeight();
  };
}