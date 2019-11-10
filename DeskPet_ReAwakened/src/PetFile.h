#pragma once

#include "sdl/Texture.h"

// we will need to read in game data from a file
// and populate a struct with the appropriate data.

class PetFile {
private:
  std::string name = "";
  std::string age = "";
  std::string state = "";
  std::string bond = "";
  
public:
  PetFile(std::string filepath);
  void parseFile(std::vector<std::string>& lines);
  bool checkData();
};
