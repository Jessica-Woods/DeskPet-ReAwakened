#pragma once

#include "Pet.h"
#include <chrono>

class PetFile {
private:
  Pet::Stage stage;
  std::string name;
  int age;
  int bond;
  int health;
  int hunger;
  bool sleeping;
  std::chrono::system_clock::time_point lastSaveTime;

  static std::string filepath;
  static Pet::Stage petStageFromString(std::string s);
  static std::string petStageToString(Pet::Stage s);
  
public:
  PetFile(
    Pet::Stage stage, 
    std::string name, 
    int age, 
    int bond, 
    int health, 
    int hunger,
    bool sleeping,
    std::chrono::system_clock::time_point lastSaveTime
  );
  void save();

  Pet::Stage& getStage();
  std::string getName();
  int getAge();
  int getBond();
  int getHealth();
  int getHunger();
  bool getSleeping();
  std::chrono::system_clock::time_point getLastSaveTime();

  static PetFile* tryLoad();
};
