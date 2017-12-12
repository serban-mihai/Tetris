// PIECE FILE ==================================================================
#include "Piece.h"
// CONSTRUCTORS & DESTRUCTOR ===================================================
Piece::Piece(int model, int next, int x, int y, int xN, int yN)
{
    xPos = x;
    yPos = y;
    xGhost = x;
    yGhost = 0;
    xNext = xN;
    yNext = yN;
    type = model;
    nextType = next;
    switch(model)
    {
        case 1:
            std::cout << "Random Spawn Nr: " << model << " I" << " Color: Cyan" << std::endl;
            matrix[2][1] = 1;   //
            matrix[2][3] = 1;   //  ####
            matrix[2][4] = 1;   //
            pieceTexture = TextureManager::LoadTexture("img/BlockCyan.png");
            ghostTexture = TextureManager::LoadTexture("img/BlockCyanGhost.png");
            break;
        case 2:
            std::cout << "Random Spawn Nr: " << model << " []" << " Color: Yellow" << std::endl;
            matrix[1][2] = 1;   //  ##
            matrix[1][3] = 1;   //  ##
            matrix[2][3] = 1;   //
            pieceTexture = TextureManager::LoadTexture("img/BlockYellow.png");
            ghostTexture = TextureManager::LoadTexture("img/BlockYellowGhost.png");
            break;
        case 3:
            std::cout << "Random Spawn Nr: " << model << " N" << " Color: Red" << std::endl;
            matrix[1][1] = 1;   //  ##
            matrix[1][2] = 1;   //   ##
            matrix[2][3] = 1;   //
            pieceTexture = TextureManager::LoadTexture("img/BlockRed.png");
            ghostTexture = TextureManager::LoadTexture("img/BlockRedGhost.png");
            break;
        case 4:
            std::cout << "Random Spawn Nr: " << model << " N-" << " Color: Green" << std::endl;
            matrix[1][3] = 1;   //   ##
            matrix[1][2] = 1;   //  ##
            matrix[2][1] = 1;   //
            pieceTexture = TextureManager::LoadTexture("img/BlockGreen.png");
            ghostTexture = TextureManager::LoadTexture("img/BlockGreenGhost.png");
            break;
        case 5:
            std::cout << "Random Spawn Nr: " << model << " T" << " Color: Purple" << std::endl;
            matrix[1][2] = 1;   //   #
            matrix[2][1] = 1;   //  ###
            matrix[2][3] = 1;   //
            pieceTexture = TextureManager::LoadTexture("img/BlockPurple.png");
            ghostTexture = TextureManager::LoadTexture("img/BlockPurpleGhost.png");
            break;
        case 6:
            std::cout << "Random Spawn Nr: " << model << " L" << " Color: Orange" << std::endl;
            matrix[1][3] = 1;   //    #
            matrix[2][1] = 1;   //  ###
            matrix[2][3] = 1;   //
            pieceTexture = TextureManager::LoadTexture("img/BlockOrange.png");
            ghostTexture = TextureManager::LoadTexture("img/BlockOrangeGhost.png");
            break;
        case 7:
            std::cout << "Random Spawn Nr: " << model << " L-" << " Color: Blue" << std::endl;
            matrix[1][1] = 1;   //  #
            matrix[2][3] = 1;   //  ###
            matrix[2][1] = 1;   //
            pieceTexture = TextureManager::LoadTexture("img/BlockBlue.png");
            ghostTexture = TextureManager::LoadTexture("img/BlockBlueGhost.png");
            break;
        default:
            break;
    }
    switch(next)
    {
        case 1:
            std::cout << "Random NEXT Spawn Nr: " << next << " I" << " Color: Cyan" << std::endl;
            matrixNext[2][1] = 1;   //
            matrixNext[2][3] = 1;   //  ####
            matrixNext[2][4] = 1;   //
            nextTexture = TextureManager::LoadTexture("img/BlockCyan.png");
            // ghostTexture = TextureManager::LoadTexture("img/BlockCyanGhost.png");
            break;
        case 2:
            std::cout << "Random NEXT Spawn Nr: " << next << " []" << " Color: Yellow" << std::endl;
            matrixNext[1][2] = 1;   //  ##
            matrixNext[1][3] = 1;   //  ##
            matrixNext[2][3] = 1;   //
            nextTexture = TextureManager::LoadTexture("img/BlockYellow.png");
            // ghostTexture = TextureManager::LoadTexture("img/BlockYellowGhost.png");
            break;
        case 3:
            std::cout << "Random NEXT Spawn Nr: " << next << " N" << " Color: Red" << std::endl;
            matrixNext[1][1] = 1;   //  ##
            matrixNext[1][2] = 1;   //   ##
            matrixNext[2][3] = 1;   //
            nextTexture = TextureManager::LoadTexture("img/BlockRed.png");
            // ghostTexture = TextureManager::LoadTexture("img/BlockRedGhost.png");
            break;
        case 4:
            std::cout << "Random NEXT Spawn Nr: " << next << " N-" << " Color: Green" << std::endl;
            matrixNext[1][3] = 1;   //   ##
            matrixNext[1][2] = 1;   //  ##
            matrixNext[2][1] = 1;   //
            nextTexture = TextureManager::LoadTexture("img/BlockGreen.png");
            // ghostTexture = TextureManager::LoadTexture("img/BlockGreenGhost.png");
            break;
        case 5:
            std::cout << "Random NEXT Spawn Nr: " << next << " T" << " Color: Purple" << std::endl;
            matrixNext[1][2] = 1;   //   #
            matrixNext[2][1] = 1;   //  ###
            matrixNext[2][3] = 1;   //
            nextTexture = TextureManager::LoadTexture("img/BlockPurple.png");
            // ghostTexture = TextureManager::LoadTexture("img/BlockPurpleGhost.png");
            break;
        case 6:
            std::cout << "Random NEXT Spawn Nr: " << next << " L" << " Color: Orange" << std::endl;
            matrixNext[1][3] = 1;   //    #
            matrixNext[2][1] = 1;   //  ###
            matrixNext[2][3] = 1;   //
            nextTexture = TextureManager::LoadTexture("img/BlockOrange.png");
            // ghostTexture = TextureManager::LoadTexture("img/BlockOrangeGhost.png");
            break;
        case 7:
            std::cout << "Random NEXT Spawn Nr: " << next << " L-" << " Color: Blue" << std::endl;
            matrixNext[1][1] = 1;   //  #
            matrixNext[2][3] = 1;   //  ###
            matrixNext[2][1] = 1;   //
            nextTexture = TextureManager::LoadTexture("img/BlockBlue.png");
            // ghostTexture = TextureManager::LoadTexture("img/BlockBlueGhost.png");
            break;
        default:
            break;
    }
}
Piece::~Piece()
{
    SDL_DestroyTexture(pieceTexture);
    SDL_DestroyTexture(ghostTexture);
    SDL_DestroyTexture(nextTexture);
}
// METHODS =====================================================================
void Piece::printPiece()
{
    std::cout << "Piece Matrix" << std::endl;   //debug purpouses only
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
    return;
}
void Piece::rotatePiece()
{
    int tempMatrix[N][N];
    // Transpose the original matrix
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            tempMatrix[j][i] = matrix[i][j];
        }
    }
    // Swap columns
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N/2; j++)
        {
            std::swap(tempMatrix[i][j], tempMatrix[i][N - j - 1]);
        }
    }
    // Override original matrix with the clockwise rotated one
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            matrix[i][j] = tempMatrix[i][j];
        }
    }
    std::cout << "Matrix Rotated Clockwise:" << std::endl;
    return;
}
void Piece::movePiece(int speed)
{
    yPos += speed;
    return;
}
void Piece::moveGhost(int speed)
{
    yGhost -= speed;
    return;
}
void Piece::strifePiece(int direction)
{
    if(direction == 1)
    {
        xPos += 32;
        xGhost += 32;
    }
    else if(direction == -1)
    {
        xPos -= 32;
        xGhost -= 32;
    }
    return;
}
int* Piece::getMatrixPoints()
{
    static int pointer[8];
    int arrayIndex = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(matrix[i][j] == 1 || matrix[i][j] == 2)
            {
                pointer[arrayIndex] = i;
                pointer[arrayIndex + 1] = j;
                arrayIndex += 2;
            }
        }
    }
    return pointer;
}
void Piece::printMatrixPoints(int* ptr)
{
    for(int i = 0; i < 8; i++)
    {
        // std::cout << "Matrix Points" << std::endl;
        std::cout << ptr[i] << " ";
    }
    std::cout << "\n";
    return;
}
void Piece::update()
{
    // xPos++;
    // yPos++;
    // Piece Rectangle
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.h = 32;
    destRect.w = 32;
    destRect.x = xPos;
    destRect.y = yPos;
    // Ghost Rectangle
    srcGhost.h = 32;
    srcGhost.w = 32;
    srcGhost.x = 0;
    srcGhost.y = 0;
    destGhost.h = 32;
    destGhost.w = 32;
    destGhost.x = xGhost;
    destGhost.y = yGhost - 96;    //TEST with pixels above
    // next
    srcNext.h = 32;
    srcNext.w = 32;
    srcNext.x = 0;
    srcNext.y = 0;
    destNext.h = 32;
    destNext.w = 32;
    destNext.x = xNext;
    destNext.y = yNext;
    return;

}
void Piece::render()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int type = matrix[i][j];
            switch(type)
            {
                case 0:
                    TextureManager::Draw(blankTexture, srcGhost, destGhost);
                    TextureManager::Draw(blankTexture, srcRect, destRect);
                    break;
                case 1:
                    TextureManager::Draw(ghostTexture, srcGhost, destGhost);
                    TextureManager::Draw(pieceTexture, srcRect, destRect);
                    break;
                case 2:
                    TextureManager::Draw(ghostTexture, srcGhost, destGhost);
                    TextureManager::Draw(pieceTexture, srcRect, destRect);
                    break;
                default:
                    break;
            }
            /*int nextType = matrixNext[i][j];
            switch(nextType)
            {
                case 0:
                    TextureManager::Draw(blankTexture, srcNext, destNext);
                    break;
                case 1:
                    TextureManager::Draw(nextTexture, srcNext, destNext);
                    break;
                case 2:
                    TextureManager::Draw(nextTexture, srcNext, destNext);
                    break;
                default:
                    break;
            }*/
            destRect.x += 32;
            // destNext.x += 32;
            // Ghost
            destGhost.x += 32;
            // destGhost.y = yGhost;
        }
        destRect.x = xPos;
        destRect.y += 32;
        // destNext.x = xNext;
        // destNext.y += 32;
        // Ghost
        destGhost.x = xGhost;
        destGhost.y += 32;
    }
    // std::cout << SDL_GetError() << std::endl;
    return;
}
void Piece::renderNext()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            int nextType = matrixNext[i][j];
            switch(nextType)
            {
                case 0:
                    TextureManager::Draw(blankTexture, srcNext, destNext);
                    break;
                case 1:
                    TextureManager::Draw(nextTexture, srcNext, destNext);
                    break;
                case 2:
                    TextureManager::Draw(nextTexture, srcNext, destNext);
                    break;
                default:
                    break;
            }
            destNext.x += 32;
        }
        destNext.x = xNext;
        destNext.y += 32;
    }
    return;
}
// SETTER & GETTER =============================================================
SDL_Texture* Piece::getPieceTexture()
{
    return pieceTexture;
}
SDL_Texture* Piece::getGhostTexture()
{
    return ghostTexture;
}
int Piece::getType()
{
    return type;
}
int Piece::getNextType()
{
    return nextType;
}
void Piece::setYGhost(int pos)
{
    yGhost = pos * 32;
    return;
}
int Piece::getYGhost()
{
    return yGhost;
}
void Piece::setXGhost(int pos)
{
    xGhost = pos * 32;
    return;
}
int Piece::getXGhost()
{
    return xGhost;
}
void Piece::setXNext(int pos)
{
    xNext = pos;
    return;
}
void Piece::setYNext(int pos)
{
    yNext = pos;
    return;
}