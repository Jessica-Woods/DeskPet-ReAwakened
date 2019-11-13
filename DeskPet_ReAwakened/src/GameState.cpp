#include "GameState.h"

#include "Game.h"

GameState::GameState() {
}

GameState::~GameState() {
}

void GameState::setGame(Game& game) { this->game = &game; }
void GameState::setWindow(sdl::Window& window) { this->window = &window; }
void GameState::setTextureManager(sdl::TextureManager& textureManager) { this->textureManager = &textureManager; }
void GameState::setSpritesheetManager(sdl::SpritesheetManager& spritesheetManager) { this->spritesheetManager = &spritesheetManager; }
void GameState::setAnimationManager(sdl::AnimationManager& animationManager) { this->animationManager = &animationManager; }
void GameState::setPet(Pet& pet) { this->pet = &pet; }