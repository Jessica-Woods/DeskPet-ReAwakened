#pragma once

#include "Spritesheet.h"
#include "Animation.h"

sdl::Animation::Animation(Spritesheet& ss) : spritesheet(ss) {
}

sdl::Animation::~Animation() {
}

sdl::Animation& sdl::Animation::addFrame(std::string spriteName, float duration) {
  frames.push_back({spriteName, duration});
  return *this;
}

void sdl::Animation::update(float delta) {
}

void sdl::Animation::render(int targetX, int targetY) {
  auto source = frames.at(currentFrame).spriteName;
  spritesheet.render(source, targetX, targetY); 
}
