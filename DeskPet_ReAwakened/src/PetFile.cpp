#include "PetFile.h"
#include "util/file.h"
#include "util/string.h"
#include <stdexcept>

#include <fstream>
#include <ostream>

std::string PetFile::filepath = "pet.txt";

PetFile::PetFile(Pet::PetState _state, std::string _name, int _age, int _bond) :
  state(_state), name(_name), age(_age), bond(_bond) {
}

void PetFile::save() {
  std::ofstream file(filepath, std::ofstream::out);

  file << "NAME: " << name;
  file << "\nAGE: " << age;
  file << "\nSTATE: " << petStateToString(state);
  file << "\nBOND: " << bond;

  file.close();
}

Pet::PetState& PetFile::getState() { return state; }
std::string PetFile::getName() { return name; }
int PetFile::getAge() { return age; }
int PetFile::getBond() { return bond; }

PetFile* PetFile::tryLoad() {
  if (util::file::exists(filepath)) {
    std::string state;
    std::string name;
    std::string age;
    std::string bond;

    std::vector<std::string> lines = util::file::readCleanLines(filepath);
    for (auto line : lines) {
      auto chunks = util::string::split(line, ':');
      if (chunks[0] == "STATE") { state = util::string::trim(chunks[1]); }
      if (chunks[0] == "NAME") { name = util::string::trim(chunks[1]); }
      if (chunks[0] == "AGE") { age = util::string::trim(chunks[1]); }
      if (chunks[0] == "BOND") { bond = util::string::trim(chunks[1]); }
      // Stats
      // Level
    }

    if (state.empty() || name.empty() || age.empty() || bond.empty()) {
      throw std::exception("Invalid pet file");
    }

    return new PetFile(
      petStateFromString(state), 
      name, 
      stoi(age), 
      stoi(bond)
    );
  } else {
    return nullptr;
  }
}

Pet::PetState PetFile::petStateFromString(std::string s) {
  if(s == "EGG") { return Pet::PetState::EGG; }
  else if(s == "BABY") { return Pet::PetState::BABY; }
  else if (s == "CHILD") { return Pet::PetState::CHILD; }
  else if (s == "ADULT") { return Pet::PetState::ADULT; }
  else if (s == "RETIRED") { return Pet::PetState::RETIRED; }
  else { throw std::exception("Invalid pet stateFromString"); }
}

std::string PetFile::petStateToString(Pet::PetState s) {
  if (s == Pet::PetState::EGG) { return "EGG"; }
  else if (s == Pet::PetState::BABY) { return  "BABY"; }
  else if (s == Pet::PetState::CHILD) { return "CHILD"; }
  else if (s == Pet::PetState::ADULT) { return "ADULT"; }
  else if (s == Pet::PetState::RETIRED) { return "RETIRED"; }
  else { throw std::exception("Invalid pet stateToString"); }
}