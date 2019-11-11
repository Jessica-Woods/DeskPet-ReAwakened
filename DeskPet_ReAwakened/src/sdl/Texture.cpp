#include "Texture.h"

#include <SDL.h>
#include <exception>
#include <string>

sdl::Texture::Texture(sdl::Window& win, SDL_Texture* texture, int width, int height) : window(win) {
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

void sdl::Texture::render() {
  window.renderCopy(*texture, nullptr, nullptr);
}

void sdl::Texture::render(int x, int y) {
  SDL_Rect target = { x, y, width, height };
  window.renderCopy(*texture, nullptr, &target);
}

void sdl::Texture::render(int x, int y, SDL_Rect source) {
  SDL_Rect target = { x, y, width, height };

  target.w = source.w;
  target.h = source.h;
  
  window.renderCopy(*texture, &source, &target);
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