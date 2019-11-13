#pragma once

#include "Texture.h"
#include "TextureManager.h"

sdl::TextureManager::TextureManager(sdl::Window& window) {
  std::string images = "resources/images/";
  border = window.createTextureFromFile(images + "border.png");
  dayBackground = window.createTextureFromFile(images + "day-background.png");
  nightBackground = window.createTextureFromFile(images + "night-background.png");
  petTvCat = window.createTextureFromFile(images + "pet-TvCat.png");
}

sdl::TextureManager::~TextureManager() {
  delete border;
  delete dayBackground;
  delete nightBackground;
  delete petTvCat;
}

sdl::Texture& sdl::TextureManager::getBorder() { return *border; }
sdl::Texture& sdl::TextureManager::getDayBackground() { return *dayBackground; }
sdl::Texture& sdl::TextureManager::getNightBackground() { return *nightBackground; }
sdl::Texture& sdl::TextureManager::getPetTvCat() {return *petTvCat;}
