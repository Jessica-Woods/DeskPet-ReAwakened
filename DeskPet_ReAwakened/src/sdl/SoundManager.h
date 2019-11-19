#pragma once
#include "SDL.h"
#include "SDL_mixer.h"
#include "Music.h"
#include <string>

namespace sdl {
  class SoundManager {
    private:
      Music* loadMusic(std::string filepath);
      Mix_Chunk* loadSound(std::string filepath);
      void playMusic(Music* music);

      Music* currentSong = nullptr;
      Music* idleStateSong = nullptr;
      Music* sadStateSong = nullptr;
      Music* sickStateSong = nullptr;
      Music* sleepStateSong = nullptr;
      Music* foodGameSong = nullptr;

      Mix_Chunk* appleRedSound = nullptr;
      Mix_Chunk* appleGreenSound = nullptr;
      Mix_Chunk* gameOver = nullptr;

    public:
      SoundManager();
      ~SoundManager();

      void playIdleSong();
      void playSadSong();
      void playSickSong();
      void playSleepSong();
      void playFoodGameSong();

      void playRedAppleSound();
      void playGreenAppleSound();
      void playGameOverSound();
  };
}