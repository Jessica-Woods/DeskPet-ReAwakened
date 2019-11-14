#pragma once

#include "Spritesheet.h"
#include "Animation.h"

sdl::Animation::Animation(Spritesheet& ss) : spritesheet(ss) {
}

sdl::Animation::~Animation() {
}

sdl::Animation::Animation(const Animation& other) : 
  spritesheet(other.spritesheet),
  frames(other.frames),
  elapsedTime(other.elapsedTime),
  currentFrame(other.currentFrame) {
}

sdl::Animation& sdl::Animation::operator=(const Animation& other) {
  spritesheet = other.spritesheet;
  frames = other.frames;
  elapsedTime = other.elapsedTime;
  currentFrame = other.currentFrame;
  return *this;
}

sdl::Animation& sdl::Animation::addFrame(std::string spriteName, double durationSeconds) {
  frames.push_back({spriteName, durationSeconds * 1000});
  return *this;
}

void sdl::Animation::update(double delta) {
  elapsedTime += delta;
  if (elapsedTime > frames.at(currentFrame).durationMs) {
    ++currentFrame;
    elapsedTime = 0;

    if (currentFrame >= frames.size()) {
      currentFrame = 0;
    }
  }
}

void sdl::Animation::render(int targetX, int targetY, bool flip) {
  auto source = frames.at(currentFrame).spriteName;
  spritesheet.render(source, targetX, targetY, flip); 
}
