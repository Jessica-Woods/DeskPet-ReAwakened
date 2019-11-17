#pragma
#include "GameState.h"
#include "Button.h"

class MainGame : public GameState {
private:
  Button* feedButton = nullptr;
  Button* mediButton = nullptr;
  Button* sleepButton = nullptr;

  void onFeedClicked();
  void onMediClicked();
  void onSleepClicked();

public:
  MainGame();
  ~MainGame();

  void initialize() override;
  void handleInput(SDL_Event e) override;
  void update(double deltaTime) override;
  void render() override;
};