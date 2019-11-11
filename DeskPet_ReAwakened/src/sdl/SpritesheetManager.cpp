#pragma once

#include "Texture.h"
#include "SpritesheetManager.h"
#include "Spritesheet.h"

sdl::SpritesheetManager::SpritesheetManager(TextureManager& textureManager) {
  petTvCat = new Spritesheet(textureManager.getNightBackground());
  petTvCat->addSprite("chomp1", 0, 0, 30, 30);
  petTvCat->addSprite("chomp2", 30, 0, 30, 30);
}

sdl::SpritesheetManager::~SpritesheetManager() {
  delete petTvCat;
}

Spritesheet& sdl::SpritesheetManager::getPetTvCat() {
  return *petTvCat;
}
