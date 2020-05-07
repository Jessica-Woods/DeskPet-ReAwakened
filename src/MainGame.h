#pragma
#include "GameState.h"
#include "Button.h"

class MainGame : public GameState {
private:
  Button* feedButton = nullptr;
  Button* mediButton = nullptr;
  Button* sleepButton = nullptr;
  Button* helpButton = nullptr;

  void onFeedClicked();
  void onMediClicked();
  void onSleepClicked();
  void onHelpClicked();

  void renderHealthBar();
  void renderHungerBar();
  
  void updateMusic();

public:
  MainGame();
  ~MainGame();

  void initialize() override;
  void handleInput(SDL_Event e) override;
  void update(double deltaTime) override;
  void render() override;
};