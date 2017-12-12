// PIECE HEADER ================================================================
#ifndef PIECE_H_
#define PIECE_H_
// INCLUDES ====================================================================
#include "Game.h"
#include "TextureManager.h"
#define N 5
// CLASS =======================================================================
class Piece
{
    public:
        Piece(int model,int next, int x, int y, int xN, int yN);
        ~Piece();
        void update();
        void render();
        void renderNext();
        void printPiece();
        void rotatePiece();
        void movePiece(int speed);
        void moveGhost(int speed);
        void strifePiece(int direction);
        int* getMatrixPoints();
        void printMatrixPoints(int* ptr);
        int getType();
        int getNextType();
        void setYGhost(int pos);
        int getYGhost();
        void setXGhost(int pos);
        int getXGhost();
        void setXNext(int pos);
        void setYNext(int pos);
        SDL_Texture* getPieceTexture();
        SDL_Texture* getGhostTexture();
    private:
        int matrix[N][N] =  {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 2, 0, 0},    //number 2 is the pivot point for rotation
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                            };
        int matrixNext[N][N] = {
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 2, 0, 0},    //number 2 is the pivot point for rotation
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}
                            };
        int type;
        int nextType;
        SDL_Texture* pieceTexture;
        SDL_Texture* ghostTexture;
        SDL_Texture* nextTexture;
        SDL_Texture* blankTexture = TextureManager::LoadTexture("img/BlockAlpha.png");
        SDL_Rect srcRect, destRect;
        SDL_Rect srcGhost, destGhost;
        SDL_Rect srcNext, destNext;
        int xPos;
        int yPos;
        int xGhost;
        int yGhost;
        int xNext;
        int yNext;
};

#endif
