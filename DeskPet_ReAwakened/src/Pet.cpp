#include "Pet.h"
#include "PetFile.h"
#include "sdl/AnimationManager.h"

Pet::Pet(sdl::AnimationManager& am) : animationManager(am), currentAnimation(animationManager.getIdle()){
  this->state = Pet::PetState::EGG;
  this->name = "TV Cat";
  this->age = 0;
  this->bond = 0;

  // Try to load the pet
  PetFile* petFile = PetFile::tryLoad();
  if (petFile != nullptr) {
    this->state = petFile->getState();
    this->name = petFile->getName();
    this->age = petFile->getAge();
    this->bond = petFile->getBond();
    delete petFile;
  }
}

void Pet::save() {
  PetFile file(state, name, age, bond);
  file.save();
}

void Pet::render() {
  currentAnimation.render(x, y, flip);
}

void Pet::behaviour(double deltaTime) {
  double timer = 8.00;
  double elapsedTime = 0.0;
  elapsedTime += deltaTime;

  if (currentAnimation == animationManager.getIdle()){
    if (elapsedTime > timer && flip == false) {
      elapsedTime = 0.0;
      x -= 20;
      if (x <= 0) {
        flip = true;
      } 
    }

    if (elapsedTime > timer && flip == true) {
      elapsedTime = 0.0;
      x += 20;
      if (x >= 350) {
        flip = false;
      }
    }
  }
  else if (currentAnimation == animationManager.getSleep()) {
    dx, dy = 0;
    x, y = 200;
  }
}

void Pet::update(double deltaTime) {
  currentAnimation.update(deltaTime);
  behaviour(deltaTime);
}

void Pet::handleInput(SDL_Event e) {
  if (e.type == SDL_KEYDOWN) {
    if (e.key.keysym.sym == SDLK_UP) { y -= 15; currentAnimation = animationManager.getSleep(); }
    else if (e.key.keysym.sym == SDLK_DOWN) { y += 15; }
    else if (e.key.keysym.sym == SDLK_LEFT) { flip = false; x -= 15;}
    else if (e.key.keysym.sym == SDLK_RIGHT) { flip = true;  x += 15;}
  }
}