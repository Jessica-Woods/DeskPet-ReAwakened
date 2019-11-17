#pragma once

#include "Spritesheet.h"
#include "Animation.h"

sdl::Animation::Animation(std::string n, Spritesheet& ss) : name(n), spritesheet(ss) {
}

sdl::Animation::~Animation() {
}

sdl::Animation::Animation(const Animation& other) : 
  name(other.name),
  spritesheet(other.spritesheet),
  frames(other.frames),
  elapsedTime(other.elapsedTime),
  currentFrame(other.currentFrame),
  pause(other.pause) {
}

sdl::Animation& sdl::Animation::operator=(const Animation& other) {
  name = other.name;
  spritesheet = other.spritesheet;
  frames = other.frames;
  elapsedTime = other.elapsedTime;
  currentFrame = other.currentFrame;
  pause = other.pause;
  return *this;
}

sdl::Animation& sdl::Animation::addFrame(std::string spriteName, double durationSeconds) {
  frames.push_back({spriteName, durationSeconds * 1000});
  return *this;
}

bool sdl::Animation::getPause() {
  return pause;
}

void sdl::Animation::setPause(bool pause)
{
  this->pause = pause;
}

void sdl::Animation::setCurrentFrame(int index) {
  currentFrame = index;
}

std::string sdl::Animation::getName() {
  return name;
}

void sdl::Animation::update(double delta) {
  if(!pause) {
    elapsedTime += delta;
    if (elapsedTime > frames.at(currentFrame).durationMs) {
      elapsedTime = elapsedTime - frames.at(currentFrame).durationMs;
      ++currentFrame;

      if (currentFrame >= frames.size()) {
        currentFrame = 0;
      }
    }
  }
}

void sdl::Animation::render(int targetX, int targetY, bool flip) {
  auto source = frames.at(currentFrame).spriteName;
  spritesheet.render(source, targetX, targetY, flip); 
}