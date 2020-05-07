#pragma once

#include "Spritesheet.h"
#include "SpritesheetManager.h"
#include <string>
#include <map>
#include "Animation.h"

namespace sdl {
  class AnimationManager {
    private:
      SpritesheetManager& spritesheetManager;

    public:
      AnimationManager(SpritesheetManager& spritesheetManager);
      ~AnimationManager();

      Animation getUpset();
      Animation getEating();
      Animation getSleep();
      Animation getSick();
      Animation getIdle();
  };
}