#include "Pet.h"
#include "PetFile.h"
#include "sdl/AnimationManager.h"
#include <chrono>

Pet::Pet(sdl::AnimationManager& am) : animationManager(am), currentAnimation(animationManager.getIdle()){
  this->stage = Pet::Stage::EGG;
  this->name = "TVCat";
  this->age = 0;
  this->bond = 0;
  this->health = 0;
  this->hunger = 0;

  idle();

  // Try to load the pet
  PetFile* petFile = PetFile::tryLoad();
  if (petFile != nullptr) {
    this->stage = petFile->getStage();
    this->name = petFile->getName();
    this->age = petFile->getAge();
    this->bond = petFile->getBond();
    addHealth(petFile->getHealth());
    addHunger(petFile->getHunger());

    if (petFile->getSleeping()) {
      sleep();
    }

    // Simulate the time we missed while the game was offline
    auto timePassedMs = std::chrono::duration_cast<std::chrono::milliseconds>(
      std::chrono::system_clock::now() - petFile->getLastSaveTime()
    ).count();

    double offlineMultiplier = 1.00;
    double timeToSimulate = (double)timePassedMs * offlineMultiplier;
    double tickSize = 1000.0;
    while (timeToSimulate > 0.0) {
      timeToSimulate -= tickSize;
      updateHunger(tickSize);
      updateHealth(tickSize);
    }

    delete petFile;
  }
}

void Pet::update(double deltaTime) {
  updateAnimation(deltaTime);
  updateMovement(deltaTime);
  updateState(deltaTime);
  updateHunger(deltaTime);
  updateHealth(deltaTime);
}

void Pet::render() { currentAnimation.render(x, y, flip()); }

// Helper Functions
std::string Pet::getName() { return name; }
Pet::State Pet::getState() { return state; }
int Pet::getHealth() { return health; }
int Pet::getHunger() { return hunger; }
bool Pet::flip() { return dx > 0; }

void Pet::addHealth(int health) {
  this->health += health;
  if (this->health > 10) {
    this->health = 10;
  }

  if (this->health < 1) {
    this->health = 0;
  }
}

void Pet::addHunger(int hunger) {
  this->hunger += hunger;
  if (this->hunger > 5) {
    this->hunger = 5;
  }

  if (this->hunger < 1) {
    this->hunger = 0;
    addHealth(-1);
  }
}

void Pet::save() {
  PetFile file(
    stage, 
    name, 
    age, 
    bond, 
    health, 
    hunger, 
    state == Pet::State::SLEEP, 
    std::chrono::system_clock::now()
  );
  file.save();
}
void Pet::updateState(double deltaTime) {
  if (state != Pet::State::SLEEP && state != Pet::State::EATING){
    if (health == 0) {
      sick();
    } else if (health <= 3) {
      upset();
    } else {
      idle();
    }
  }
}

void Pet::updateHealth(double deltaTimeMs) {
  // 20 seconds
  double HealthtimeMs = 20000.0;
  if (state != Pet::State::SLEEP) {
    healthTimerMS += deltaTimeMs;

    if (healthTimerMS > HealthtimeMs) {
      healthTimerMS = healthTimerMS - HealthtimeMs;
      if (hunger <= 0 && state != Pet::State::EATING) {
        addHealth(-1);
      } else if (hunger > 0) {
        addHealth(1);
      }
    }
  }
}


void Pet::updateHunger(double deltaTimeMs) {
  // 20 seconds
  double HungertimeMS = 20000.0;
  if (state != Pet::State::SLEEP) {
    hungerTimerMS += deltaTimeMs;
    if (state != Pet::State::EATING && hungerTimerMS > HungertimeMS) {
      hungerTimerMS = hungerTimerMS - HungertimeMS;
      addHunger(-1);
    }
  }
}

// Pet States
void Pet::center() { x = 250; y = 170; dx = 0; dy = 0; }
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
    center();
  }
}
void Pet::sick() {
  if (state != Pet::State::SICK) {
    state = Pet::State::SICK;
    center();
  }
}
void Pet::upset() {
  if (state != Pet::State::UPSET){
    state = Pet::State::UPSET;
    center();
  }
}
void Pet::eating() {
  if (state != Pet::State::EATING) {
    state = Pet::State::EATING;
    center();
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
