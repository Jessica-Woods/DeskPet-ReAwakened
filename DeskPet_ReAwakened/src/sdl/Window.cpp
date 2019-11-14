#include "Window.h"
#include "Texture.h"
#include <SDL.h>

sdl::Window::Window(std::string title, int width, int height) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw std::exception("Failed to initialize video");
  }

  if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
    throw std::exception("Failed to hint render scale quality");
  }

  sdlWindow = SDL_CreateWindow(
    title.c_str(),
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    width,
    height,
    SDL_WINDOW_SHOWN
  );
  if (sdlWindow == nullptr) {
    throw std::exception("Failed to create window");
  }

  sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
  if (sdlRenderer == nullptr) {
    throw std::exception("Failed to create renderer");
  }

  setRenderDrawColor(0xFF, 0xFF, 0xFF, 0xFF);

  if (IMG_Init(IMG_INIT_PNG) == 0) {
    throw std::exception("Failed to initialize SDL2_image");
  }

  open = true;
}

sdl::Window::~Window() {
  SDL_DestroyRenderer(sdlRenderer);
  SDL_DestroyWindow(sdlWindow);
  sdlWindow = nullptr;
  sdlRenderer = nullptr;

  IMG_Quit();
  SDL_Quit();
}

SDL_Renderer& sdl::Window::getSDLRenderer() {
  return *sdlRenderer;
}

bool sdl::Window::isOpen() {
  return open;
}

bool sdl::Window::pollEvent(SDL_Event& sdlEvent) {
  if (SDL_PollEvent(&sdlEvent) == 0) {
    return false;
  }

  if (sdlEvent.type == SDL_QUIT) {
    open = false;
  }

  return true;
}

void sdl::Window::setRenderDrawColor(Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha) {
  SDL_SetRenderDrawColor(sdlRenderer, red, green, blue, alpha);
}

void sdl::Window::renderClear() {
  SDL_RenderClear(sdlRenderer);
}

void sdl::Window::renderCopy(SDL_Texture& texture, SDL_Rect* source, SDL_Rect* target) {
  SDL_RenderCopy(sdlRenderer, &texture, source, target);
}

void sdl::Window::renderCopyEx(SDL_Texture& texture, SDL_Rect* source, SDL_Rect* target, bool f) {
  SDL_Point* center = NULL;
  double angle = 0;
  auto flip = f ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

  SDL_RenderCopyEx(sdlRenderer, &texture, source, target, angle, center, flip);
}

void sdl::Window::renderPresent() {
  SDL_RenderPresent(sdlRenderer);
}

sdl::Texture* sdl::Window::createTextureFromFile(std::string filepath) {
  SDL_Surface* surface = IMG_Load(filepath.c_str());
  if (surface == nullptr) {
    throw std::exception("Could not load image surface");
  }

  SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0xFF, 0xFF));

  SDL_Texture* texture = SDL_CreateTextureFromSurface(sdlRenderer, surface);
  if (texture == nullptr) {
    throw std::exception("Could not load image texture");
  }

  int width = surface->w;
  int height = surface->h;

  SDL_FreeSurface(surface);

  return new Texture(*this, texture, width, height);
}
