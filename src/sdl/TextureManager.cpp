#pragma once

#include "Texture.h"
#include "TextureManager.h"

sdl::TextureManager::TextureManager(sdl::Window& window) {
  std::string images = "resources/images/";
  border = window.createTextureFromFile(images + "border.png");
  dayBackground = window.createTextureFromFile(images + "day-background.png");
  nightBackground = window.createTextureFromFile(images + "night-background.png");
  helpScreenMain = window.createTextureFromFile(images + "help-background.png");
  helpScreenGame = window.createTextureFromFile(images + "help-background2.png");

  petTvCat = window.createTextureFromFile(images + "pet-TvCat.png");

  heartEmpty = window.createTextureFromFile(images + "heart-Empty.png");
  heartHalf = window.createTextureFromFile(images + "heart-Half.png");
  heartFull = window.createTextureFromFile(images + "heart-Full.png");

  iconFeed = window.createTextureFromFile(images + "icon-Feed.png");
  iconSleep = window.createTextureFromFile(images + "icon-Sleep.png");
  iconMedi = window.createTextureFromFile(images + "icon-Medi.png");
  iconHelp = window.createTextureFromFile(images + "icon-Help.png");
  iconHelpBack = window.createTextureFromFile(images + "icon-Help2.png");

  appleRed = window.createTextureFromFile(images + "apple-Red.png");
  appleGreen = window.createTextureFromFile(images + "apple-Green.png");

  hungerFull = window.createTextureFromFile(images + "hunger-Full.png");
  hungerEmpty = window.createTextureFromFile(images + "hunger-Empty.png");
}

sdl::TextureManager::~TextureManager() {
  delete border;
  delete dayBackground;
  delete nightBackground;
  delete helpScreenGame;
  delete helpScreenMain;

  delete petTvCat;

  delete heartEmpty;
  delete heartHalf;
  delete heartFull;

  delete iconFeed;
  delete iconSleep;
  delete iconMedi;
  delete iconHelp;
  delete iconHelpBack;

  delete appleRed;
  delete appleGreen;

  delete hungerFull;
  delete hungerEmpty;
}

sdl::Texture& sdl::TextureManager::getBorder() { return *border; }
sdl::Texture& sdl::TextureManager::getDayBackground() { return *dayBackground; }
sdl::Texture& sdl::TextureManager::getNightBackground() { return *nightBackground; }

sdl::Texture& sdl::TextureManager::getHelpScreenMain(){ return *helpScreenMain; }
sdl::Texture& sdl::TextureManager::getHelpScreenGame(){ return *helpScreenGame; }

sdl::Texture& sdl::TextureManager::getPetTvCat() { return *petTvCat; }

sdl::Texture& sdl::TextureManager::getHeartEmpty() { return *heartEmpty; }
sdl::Texture& sdl::TextureManager::getHeartHalf() { return *heartHalf; }
sdl::Texture& sdl::TextureManager::getHeartFull() { return *heartFull; }

sdl::Texture& sdl::TextureManager::getIconFeed() { return *iconFeed; }
sdl::Texture& sdl::TextureManager::getIconSleep() { return *iconSleep; }
sdl::Texture& sdl::TextureManager::getIconMedi() { return *iconMedi; }
sdl::Texture& sdl::TextureManager::getIconHelp() { return *iconHelp; }

sdl::Texture& sdl::TextureManager::getIconHelpBack() { return *iconHelpBack;}

sdl::Texture& sdl::TextureManager::getAppleRed() { return *appleRed;}
sdl::Texture& sdl::TextureManager::getAppleGreen() { return *appleGreen; }

sdl::Texture& sdl::TextureManager::getHungerFull(){ return *hungerFull; }
sdl::Texture& sdl::TextureManager::getHungerEmpty(){ return *hungerEmpty;}
