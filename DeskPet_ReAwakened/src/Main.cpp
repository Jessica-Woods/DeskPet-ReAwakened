#include "Game.h"
#include "GameState.h"
#include "MainGame.h"

int main(int argc, char* args[]) {
  Game game;
  game.pushState(new MainGame);

  while (game.isRunning()) {
    game.handleInput();
    game.update();
    game.render();
    game.runPostLoopTriggers();
  }

  return 0;
}