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
      double durationMs;
    };

    Animation(Spritesheet& spritesheet);
    ~Animation();
    Animation(const Animation& other);
    Animation& operator=(const Animation& other);
    friend bool operator==(const Animation& lhs, const Animation& rhs);
    
    sdl::Animation& addFrame(std::string spriteName, double duration);

    void update(double delta);
    void render(int targetX, int targetY, bool flip);
 
  private:
    Spritesheet& spritesheet;
    std::vector<Frame> frames;

    double elapsedTime = 0.0;
    int currentFrame = 0;
  };
}