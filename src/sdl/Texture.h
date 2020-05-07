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
    sdl::Window& window;
    SDL_Texture* texture;
    int width;
    int height;
  public:
    Texture(sdl::Window& window, SDL_Texture* texture, int width, int height);
    Texture(const Texture& other);
    ~Texture();
    Texture& operator=(const Texture& other);

    void render();
    void render(int x, int y);
    void render(int x, int y, SDL_Rect clip);
    void render(int x, int y, SDL_Rect source, bool flip);

    void setColor(Uint8 red, Uint8 green, Uint8 blue);
    void setAlpha(Uint8 alpha);

    SDL_Texture& getTexture();
    int getWidth();
    int getHeight();
  };
}