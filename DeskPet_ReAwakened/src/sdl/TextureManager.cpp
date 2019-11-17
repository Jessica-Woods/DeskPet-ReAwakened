#pragma once

#include "Texture.h"
#include "TextureManager.h"

sdl::TextureManager::TextureManager(sdl::Window& window) {
  std::string images = "resources/images/";
  border = window.createTextureFromFile(images + "border.png");
  dayBackground = window.createTextureFromFile(images + "day-background.png");
  nightBackground = window.createTextureFromFile(images + "night-background.png");

  petTvCat = window.createTextureFromFile(images + "pet-TvCat.png");

  heartEmpty = window.createTextureFromFile(images + "heart-Empty.png");
  heartHalf = window.createTextureFromFile(images + "heart-Half.png");
  heartFull = window.createTextureFromFile(images + "heart-Full.png");

  iconFeed = window.createTextureFromFile(images + "icon-Feed.png");
  iconSleep = window.createTextureFromFile(images + "icon-Sleep.png");
  iconMedi = window.createTextureFromFile(images + "icon-Medi.png");

  appleRed = window.createTextureFromFile(images + "apple-Red.png");
  appleGreen = window.createTextureFromFile(images + "apple-Green.png");
}

sdl::TextureManager::~TextureManager() {
  delete border;
  delete dayBackground;
  delete nightBackground;

  delete petTvCat;

  delete heartEmpty;
  delete heartHalf;
  delete heartFull;

  delete iconFeed;
  delete iconSleep;
  delete iconMedi;

  delete appleRed;
  delete appleGreen;
}

sdl::Texture& sdl::TextureManager::getBorder() { return *border; }
sdl::Texture& sdl::TextureManager::getDayBackground() { return *dayBackground; }
sdl::Texture& sdl::TextureManager::getNightBackground() { return *nightBackground; }

sdl::Texture& sdl::TextureManager::getPetTvCat() {return *petTvCat;}

sdl::Texture& sdl::TextureManager::getheartEmpty() {return *heartEmpty; }
sdl::Texture& sdl::TextureManager::getheartHalf() { return *heartHalf; }
sdl::Texture& sdl::TextureManager::getheartFull() { return *heartFull; }

sdl::Texture& sdl::TextureManager::getIconFeed() { return *iconFeed; }
sdl::Texture& sdl::TextureManager::getIconSleep() { return *iconSleep; }
sdl::Texture& sdl::TextureManager::getIconMedi() { return *iconMedi; }

sdl::Texture& sdl::TextureManager::getAppleRed() { return* appleRed;}
sdl::Texture& sdl::TextureManager::getAppleGreen() { return *appleGreen; }