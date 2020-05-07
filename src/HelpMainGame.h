#pragma
#include <vector>
#include <cstdlib>

#include "GameState.h"
#include "Button.h"

class HelpMainGame : public GameState {
private:

  Button* helpButton = nullptr;
  void onHelpClicked();

public:
  HelpMainGame();
  ~HelpMainGame();

  void initialize() override;
  void handleInput(SDL_Event e) override;
  void update(double deltaTime) override;
  void render() override;
};