#include "Texture.h"

#include <SDL.h>
#include <exception>
#include <string>

sdl::Texture::Texture(SDL_Texture* texture, int width, int height) {
  this->texture = texture;
  this->width = width;
  this->height = height;
}

sdl::Texture::~Texture() {
  if (texture != nullptr) {
    SDL_DestroyTexture(texture);
    texture = nullptr;
  }
}

void sdl::Texture::setColor(Uint8 red, Uint8 green, Uint8 blue) {
  SDL_SetTextureColorMod(texture, red, green, blue);
}

void sdl::Texture::setAlpha(Uint8 alpha) {
  SDL_SetTextureAlphaMod(texture, alpha);
}

SDL_Texture& sdl::Texture::getTexture() {
  return *texture;
}

int sdl::Texture::getWidth() {
  return width;
}

int sdl::Texture::getHeight() {
  return height;
}