#include "PetFile.h"
#include "util/file.h"
#include "util/string.h"

void PetFile::parseFile(std::vector<std::string>& lines) {
  for (auto line : lines) {

    // should I do is this way
    auto chunks = util::string::split(line, ':');
    // Name
    if (chunks[0] == "NAME") { name = util::string::trim(chunks[1]); }
    // Age
    if (chunks[0] == "AGE") { age = util::string::trim(chunks[1]); }
    // State
    if (chunks[0] == "STATE") { state = util::string::trim(chunks[1]); }
    // Bond
    if (chunks[0] == "BOND") { bond = util::string::trim(chunks[1]); }
    // Stats
    // Level
  }
}

bool PetFile::checkData() {
  if (
    name.empty() 
    || age.empty() 
    || state.empty()
    || bond.empty()
  ) { return false; }

  return true;
}

PetFile::PetFile(std::string filepath) {
  std::vector<std::string> lines = util::file::readCleanLines(filepath);
  parseFile(lines);
  if (checkData()) {
    std::cout << "Loaded A Pet!" << std::endl;
    // createPet(name, age, state, bond, stats);
  } else {
    // we need to create a new pet.
    std::cout << "Failure to load pet" << std::endl;
    // name = getPetsName();
    age = "0";
    state = "baby";
    bond = "0";
    // createPet(age, state, bond, stats);
  }
}