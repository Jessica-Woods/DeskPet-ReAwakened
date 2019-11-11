#pragma once

#include "Spritesheet.h"
#include "AnimationManager.h"
#include "Animation.h"

sdl::AnimationManager::AnimationManager(SpritesheetManager& ssm) : spritesheetManager(ssm) {
}

sdl::AnimationManager::~AnimationManager() {
}

sdl::Animation sdl::AnimationManager::getChomp() {
  return Animation(spritesheetManager.getPetTvCat())
    .addFrame("chomp1", 0.2)
    .addFrame("chomp2", 0.3);
}

sdl::Animation sdl::AnimationManager::getSleep() {
  return getChomp();
}

sdl::Animation sdl::AnimationManager::getIdle() {
  return getChomp();
}
