#pragma once
#include "Music.h"
#include <stdexcept>

#include "SDL_mixer.h"
#include <string>

sdl::Music::Music() {
  this->sdlMusic = nullptr;
  this->playing = false;
}

sdl::Music::Music(Mix_Music* sdlMusic) {
  this->sdlMusic = sdlMusic;
  this->playing = false;
}

sdl::Music::~Music() {
  Mix_FreeMusic(sdlMusic);
}

void sdl::Music::play() {
  if (!playing) {
    Mix_PlayMusic(sdlMusic, -1);
    playing = true;
  }
}

void sdl::Music::stop() {
  if (playing) {
    Mix_HaltMusic();
    playing = false;
  }
}

sdl::Music* sdl::Music::loadFromFile(std::string filename) {
  std::string filepath = "resources/sounds/";
  std::string path = filepath + filename;
  auto music = Mix_LoadMUS(path.c_str());
  if (music == nullptr) {
    throw std::exception("Failed to load music");
  }
  return new sdl::Music(music);
}