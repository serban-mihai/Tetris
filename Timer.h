// PIECE HEADER ================================================================
#ifndef TIMER_H_
#define TIMER_H_
// INCLUDES ====================================================================
#include "Game.h"
#include <string>
// CLASS =======================================================================
class Timer
{
    public:
        Timer();
        ~Timer();
        void update();
        void render();
        void setScore(long number);
        long getScore();
        void setLines(int number);
        int getLines();
    private:
        long score;
        int lines;
        TTF_Font* font = TTF_OpenFont("FetteTrumpDeutsch.ttf", 30);
        SDL_Color color = {255, 255, 255, 255};
        // For Score
        SDL_Surface* textSurface;
        SDL_Texture* text;
        SDL_Rect textRect;
        // For lines
        SDL_Surface* textLinesSurface;
        SDL_Texture* textLines;
        SDL_Rect textLinesRect;
};
#endif