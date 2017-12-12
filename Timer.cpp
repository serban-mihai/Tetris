// TIMER FILE ==================================================================
#include "Timer.h"
// CONSTRUCTORS & DESTRUCTOR ===================================================
Timer::Timer()
{
    score = 0;
    lines = 0;
}
Timer::~Timer()
{}
// METHODS =====================================================================
void Timer::update()
{
    // Score
    textRect.x = 455;
    textRect.y = 245;
    // Lines
    textLinesRect.x = 495;
    textLinesRect.y = 325;
    return;
}
void Timer::render()
{
    // Score Render
    std::string tempScore = std::to_string(score);
    char const *displayScore = tempScore.c_str();
    textSurface = TTF_RenderText_Solid(font, displayScore, color);
    text = SDL_CreateTextureFromSurface(Game::renderer, textSurface);
    SDL_QueryTexture(text, NULL, NULL, &textRect.w, &textRect.h);
    SDL_RenderCopy(Game::renderer, text, NULL, &textRect);
    // Lines Render
    std::string tempLinesScore = std::to_string(lines);
    char const *displayLines = tempLinesScore.c_str();
    textLinesSurface = TTF_RenderText_Solid(font, displayLines, color);
    textLines = SDL_CreateTextureFromSurface(Game::renderer, textLinesSurface);
    SDL_QueryTexture(textLines, NULL, NULL, &textLinesRect.w, &textLinesRect.h);
    SDL_RenderCopy(Game::renderer, textLines, NULL, &textLinesRect);

    return;
}
// SETTER & GETTER =============================================================
void Timer::setScore(long number)
{
    score += number;
    return;
}
long Timer::getScore()
{
    return score;
}
void Timer::setLines(int number)
{
    lines += number;
    return;
}
int Timer::getLines()
{
    return lines;
}