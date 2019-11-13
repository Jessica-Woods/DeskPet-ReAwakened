#pragma once
#include <string>

class Pet {
public:
  enum class PetState { EGG, BABY, CHILD, ADULT, RETIRED };

  Pet();
  void save();

private:
  PetState state; 
  std::string name;
  int age;
  int bond;
};
