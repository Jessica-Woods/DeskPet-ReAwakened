#pragma
#include "GameState.h"

class MainGame : public GameState {

public:
  MainGame();
  ~MainGame();

  void handleInput(SDL_Event e) override;
  void update(double deltaTime) override;
  void render() override;
};