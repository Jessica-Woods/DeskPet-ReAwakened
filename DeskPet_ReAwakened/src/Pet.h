#pragma once
#include <string>
#include "sdl/AnimationManager.h"

class Pet {
public:
  enum class PetState { EGG, BABY, CHILD, ADULT, RETIRED };

  Pet(sdl::AnimationManager& currentAnimation);
  void save();
  void render() {
    if (animationState == "upset") { currentAnimation.getUpset().render(xPos, yPos, flip); }
    else if (animationState == "eating") { currentAnimation.getEating().render(xPos, yPos, flip); }
    else if (animationState == "sleep") { currentAnimation.getSleep().render(xPos, yPos, flip); }
    else if (animationState == "sick") { currentAnimation.getSick().render(xPos, yPos, flip); }
    else if (animationState == "idle") { currentAnimation.getIdle().render(xPos, yPos, flip); }
    else { throw std::exception("Error: missing animation"); }
  }
  void handleInput(SDL_Event e);

private:
  // Pet Data
  PetState state; 
  std::string name;
  int age;
  int bond;

  // InGame Pet Data
  sdl::AnimationManager& currentAnimation;
  std::string animationState = "idle";
  int xPos = 0;
  int yPos = 0;
  bool flip = false;
};
