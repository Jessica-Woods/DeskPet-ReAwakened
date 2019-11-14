#include "Pet.h"
#include "PetFile.h"
#include "sdl/AnimationManager.h"

Pet::Pet(sdl::AnimationManager& cm) : currentAnimation(cm) {
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

void Pet::handleInput(SDL_Event e) {
  if (e.type == SDL_KEYDOWN) {
    if (e.key.keysym.sym == SDLK_UP) { yPos -= 15; }
    else if (e.key.keysym.sym == SDLK_DOWN) { yPos += 15; }
    else if (e.key.keysym.sym == SDLK_LEFT) { xPos -= 15; flip = false; }
    else if (e.key.keysym.sym == SDLK_RIGHT) { xPos += 15; flip = true; }
  }
}


