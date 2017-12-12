// GAME HEADER =================================================================
#ifndef GAME_H_
#define GAME_H_
// INCLUDES ====================================================================
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"
#include <iostream>
#include <random> //for random piece spawn
#include <ctime>  //for real random
// CLASS =======================================================================
class Game
{
  public:
    Game();
    ~Game();
    void init(const char* title, int xP, int yP, int width, int height, bool fullscreen);
    void update();
    void render();
    void renderPause();
    void events();
    void clean();
    static SDL_Renderer *renderer;
    static SDL_Event event;
    bool isRunning();
    bool isPaused();
  private:
    SDL_Texture* backgroundTexture;
    SDL_Rect srcBackground, destBackground;
    SDL_Texture* pauseTexture;
    SDL_Texture* howToPlayTexture;
    SDL_Texture* aboutTexture;
    SDL_Rect srcPause, destPause;
    int randomChoice;
    int randomNext;
    int pieceI;
    bool lines;
    int speed = 60;
    int rotationGhost = 0;
    int isRotated = false;
    bool newPiece = true;
    int counter = 0;
    bool running;
    bool paused = false;
    int menu = 0;
    SDL_Window *window;
};
#endif
