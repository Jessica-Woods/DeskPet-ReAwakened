#pragma once
#include <string>
#include "sdl/AnimationManager.h"

class Pet {
public:
  enum class Stage { EGG, BABY, CHILD, ADULT, RETIRED };
  enum class State { IDLE, SLEEP, SICK, EATING, UPSET };

  Pet(sdl::AnimationManager& animationManager);
  void save();
  void update(double deltaTime);
  void render();

  void idle();
  void sleep();
  void sick();
  void upset();
  void eating();

  void incHealth(int health);

  std::string getName();
  State getState();

private:
  // Pet Data
  Stage stage; 
  std::string name;
  int age;
  int bond;

  // InGame Pet Data
  sdl::AnimationManager& animationManager;
  sdl::Animation currentAnimation;
  State state;

  int x = 250;
  int y = 165;
  int dx = -10;
  int dy = 10;
  double moveTimerMs = 0.0;

  int health = 0;
  bool toggle = false;
  bool flip();

  void updateMovement(double deltaTime);
  void updateAnimation(double deltaTime);
  void updateHealth(double deltaTime);
};
