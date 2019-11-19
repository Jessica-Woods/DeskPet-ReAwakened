#pragma once
#include "SoundManager.h"
#include <stdexcept>

#include "SDL_mixer.h"
#include <string>

sdl::Music* sdl::SoundManager::loadMusic(std::string filename) {
  return sdl::Music::loadFromFile(filename);
}

Mix_Chunk* sdl::SoundManager::loadSound(std::string filename) {
  std::string filepath = "resources/sounds/";
  std::string path = filepath + filename;
  auto sound = Mix_LoadWAV(path.c_str());
  if (sound == nullptr) {
    throw std::exception("Failed to load sound");
  }
  return sound;
}

void sdl::SoundManager::playMusic(Music* music) {
  if (currentSong != nullptr && currentSong != music) {
    currentSong->stop();
  }

  music->play();
  currentSong = music;
}

sdl::SoundManager::SoundManager() {
  if (SDL_Init(SDL_INIT_AUDIO) < 0) {
    throw std::exception("Failed to initialize SDL_mixer");
  }
  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    throw std::exception("Failed to open audio mixer");
  }

  //Music from: https://freesound.org/people/cabled_mess/sounds/335361/
  idleStateSong = loadMusic("335361__cabled-mess__little-happy-tune-22-10.wav");

  //Music from: https://freesound.org/people/Clinthammer/sounds/179510/ 
  sickStateSong = loadMusic("179510__clinthammer__clinthammermusic-gamerstep-chords-2.wav");
  
  sadStateSong = loadMusic("200431__setuniman__aimless-1c87.wav");
  
  //Music from: https://freesound.org/people/FoolBoyMedia/sounds/264295/
  sleepStateSong = loadMusic("264295__foolboymedia__sky-loop.wav");

  //Music from: https://freesound.org/people/Burinskas/sounds/362133/
  foodGameSong = loadMusic("362133__burinskas__chiptune-loop-light.wav");


  // SFX from: https://freesound.org/people/meroleroman7/sounds/238283/
  appleRedSound = loadSound("238283__meroleroman7__8-bit-noise.wav");

  // SFX from: https://freesound.org/people/jalastram/sounds/239987/
  appleGreenSound = loadSound("239987__jalastram__fx114.wav");

  // SFX from: https://freesound.org/people/ProjectsU012/sounds/333785/
  gameOver = loadSound("333785__projectsu012__8-bit-failure-sound.wav");
}

sdl::SoundManager::~SoundManager() {  
  delete idleStateSong;
  delete sickStateSong;
  delete sadStateSong;
  delete sleepStateSong;
  delete foodGameSong;

  Mix_FreeChunk(appleRedSound); appleRedSound = nullptr;
  Mix_FreeChunk(appleGreenSound); appleGreenSound = nullptr;
  Mix_FreeChunk(gameOver); gameOver = nullptr;

  Mix_Quit();
}

void sdl::SoundManager::playIdleSong() { playMusic(idleStateSong); }
void sdl::SoundManager::playSadSong() { playMusic(sadStateSong); }
void sdl::SoundManager::playSickSong() { playMusic(sickStateSong); }
void sdl::SoundManager::playSleepSong() { playMusic(sleepStateSong); }
void sdl::SoundManager::playFoodGameSong() { playMusic(foodGameSong); }

void sdl::SoundManager::playRedAppleSound() { 
  Mix_PlayChannel(-1, appleRedSound, 0);
}

void sdl::SoundManager::playGreenAppleSound() {
  Mix_PlayChannel(-1, appleGreenSound, 0);
}

void sdl::SoundManager::playGameOverSound() {
  Mix_PlayChannel(-1, gameOver, 0);
}
