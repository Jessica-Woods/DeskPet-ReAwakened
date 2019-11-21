#include "Button.h"

Button::Button(sdl::Texture& _texture, int x, int y) : texture(_texture) {
  this->x = x;
  this->y = y;
}

void Button::onClick(std::function<void()> callback) {
  callbacks.push_back(callback);
}

void Button::handleInput(SDL_Event e) {
  if (e.button.type == SDL_MOUSEBUTTONDOWN 
      && e.button.button == SDL_BUTTON_LEFT
      && e.button.x > x
      && e.button.x < x + texture.getWidth()
      && e.button.y > y
      && e.button.y < y + texture.getHeight()) {
    for (auto callback : callbacks) {
      callback();
    }
  }
}

void Button::render() {
  texture.render(x, y);
}
