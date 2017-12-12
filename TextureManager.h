// TEXTURE MANAGER HEADER ======================================================
#ifndef TEXTUREMANAGER_H_
#define TEXTUREMANAGER_H_
// INCLUDES ====================================================================
#include "Game.h"
// CLASS =======================================================================
class TextureManager
{
    public:
        static SDL_Texture* LoadTexture(const char* texture);
        static void Draw(SDL_Texture* texture, SDL_Rect &src, SDL_Rect &dest);
};
#endif