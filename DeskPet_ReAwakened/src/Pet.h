#pragma once
#include <string>
#include "sdl/AnimationManager.h"

class Pet {
public:
  enum class PetState { EGG, BABY, CHILD, ADULT, RETIRED };

  Pet(sdl::AnimationManager& animationManager);
  void save();
  void render();
  void handleInput(SDL_Event e);
  void update(double deltaTime);

  void behaviour(double deltaTime);

private:
  // Pet Data
  PetState state; 
  std::string name;
  int age;
  int bond;

  // InGame Pet Data
  sdl::AnimationManager& animationManager;
  sdl::Animation currentAnimation;

  int x = 250;
  int y = 160;
  int dx = 0;
  int dy = 0;

  bool flip = false;
};
