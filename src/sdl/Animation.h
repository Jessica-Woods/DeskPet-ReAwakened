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

    Animation(std::string name, Spritesheet& spritesheet);
    ~Animation();
    Animation(const Animation& other);
    Animation& operator=(const Animation& other);
    
    sdl::Animation& addFrame(std::string spriteName, double duration);
    bool getPause();
    void setPause(bool pause);
    void setCurrentFrame(int index);
    std::string getName();

    void update(double delta);
    void render(int targetX, int targetY, bool flip);
 
  private:
    std::string name;
    Spritesheet& spritesheet;
    std::vector<Frame> frames;

    bool pause = false;
    double elapsedTime = 0.0;
    int currentFrame = 0;
  };
}