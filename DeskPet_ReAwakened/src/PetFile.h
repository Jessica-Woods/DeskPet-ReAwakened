#pragma once

#include "Pet.h"

class PetFile {
private:
  Pet::Stage stage;
  std::string name;
  int age;
  int bond;

  static std::string filepath;
  static Pet::Stage petStageFromString(std::string s);
  static std::string petStageToString(Pet::Stage s);
  
public:
  PetFile(Pet::Stage stage, std::string name, int age, int bond);
  void save();

  Pet::Stage& getStage();
  std::string getName();
  int getAge();
  int getBond();

  static PetFile* tryLoad();
};
