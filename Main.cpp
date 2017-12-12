// Tetris
// Author: Serban Mihai Ciprian
// Language: C++11
// Compiler: GNU G++
// Developed on: GNU/Linux Distro. Linux Mint 18.2
// Verison: 0.8
// GitHub: https://github.com/serban-mihai/Tetris
// IMPORTS =====================================================================
#include <iostream>
#include "Game.h"
// LIBS ========================================================================
using namespace std;
// OBJECTS DECLARATION =========================================================
Game *game = nullptr;
// MAIN ========================================================================
int main(int argc, const char * argv[])
{
  // Frame rate control (locked to 60FPS/s)
  const int FPS = 60;
  const int frameDelay = 1000 / FPS;
  int frameTime;
  Uint32 frameStart;
  // Game init and loop
  game = new Game();
  game->init("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 704, false);
  while(game->isRunning())
  {
    game->events();
    while(!game->isPaused())
    {
      frameStart = SDL_GetTicks();
      game->events();
      game->update();
      game->render();
      frameTime = SDL_GetTicks() - frameStart;
      if(frameDelay > frameTime)
      { SDL_Delay(frameDelay - frameTime); }
    }
    game->renderPause();
  }
  game->clean();
  return 0;
}
