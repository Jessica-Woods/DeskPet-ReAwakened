#pragma once
#include "SDL.h"
#include "SDL_mixer.h"
#include <string>

namespace sdl {
  class Music {
    private:
      Mix_Music* sdlMusic;
      bool playing;
    public:
      Music();
      Music(Mix_Music* sdlMusic);
      ~Music();

      void play();
      void stop();

      static Music* loadFromFile(std::string filepath);
  };
}