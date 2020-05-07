#pragma
#include <vector>
#include <cstdlib>

#include "GameState.h"
#include "Button.h"

class HungerGame : public GameState {
private:
  enum class appleType { redApple, greenApple };
  struct apple{
    appleType type;
    sdl::Texture& texture;
    int x;
    int y;
    int dy;
  };

  std::vector<apple*> apples;
  int moveTimerMs = 0.0;
  int appleTimerMs = 0.0;
  int greenApplesHit = 0;
  Button* feedButton = nullptr;
  Button* helpButton = nullptr;

  void onFeedClicked();
  void onHelpClicked();

  void renderHealthBar();
  void renderHungerBar();

  void createApple();
  void spawnApples(double deltaTime);
  void applesMove(double deltaTime);
  void appleHit(SDL_Event e);

public:
  HungerGame();
  ~HungerGame();

  void initialize() override;
  void handleInput(SDL_Event e) override;
  void update(double deltaTime) override;
  void render() override;
};