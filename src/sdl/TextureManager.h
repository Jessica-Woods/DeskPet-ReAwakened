#pragma once

#include "Texture.h"

namespace sdl {
  class TextureManager {
    private:
      Texture* border;
      Texture* dayBackground;
      Texture* nightBackground;
      Texture* helpScreenMain;
      Texture* helpScreenGame;

      Texture* petTvCat;

      Texture* heartEmpty;
      Texture* heartHalf;
      Texture* heartFull;

      Texture* iconFeed;
      Texture* iconSleep;
      Texture* iconMedi;
      Texture* iconHelp;
      Texture* iconHelpBack;

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
      Texture& getHelpScreenMain();
      Texture& getHelpScreenGame();

      Texture& getPetTvCat();

      Texture& getHeartEmpty();
      Texture& getHeartHalf();
      Texture& getHeartFull();

      Texture& getIconFeed();
      Texture& getIconSleep();
      Texture& getIconMedi();
      Texture& getIconHelp();
      Texture& getIconHelpBack();

      Texture& getAppleRed();
      Texture& getAppleGreen();

      Texture& getHungerFull();
      Texture& getHungerEmpty();
  };
}