#pragma once

#include "Texture.h"

namespace sdl {
  class TextureManager {
    private:
      Texture* border;
      Texture* dayBackground;
      Texture* nightBackground;
      Texture* petTvCat;

    public:
      TextureManager(sdl::Window& window);
      ~TextureManager();

      Texture& getBorder();
      Texture& getDayBackground();
      Texture& getNightBackground();
      Texture& getPetTvCat();
  };
}