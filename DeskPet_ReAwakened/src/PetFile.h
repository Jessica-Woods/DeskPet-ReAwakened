#pragma once

#include "Pet.h"

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
