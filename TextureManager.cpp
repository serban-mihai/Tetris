// TEXTURE MANAGER FILE ========================================================
#include "TextureManager.h"
// METHODS =====================================================================
SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
    SDL_Surface* temp = IMG_Load(texture);
    SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, temp);
    SDL_FreeSurface(temp);
    return tex;
}
void TextureManager::Draw(SDL_Texture* texture, SDL_Rect &src, SDL_Rect &dest)
{
    SDL_RenderCopy(Game::renderer, texture, &src, &dest);
    return;
}