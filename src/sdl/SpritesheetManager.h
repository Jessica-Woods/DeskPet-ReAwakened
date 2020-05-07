#pragma once

#include "Spritesheet.h"
#include "TextureManager.h"

namespace sdl {
  class SpritesheetManager {
  private:
    Spritesheet* petTvCat; 

  public:
    SpritesheetManager(TextureManager& textureManager);
    ~SpritesheetManager();

    Spritesheet& getPetTvCat();
  };
}