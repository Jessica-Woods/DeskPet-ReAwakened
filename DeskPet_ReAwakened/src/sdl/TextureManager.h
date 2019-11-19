#pragma once

#include "Texture.h"

namespace sdl {
  class TextureManager {
    private:
      Texture* border;
      Texture* dayBackground;
      Texture* nightBackground;
      Texture* petTvCat;

      Texture* heartEmpty;
      Texture* heartHalf;
      Texture* heartFull;

      Texture* iconFeed;
      Texture* iconSleep;
      Texture* iconMedi;
      Texture* iconHelp;

      Texture* appleRed;
      Texture* appleGreen;

      Texture* hungerFull;
      Texture* hungerEmpty;

    public:
      TextureManager(sdl::Window& window);
      ~TextureManager();

      Texture& getBorder();
      Texture& getDayBackground();
      Texture& getNightBackground();

      Texture& getPetTvCat();

      Texture& getheartEmpty();
      Texture& getheartHalf();
      Texture& getheartFull();

      Texture& getIconFeed();
      Texture& getIconSleep();
      Texture& getIconMedi();
      Texture& getIconHelp();

      Texture& getAppleRed();
      Texture& getAppleGreen();

      Texture& getHungerFull();
      Texture& getHungerEmpty();
  };
}