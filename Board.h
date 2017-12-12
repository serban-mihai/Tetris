// PIECE HEADER ================================================================
#ifndef BOARD_H_
#define BOARD_H_
// INCLUDES ====================================================================
#include "Game.h"
#include "Piece.h"
#include "TextureManager.h"
#define N 5
#define W 14    // 10 for the board, 4 for the buffer zone
#define H 23    // 18 for the board, 5 for the buffer zone
// CLASS =======================================================================
class Board
{
    public:
        Board();
        ~Board();
        void update();
        void render();
        void printBoard();
        void syncPosition();
        void setInitMatY(int number);
        int getInitMatY();
        void setInitMatX(int number);
        int getInitMatX();
        bool groundCollision(int* positions);
        bool wallCollisionLeft(int* positions);
        bool wallCollisionRight(int* positions);
        int pivotAtWalls();
        int isPieceI(int* positions);
        bool isRotationSafe(int* positions);
        bool isRotationSafeI(int* positions);
        void fillBoard(int* positions, int type);
        bool areLinesFull();
        int* checkLines();
        void eraseLines(int* lines);
        void usdTest();
        void resetMatrixPositions();
        int getCollisionPoint(int* positions);
        int getLines();
        bool gameOver();
    private:
        int matrixBoard[H][W];
        int tempMatrix[N][N];
        // int lines;
        int initMatX = 0;
        int initMatY = 4;
        int initPosX = 0;
        int initPosY = -32;
        // Load Piece Textures
        SDL_Texture* boardTexture = TextureManager::LoadTexture("img/BlockBoard.png");
        SDL_Texture* blankTexture = TextureManager::LoadTexture("img/BlockAlpha.png");
        SDL_Texture* cyanTexture = TextureManager::LoadTexture("img/BlockCyan.png");
        SDL_Texture* yellowTexture = TextureManager::LoadTexture("img/BlockYellow.png");
        SDL_Texture* redTexture = TextureManager::LoadTexture("img/BlockRed.png");
        SDL_Texture* greenTexture = TextureManager::LoadTexture("img/BlockGreen.png");
        SDL_Texture* purpleTexture = TextureManager::LoadTexture("img/BlockPurple.png");
        SDL_Texture* orangeTexture = TextureManager::LoadTexture("img/BlockOrange.png");
        SDL_Texture* blueTexture = TextureManager::LoadTexture("img/BlockBlue.png");
        // Load Ghost Textures
        SDL_Texture* cyanGhostTexture = TextureManager::LoadTexture("img/BlockCyanGhost.png");
        SDL_Texture* yellowGhostTexture = TextureManager::LoadTexture("img/BlockYellowGhost.png");
        SDL_Texture* redGhostTexture = TextureManager::LoadTexture("img/BlockRedGhost.png");
        SDL_Texture* greenGhostTexture = TextureManager::LoadTexture("img/BlockGreenGhost.png");
        SDL_Texture* purpleGhostTexture = TextureManager::LoadTexture("img/BlockPurpleGhost.png");
        SDL_Texture* orangeGhostTexture = TextureManager::LoadTexture("img/BlockOrangeGhost.png");
        SDL_Texture* blueGhostTexture = TextureManager::LoadTexture("img/BlockBlueGhost.png");
        // Rectangle used for render the board
        SDL_Rect srcRect, destRect;
};
#endif