#include "Spritesheet.h"
#include "Texture.h"

Spritesheet::Spritesheet(sdl::Texture& tex) : texture(tex) {
}

Spritesheet::Spritesheet(const Spritesheet& other) : texture(other.texture), sprites(other.sprites) {
}

Spritesheet& Spritesheet::operator=(const Spritesheet& other) {
  texture = other.texture;
  sprites = other.sprites;
  return *this;
}

bool Spritesheet::operator==(const Spritesheet& other) {
  return true;
  //return (texture == other.texture 
  //&& sprites == other.sprites);
}

void Spritesheet::addSprite(std::string name, int x, int y, int width, int height) {
  sprites[name] = SDL_Rect { x, y, width, height };
}

void Spritesheet::render(std::string name, int targetX, int targetY, bool flip) {
  auto source = sprites[name];
  texture.render(targetX, targetY, source, flip);
}