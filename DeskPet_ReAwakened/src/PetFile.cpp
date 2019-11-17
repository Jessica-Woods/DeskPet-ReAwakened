#define _CRT_SECURE_NO_WARNINGS
// We're not using threads so were going to ignore this warning
// https://stackoverflow.com/questions/38034033/c-localtime-this-function-or-variable-may-be-unsafe

#include "PetFile.h"
#include "util/file.h"
#include "util/string.h"
#include <stdexcept>
#include <ctime>

#include <fstream>
#include <ostream>

std::string PetFile::filepath = "pet.txt";

PetFile::PetFile(Pet::Stage _stage, std::string _name, int _age, int _bond) :
  stage(_stage), name(_name), age(_age), bond(_bond) {
}

void PetFile::save() {
  std::ofstream file(filepath, std::ofstream::out);
  std::time_t time = std::time(nullptr);

  file << "NAME: " << name;
  file << "\nAGE: " << age;
  file << "\nSTAGE: " << petStageToString(stage);
  file << "\nBOND: " << bond;
  // WARNING : if threads are added to the game change the way time is recorded
  // Will change if we have time
  file << "\nTIME: " << std::asctime(std::localtime(&time));

  file.close();
}

Pet::Stage& PetFile::getStage() { return stage; }
std::string PetFile::getName() { return name; }
int PetFile::getAge() { return age; }
int PetFile::getBond() { return bond; }

PetFile* PetFile::tryLoad() {
  if (util::file::exists(filepath)) {
    std::string stage;
    std::string name;
    std::string age;
    std::string bond;

    std::vector<std::string> lines = util::file::readCleanLines(filepath);
    for (auto line : lines) {
      auto chunks = util::string::split(line, ':');
      if (chunks[0] == "STAGE") { stage = util::string::trim(chunks[1]); }
      if (chunks[0] == "NAME") { name = util::string::trim(chunks[1]); }
      if (chunks[0] == "AGE") { age = util::string::trim(chunks[1]); }
      if (chunks[0] == "BOND") { bond = util::string::trim(chunks[1]); }
      if (chunks[0] == "TIME") { }
      // Stats
      // Level
    }

    if (stage.empty() || name.empty() || age.empty() || bond.empty()) {
      throw std::exception("Invalid pet file");
    }

    return new PetFile(
      petStageFromString(stage), 
      name, 
      stoi(age), 
      stoi(bond)
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