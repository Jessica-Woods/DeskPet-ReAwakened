#include "PetFile.h"
#include "util/file.h"
#include "util/string.h"
#include "util/time.h"
#include <stdexcept>
#include <ctime>
#include <chrono>

#include <fstream>
#include <ostream>

std::string PetFile::filepath = "pet.txt";

PetFile::PetFile(Pet::Stage _stage, std::string _name, int _age, int _bond, int _health, int _hunger, bool _sleeping, std::chrono::system_clock::time_point _lastSaveTime) :
  stage(_stage), name(_name), age(_age), bond(_bond), health(_health), hunger(_hunger), sleeping(_sleeping), lastSaveTime(_lastSaveTime) {
}

void PetFile::save() {
  std::ofstream file(filepath, std::ofstream::out);
  std::time_t time = std::time(nullptr);

  auto now = std::chrono::system_clock::now();
  auto nowT = std::chrono::system_clock::to_time_t(now);

  file << "NAME: " << name;
  file << "\nAGE: " << age;
  file << "\nSTAGE: " << petStageToString(stage);
  file << "\nBOND: " << bond;
  file << "\nHEALTH: " << health;
  file << "\nHUNGER: " << hunger;
  file << "\nSLEEPING: " << sleeping;
  file << "\nTIME: " << util::time::toString(lastSaveTime);
  
  file.close();
}

Pet::Stage& PetFile::getStage() { return stage; }
std::string PetFile::getName() { return name; }
int PetFile::getAge() { return age; }
int PetFile::getBond() { return bond; }
int PetFile::getHealth() { return health; }
int PetFile::getHunger() { return hunger; }
bool PetFile::getSleeping() { return sleeping; }

std::chrono::system_clock::time_point PetFile::getLastSaveTime() {
  return lastSaveTime;
}

PetFile* PetFile::tryLoad() {
  if (util::file::exists(filepath)) {
    std::string stage;
    std::string name;
    std::string age;
    std::string bond;
    std::string health;
    std::string hunger;
    std::string sleeping;
    std::string time;

    std::vector<std::string> lines = util::file::readCleanLines(filepath);
    for (auto line : lines) {
      auto pair = util::string::split_first(line, ":");
      auto command = std::get<0>(pair);
      auto value = util::string::trim(std::get<1>(pair));

      if (command == "STAGE") { stage = value; }
      if (command == "NAME") { name = value; }
      if (command == "AGE") { age = value; }
      if (command == "BOND") { bond = value; }
      if (command == "HEALTH") { health = value; }
      if (command == "HUNGER") { hunger = value; }
      if (command == "SLEEPING") { sleeping = value; }
      if (command == "TIME") { time = value; }
    }

    if (stage.empty() || name.empty() || age.empty() || bond.empty() || 
      health.empty() || hunger.empty() || sleeping.empty() || time.empty()) {
      throw std::exception("Invalid pet file");
    }

    return new PetFile(
      petStageFromString(stage), 
      name, 
      stoi(age), 
      stoi(bond),
      stoi(health),
      stoi(hunger),
      sleeping == "1",
      util::time::fromString(time)
    );
  } else {
    return nullptr;
  }
}

Pet::Stage PetFile::petStageFromString(std::string s) {
  if(s == "EGG") { return Pet::Stage::EGG; }
  else if(s == "BABY") { return Pet::Stage::BABY; }
  else if (s == "CHILD") { return Pet::Stage::CHILD; }
  else if (s == "ADULT") { return Pet::Stage::ADULT; }
  else if (s == "RETIRED") { return Pet::Stage::RETIRED; }
  else { throw std::exception("Invalid pet stageFromString"); }
}

std::string PetFile::petStageToString(Pet::Stage s) {
  if (s == Pet::Stage::EGG) { return "EGG"; }
  else if (s == Pet::Stage::BABY) { return  "BABY"; }
  else if (s == Pet::Stage::CHILD) { return "CHILD"; }
  else if (s == Pet::Stage::ADULT) { return "ADULT"; }
  else if (s == Pet::Stage::RETIRED) { return "RETIRED"; }
  else { throw std::exception("Invalid pet stageToString"); }
}