#include <SDL.h>
#include <iostream>

#include "sdl/Window.h"

#include "Game.h"
#include "GameState.h"
#include "MainGame.h"

int main(int argc, char* args[]) {

  // Load base resources && Setup game (read in save file)-> outputs a myGame was a struct now a class


  Game game;
  game.pushState(new MainGame);
  while (game.isRunning()) {
    game.handleInput();
    game.update();
    game.render();
  }

  // enter Game Loop, until window close requested

  // {
  //    ProcessEvents()
  //    Clear screen
  //    UpdateGame(myGame)
  //    DrawGame(myGame)
  //    Refresh()
  // } 

  return 0;
}