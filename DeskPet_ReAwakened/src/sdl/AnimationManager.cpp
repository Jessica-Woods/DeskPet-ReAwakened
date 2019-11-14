#pragma once

#include "Spritesheet.h"
#include "AnimationManager.h"
#include "Animation.h"

sdl::AnimationManager::AnimationManager(SpritesheetManager& ssm) : spritesheetManager(ssm) {
}

sdl::AnimationManager::~AnimationManager() {
}

sdl::Animation sdl::AnimationManager::getUpset() {
  return Animation(spritesheetManager.getPetTvCat())
    .addFrame("upset1", 0.20)
    .addFrame("upset2", 0.20);
}

sdl::Animation sdl::AnimationManager::getEating() {
  return Animation(spritesheetManager.getPetTvCat())
    .addFrame("eating1", 0.20)
    .addFrame("eating2", 0.20);
}

sdl::Animation sdl::AnimationManager::getSleep() {
  return Animation(spritesheetManager.getPetTvCat())
    .addFrame("sleep1", 0.20)
    .addFrame("sleep2", 0.20);
}

sdl::Animation sdl::AnimationManager::getSick() {
  return Animation(spritesheetManager.getPetTvCat())
    .addFrame("sick1", 0.20)
    .addFrame("sick2", 0.20);
}

sdl::Animation sdl::AnimationManager::getIdle() {
  return Animation(spritesheetManager.getPetTvCat())
    .addFrame("idle1", 0.20)
    .addFrame("idle2", 0.20);
}
