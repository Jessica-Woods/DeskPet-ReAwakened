#pragma once

#include "Texture.h"
#include "SpritesheetManager.h"
#include "Spritesheet.h"

sdl::SpritesheetManager::SpritesheetManager(TextureManager& textureManager) {
  petTvCat = new Spritesheet(textureManager.getPetTvCat());
  int clipHeight = 100;
  int clipWidth = 160;

  petTvCat->addSprite("upset1",  0 * clipWidth, 0 * clipHeight, clipWidth, clipHeight);
  petTvCat->addSprite("upset2",  1 * clipWidth, 0 * clipHeight, clipWidth, clipHeight);

  petTvCat->addSprite("eating1", 0 * clipWidth, 1 * clipHeight, clipWidth, clipHeight);
  petTvCat->addSprite("eating2", 1 * clipWidth, 1 * clipHeight, clipWidth, clipHeight);

  petTvCat->addSprite("sleep1",  0 * clipWidth, 2 * clipHeight, clipWidth, clipHeight);
  petTvCat->addSprite("sleep2",  1 * clipWidth, 2 * clipHeight, clipWidth, clipHeight);

  petTvCat->addSprite("sick1",   0 * clipWidth, 3 * clipHeight, clipWidth, clipHeight);
  petTvCat->addSprite("sick2",   1 * clipWidth, 3 * clipHeight, clipWidth, clipHeight);

  petTvCat->addSprite("idle1",   0 * clipWidth, 4 * clipHeight, clipWidth, clipHeight);
  petTvCat->addSprite("idle2",   1 * clipWidth, 4 * clipHeight, clipWidth, clipHeight);
}

sdl::SpritesheetManager::~SpritesheetManager() {
  delete petTvCat;
}

Spritesheet& sdl::SpritesheetManager::getPetTvCat() {
  return *petTvCat;
}
