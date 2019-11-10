#pragma once
#include <string>
#include <vector>

namespace util {
  namespace file {
    std::vector<std::string> readLines(std::string path);
    std::vector<std::string> readCleanLines(std::string path);
  }
}