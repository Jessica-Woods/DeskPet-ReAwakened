#include "Pet.h"
#include "PetFile.h"
#include "sdl/AnimationManager.h"

Pet::Pet(sdl::AnimationManager& am) : animationManager(am), currentAnimation(animationManager.getIdle()){
  this->stage = Pet::Stage::EGG;
  this->name = "TVCat";
  this->age = 0;
  this->bond = 0;

  idle();

  // Try to load the pet
  PetFile* petFile = PetFile::tryLoad();
  if (petFile != nullptr) {
    this->stage = petFile->getStage();
    this->name = petFile->getName();
    this->age = petFile->getAge();
    this->bond = petFile->getBond();
    delete petFile;
  }
}

void Pet::update(double deltaTime) {
  updateAnimation(deltaTime);
  updateMovement(deltaTime);
  updateHealth(deltaTime);
}

void Pet::render() { currentAnimation.render(x, y, flip()); }


// Helper Functions
std::string Pet::getName() { return name; }

Pet::State Pet::getState() { return state; }

bool Pet::flip() { return dx > 0; }

void Pet::save() {
  PetFile file(stage, name, age, bond);
  file.save();
}
void Pet::updateHealth(double deltaTime) {
  if (state != Pet::State::SLEEP){
    if (health == 0) {
      sick();
    } else if (health <= 3) {
      upset();
    } else {
      idle();
    }

    // we need to decrease health over time
  }
}

// Pet States
void Pet::idle() {
  if (state != Pet::State::IDLE) {
    state = Pet::State::IDLE;
    x = 250; 
    y = 160; 
    dx = -10; 
    dy = -10;
  }
}

void Pet::sleep() {

  if (state != Pet::State::SLEEP) {
    state = Pet::State::SLEEP;
    x = 250;
    y = 170;
    dx = 0;
    dy = 0;
  }
}
void Pet::sick() {
  if (state != Pet::State::SICK) {
    state = Pet::State::SICK;
    x = 250;
    y = 170;
    dx = 0;
    dy = 0;
  }
}

void Pet::upset() {
  if (state != Pet::State::UPSET){
    state = Pet::State::UPSET;
    x = 250;
    y = 170;
    dx = 0;
    dy = 0;
  }
}

void Pet::eating() {
  if (state != Pet::State::EATING) {
    state = Pet::State::EATING;
    x = 250;
    y = 170;
    dx = 0;
    dy = 0;
  }
}

void Pet::incHealth(int health) {
  this->health += health;
  if (this->health > 5) {
    this->health = 5;
  }
}

// Updating logic
void Pet::updateMovement(double deltaTimeMs) {
  double timeMs = 500.0;
  if (state == Pet::State::IDLE) {
    moveTimerMs += deltaTimeMs;
    if (moveTimerMs > timeMs) {
      moveTimerMs = moveTimerMs - timeMs;
      if (x < 0 || x + 160 > 476) {
        dx = -dx;
      }
      dy = -dy;

      x += dx;
      y += dy;

      if (dy < 0) {
        currentAnimation.setCurrentFrame(0);
      } else {
        currentAnimation.setCurrentFrame(1);
      }
    }
  } else if (state == Pet::State::SLEEP) {
    // we don't move.
  }
}

void Pet::updateAnimation(double deltaTime) {
  if (state == Pet::State::IDLE && currentAnimation.getName() != animationManager.getIdle().getName()) {
    currentAnimation = animationManager.getIdle();
    currentAnimation.setPause(true);
  } else if (state == Pet::State::SLEEP && currentAnimation.getName() != animationManager.getSleep().getName()) {
    currentAnimation = animationManager.getSleep();
  } else if (state == Pet::State::SICK && currentAnimation.getName() != animationManager.getSick().getName()) {
    currentAnimation = animationManager.getSick();
  } else if (state == Pet::State::UPSET && currentAnimation.getName() != animationManager.getUpset().getName()) {
    currentAnimation = animationManager.getUpset();
  } else if (state == Pet::State::EATING && currentAnimation.getName() != animationManager.getEating().getName()) {
    currentAnimation = animationManager.getEating();
  }

  currentAnimation.update(deltaTime);
}
