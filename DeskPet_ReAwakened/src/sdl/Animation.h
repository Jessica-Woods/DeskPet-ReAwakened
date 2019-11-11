#pragma once

#include "Spritesheet.h"
#include "TextureManager.h"
#include <string>
#include <vector>
#include <SDL.h>

namespace sdl {
  class Animation {
  public:
    struct Frame {
      std::string spriteName;
      float duration;
    };

    Animation(Spritesheet& spritesheet);
    ~Animation();
    
    sdl::Animation& addFrame(std::string spriteName, float duration);

    void update(float delta);
    void render(int targetX, int targetY);
 
  private:
    Spritesheet& spritesheet;
    std::vector<Frame> frames;

    float elapsedTime = 0.0;
    int currentFrame = 0;
  };
}