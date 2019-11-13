#pragma once

#include "sdl/AnimationManager.h"
#include "Pet.h"

// we will need to read in game data from a file
// and populate a struct with the appropriate data.

class PetFile {
private:
  Pet::PetState state;
  std::string name;
  int age;
  int bond;

  static std::string filepath;
  static Pet::PetState petStateFromString(std::string s);
  static std::string petStateToString(Pet::PetState s);
  
public:
  PetFile(Pet::PetState state, std::string name, int age, int bond);
  void save();

  Pet::PetState& getState();
  std::string getName();
  int getAge();
  int getBond();

  static PetFile* tryLoad();
};
