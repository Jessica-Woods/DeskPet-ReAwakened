#include "Pet.h"
#include "PetFile.h"

Pet::Pet() {
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
