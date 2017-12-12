// PIECE FILE ==================================================================
#include "Board.h"
#include <algorithm>
// CONSTRUCTORS & DESTRUCTOR ===================================================
Board::Board()
{
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            if(i < 3 && j > 1 && j < 12)
            {
                matrixBoard[i][j] = 44;
            }
            else if(j < 2 || j > 11)
            {
                matrixBoard[i][j] = 88;
            }
            else if(i > 20 && j > 1 && j < 12)
            {
                matrixBoard[i][j] = 55;
            }
            else
            {
                matrixBoard[i][j] = 0;
            }
        }
    }
    // DELETE ABOVE AFTER SOLVING BUG
    // matrixBoard[18][2] = 1;
    // matrixBoard[18][7] = 2;
    // matrixBoard[18][7] = 2;

}
Board::~Board()
{}
// METHODS =====================================================================
void Board::printBoard()
{
    std::cout << "Board Matrix:" << std::endl;
    for(int i = 0; i < H; i++)
    {
        std::cout << "L" << i << "\t";
        for(int j = 0; j < W; j++)
        {
            if(matrixBoard[i][j] >= 0 && matrixBoard[i][j] <= 7)
            {
                std::cout << matrixBoard[i][j] << "  ";
            }
            else
            {
                std::cout << matrixBoard[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
    return;
}
void Board::syncPosition()
{
    std::cout << "Piece Matrix on Board" << std::endl;
    for(int i = initMatX; i < N + initMatX; i++)
    {
        for(int j = initMatY; j < N + initMatY; j++)
        {
            if(matrixBoard[i][j] >= 0 && matrixBoard[i][j] <= 7)
            {
                std::cout << matrixBoard[i][j] << "  ";
            }
            else
            {
                std::cout << matrixBoard[i][j] << " ";
            }
        }
        std::cout << "\n";
    }
    return;
}
int Board::getCollisionPoint(int* positions)
{
    // std::cout << "\nTEST" << std::endl;
    int counter = 0;
    // int possibleValues[4];  // maximum number of blocks and collisions
    // int min = 20;
    for(int i = 3; i < H - 2; i++)
    {
        counter++;
        for(int j = initMatY; j < N + initMatY; j++)
        {
            /*std::cout << "\nCounter = " << counter << std::endl;
            std::cout << "I = " << i << std::endl;
            std::cout << "Position I of\t x = " << positions[0] + counter << " y = " << positions[1] <<  std::endl;
            std::cout << "Position I of\t x = " << positions[2] + counter << " y = " << positions[3] <<  std::endl;
            std::cout << "Position I of\t x = " << positions[4] + counter << " y = " << positions[4] <<  std::endl;
            std::cout << "Position I of\t x = " << positions[6] + counter << " y = " << positions[7] <<  std::endl;*/
            /*possibleValues[0] = positions[0] + counter;
            possibleValues[1] = positions[2] + counter;
            possibleValues[2] = positions[4] + counter;
            possibleValues[3] = positions[6] + counter;
            for(int c = 0; c < 4; c++)
            {
                if(possibleValues[c] < min)
                {
                    min = possibleValues[c];
                }
            }*/
            // std::cout << matrixBoard[i][j] << " ";
            if((i == positions[0] + counter && j == positions[1] + initMatY) || (i == positions[2] + counter && j == positions[3] + initMatY) || (i == positions[4] + counter && j == positions[5] + initMatY) || (i == positions[6] + counter && j == positions[7] + initMatY))
            {
                if(matrixBoard[i + 1][j] == 55 || (matrixBoard[i + 1][j] >= 1 && matrixBoard[i + 1][j] <= 7))
                {
                    // std::cout << "GHOST BOARD DETECTED!!!\t" << "on I " << i << std::endl;
                    // std::cout << "Most correct piece for collision:  " << min << std::endl;
                    return i;
                }
            }
        }
        // std::cout << "\n";
    }
}
bool Board::groundCollision(int* positions)
{
    for(int i = initMatX; i < N + initMatX; i++)
    {
        for(int j = initMatY; j < N + initMatY; j++)
        {
            // std::cout << "Position on Board " << matrixBoard[i + 1][j] << std::endl;
            // std::cout << "Array Index " << arrayIndex << std::endl;
            // std::cout << "Analizing position " << positions[arrayIndex] << "x" << positions[arrayIndex + 1] << std::endl;
            if((i == positions[0] + initMatX && j == positions[1] + initMatY) || (i == positions[2] + initMatX && j == positions[3] + initMatY) || (i == positions[4] + initMatX && j == positions[5] + initMatY) || (i == positions[6] + initMatX && j == positions[7] + initMatY))
            {
                // std::cout << "Position FOUND " << std::endl;
                if(matrixBoard[i + 1][j] == 55 || (matrixBoard[i + 1][j] >= 1 && matrixBoard[i + 1][j] <= 7))
                {
                    std::cout << "COLLISION OR PIECE GROUND DETECTED!!!\t" << "Position " << i << "x" << j << std::endl;
                    return true;
                }
                // arrayIndex += 2;
            }
        }
    }
    return false;
}
bool Board::wallCollisionLeft(int* positions)
{
    for(int i = initMatX; i < N + initMatX; i++)
    {
        for(int j = initMatY; j < N + initMatY; j++)
        {
            // std::cout << "Position on Board " << matrixBoard[i + 1][j] << std::endl;
            // std::cout << "Array Index " << arrayIndex << std::endl;
            // std::cout << "Analizing position " << positions[arrayIndex] << "x" << positions[arrayIndex + 1] << std::endl;
            if((i == positions[0] + initMatX && j == positions[1] + initMatY) || (i == positions[2] + initMatX && j == positions[3] + initMatY) || (i == positions[4] + initMatX && j == positions[5] + initMatY) || (i == positions[6] + initMatX && j == positions[7] + initMatY))
            {
                // std::cout << "Position FOUND " << std::endl;
                if(matrixBoard[i][j - 1] == 88 || (matrixBoard[i][j - 1] >= 1 && matrixBoard[i][j - 1] <= 7))
                {
                    std::cout << "COLLISION LEFT WALL DETECTED!!!\t" << "Position " << i << "x" << j << std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}
bool Board::wallCollisionRight(int* positions)
{
    for(int i = initMatX; i < N + initMatX; i++)
    {
        for(int j = initMatY; j < N + initMatY; j++)
        {
            // std::cout << "Position on Board " << matrixBoard[i + 1][j] << std::endl;
            // std::cout << "Array Index " << arrayIndex << std::endl;
            // std::cout << "Analizing position " << positions[arrayIndex] << "x" << positions[arrayIndex + 1] << std::endl;
            if((i == positions[0] + initMatX && j == positions[1] + initMatY) || (i == positions[2] + initMatX && j == positions[3] + initMatY) || (i == positions[4] + initMatX && j == positions[5] + initMatY) || (i == positions[6] + initMatX && j == positions[7] + initMatY))
            {
                // std::cout << "Position FOUND " << std::endl;
                if(matrixBoard[i][j + 1] == 88 || (matrixBoard[i][j + 1] >= 1 && matrixBoard[i][j + 1] <= 7))
                {
                    std::cout << "COLLISION RIGHT WALL DETECTED!!!\t" << "Position " << i << "x" << j << std::endl;
                    return true;
                }
            }
        }
    }
    return false;
}
int Board::pivotAtWalls()
{
    for(int i = initMatX; i < N + initMatX; i++)
    {
        for(int j = initMatY; j < N + initMatY; j++)
        {
            if(matrixBoard[initMatX + 2][initMatY + 2 - 1] == 88 || (matrixBoard[initMatX + 2][initMatY + 2 - 1] >= 1 && matrixBoard[initMatX + 2][initMatY + 2 - 1] <= 7))
            {
                // std::cout << "Pivot = " << matrixBoard[i + 2][j + 2] << std::endl;
                // std::cout << "Pivot - 1 = " << matrixBoard[i + 2][j + 2 - 1] << std::endl;
                return -1;
            }
            else if(matrixBoard[initMatX + 2][initMatY + 2 - 2] == 88 || (matrixBoard[initMatX + 2][initMatY + 2 - 2] >= 1 && matrixBoard[initMatX + 2][initMatY + 2 - 2] <= 7))
            {
                return -2;
            }
            else if(matrixBoard[initMatX + 2][initMatY + 2 + 1] == 88 || (matrixBoard[initMatX + 2][initMatY + 2 + 1] >= 1 && matrixBoard[initMatX + 2][initMatY + 2 + 1] <= 7))
            {
                // std::cout << "Pivot = " << matrixBoard[i + 2][j + 2] << std::endl;
                // std::cout << "Pivot + 1 = " << matrixBoard[i + 2][j + 2 + 1] << std::endl;
                return 1;
            }
            else if(matrixBoard[initMatX + 2][initMatY + 2 + 2] == 88 || (matrixBoard[initMatX + 2][initMatY + 2 + 2] >= 1 && matrixBoard[initMatX + 2][initMatY + 2 + 2] <= 7))
            {
                return 2;
            }
            else if((matrixBoard[initMatX + 2][initMatY + 2 - 1] == 88 || (matrixBoard[initMatX + 2][initMatY + 2 - 1] >= 1 && matrixBoard[initMatX + 2][initMatY + 2 - 1] <= 7)) && (matrixBoard[initMatX + 2][initMatY + 2 + 1] == 88 || (matrixBoard[initMatX + 2][initMatY + 2 + 1] >= 1 && matrixBoard[initMatX + 2][initMatY + 2 + 1] <= 7)))
            {
                return 3;
            }
        }
    }
    return 0;
}
int Board::isPieceI(int* positions)
{
    for(int i = 0; i < 8; i += 2)
    {
        if(positions[i] == 4)
        {
            // std::cout << "PIECE I TO THE LEFT" << std::endl;
            return -1;
        }
        else if(positions[i] == 0)
        {
            // std::cout << "PIECE I TO THE RIGHT" << std::endl;
            return 1;
        }
    }
    return 0;
}
bool Board::isRotationSafe(int* positions)
{
    for(int i = initMatX; i < N + initMatX; i++)
    {
        for(int j = initMatY; j < N + initMatY; j++)
        {
            if((i == positions[0] + initMatX && j == positions[1] + initMatY) || (i == positions[2] + initMatX && j == positions[3] + initMatY) || (i == positions[4] + initMatX && j == positions[5] + initMatY) || (i == positions[6] + initMatX && j == positions[7] + initMatY))
            {
                if((matrixBoard[i][j - 1] == 88 || (matrixBoard[i][j - 1] >= 1 && matrixBoard[i][j - 1] <= 7)) && (matrixBoard[i][j + 1] == 88 || (matrixBoard[i][j + 1] >= 1 && matrixBoard[i][j + 1] <= 7)))
                {
                    return false;
                }
                else if((matrixBoard[i][j - 1] == 88 || (matrixBoard[i][j - 1] >= 1 && matrixBoard[i][j - 1] <= 7)) && (matrixBoard[i][j + 2] == 88 || (matrixBoard[i][j + 2] == 1 && matrixBoard[i][j + 2] <= 7)))
                {
                    return false;
                }
                else if((matrixBoard[i][j - 2] == 88 || (matrixBoard[i][j - 2] >= 1 && matrixBoard[i][j - 2] <= 7)) && (matrixBoard[i][j + 1] == 88 || (matrixBoard[i][j + 1] >= 1 && matrixBoard[i][j + 1] <= 7)))
                {
                    return false;
                }
            }
        }
    }
    return true;
}
bool Board::isRotationSafeI(int* positions)
{
    for(int i = initMatX; i < N + initMatX; i++)
    {
        for(int j = initMatY; j < N + initMatY; j++)
        {
            if((i == positions[0] + initMatX && j == positions[1] + initMatY) || (i == positions[2] + initMatX && j == positions[3] + initMatY) || (i == positions[4] + initMatX && j == positions[5] + initMatY) || (i == positions[6] + initMatX && j == positions[7] + initMatY))
            {
                if((matrixBoard[i][j - 1] == 88 || (matrixBoard[i][j - 1] >= 1 && matrixBoard[i][j - 1] <= 7)) && (matrixBoard[i][j + 3] == 88 || (matrixBoard[i][j + 3] >= 1 && matrixBoard[i][j + 3] <= 7)))
                {
                    return false;
                }
                else if((matrixBoard[i][j - 2] == 88 || (matrixBoard[i][j - 2] >= 1 && matrixBoard[i][j - 2] <= 7)) && (matrixBoard[i][j + 1] == 88 || (matrixBoard[i][j + 1] >= 1 && matrixBoard[i][j + 1] <= 7)))
                {
                    return false;
                }
                else if((matrixBoard[i][j + 2] == 88 || (matrixBoard[i][j + 2] >= 1 && matrixBoard[i][j + 2] <= 7)) && (matrixBoard[i][j - 1] == 88 || (matrixBoard[i][j - 1] >= 1 && matrixBoard[i][j - 1] <= 7)))
                {
                    return false;
                }
                else if((matrixBoard[i][j - 3] == 88 || (matrixBoard[i][j - 3] >= 1 && matrixBoard[i][j - 3] <= 7)) && (matrixBoard[i][j + 1] == 88 || (matrixBoard[i][j + 1] >= 1 && matrixBoard[i][j + 1] <= 7)))
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void Board::fillBoard(int* positions, int type)
{
    for(int i = initMatX; i < N + initMatX; i++)
    {
        for(int j = initMatY; j < N + initMatY; j++)
        {
            matrixBoard[positions[0] + initMatX][positions[1] + initMatY] = type;
            matrixBoard[positions[2] + initMatX][positions[3] + initMatY] = type;
            matrixBoard[positions[4] + initMatX][positions[5] + initMatY] = type;
            matrixBoard[positions[6] + initMatX][positions[7] + initMatY] = type;
        }
    }
    return;
}
int* Board::checkLines()
{
    static int index[4];   // max rows that can be deleted in one
    int n = 0;
    for(int i = 3; i < H - 2; i++)
    {
        for(int j = 2; j < W - 2; j++)
        {
            if(matrixBoard[i][j] == 0)
            {
                break;
            }
            else
            {
                if(j == 11)
                {
                    index[n] = i;
                    // lines++;
                    n++;
                }
            }
        }
    }
    std::cout << "Vector Elements:" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        std::cout << index[i] << " ";
    }
    std::cout << "\n";
    return index;
}
int Board::getLines()
{
    int n = 0;
    for(int i = 3; i < H - 2; i++)
    {
        for(int j = 2; j < W - 2; j++)
        {
            if(matrixBoard[i][j] == 0)
            {
                break;
            }
            else
            {
                if(j == 11)
                {
                    n++;
                }
            }
        }
    }
    return n;
}
void Board::eraseLines(int* lines)
{
    int n = 0;
    bool fall = false;
    for(int i = 3; i < H - 2; i++)
    {
        for(int j = 2; j < W - 2; j++)
        {
            // std::cout << "I = " << i << std::endl;
            if(lines[n] == 0)
            {
                break;
            }
            else
            {
                if(lines[n] == i)
                {
                    // std::cout << "N = " << lines[n] << std::endl;
                    // std::cout << "THIS SHIT WORKS" << std::endl;
                    matrixBoard[i][j] = 0;
                    if(j == 11)
                    {
                        // lines++;
                        SDL_Delay(500);
                        fall = true;
                    }
                }
                if(fall == true)
                {
                    for(int tempI = i; tempI > 3; tempI--)
                    {
                        for(int tempJ = 2; tempJ < W - 2; tempJ++)
                        {
                            // std::cout << matrixBoard[tempI][tempJ] << " ";
                            matrixBoard[tempI][tempJ] = matrixBoard[tempI - 1][tempJ];
                            // matrixBoard[tempI][tempJ] = 0;
                        }
                        // std::cout << "\n";
                    }
                    fall = false;
                }
            }
            // n++;
        }
        // std::cout << "Lines: " << lines[n] << " Erased" << std::endl;
    }
    return;
}
bool Board::areLinesFull()
{
    for(int i = 3; i < H - 2; i++)
    {
        for(int j = 2; j < W - 2; j++)
        {
            if(matrixBoard[i][j] == 0)
            {
                break;
            }
            else
            {
                if(j == 11)
                {
                    return true;
                }
            }
        }
    }
    return false;
}
void Board::resetMatrixPositions()
{
    initMatX = 0;
    initMatY = 4;
    return;
}
bool Board::gameOver()
{
    for(int j = 2; j < W - 2; j++)
    {
        if(matrixBoard[1][j] != 44 || matrixBoard[2][j] != 44)
        {
            return true;
        }
    }
    return false;
}
// DELETE ABOVE USDTEST LATER
void Board::usdTest()
{
    std::cout << "Upside Down Board" << std::endl;
    for(int i = H - 3; i > 2; i--)
    {
        for(int j = 2; j < W - 2; j++)
        {
            std::cout << matrixBoard[i][j] << " ";
        }
        std::cout << "\n";
    }
    return;
}
void Board::update()
{
    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;
    destRect.h = 32;
    destRect.w = 32;
    destRect.x = initPosX;
    destRect.y = initPosY;
    return;
}
void Board::render()
{
    for(int i = 0; i < H; i++)
    {
        for(int j = 0; j < W; j++)
        {
            int type = matrixBoard[i][j];
            switch(type)
            {
                case 0:
                    TextureManager::Draw(boardTexture, srcRect, destRect);
                    break;
                case 1:
                    TextureManager::Draw(cyanTexture, srcRect, destRect);
                    break;
                case 2:
                    TextureManager::Draw(yellowTexture, srcRect, destRect);
                    break;
                case 3:
                    TextureManager::Draw(redTexture, srcRect, destRect);
                    break;
                case 4:
                    TextureManager::Draw(greenTexture, srcRect, destRect);
                    break;
                case 5:
                    TextureManager::Draw(purpleTexture, srcRect, destRect);
                    break;
                case 6:
                    TextureManager::Draw(orangeTexture, srcRect, destRect);
                    break;
                case 7:
                    TextureManager::Draw(blueTexture, srcRect, destRect);
                    break;
                case 88:
                    TextureManager::Draw(blankTexture, srcRect, destRect);
                    break;
                default:
                    break;
            }
            destRect.x += 32;
        }
        destRect.x = initPosX;
        destRect.y += 32;
    }
    // std::cout << SDL_GetError() << std::endl;
    return;
}
// SETTER & GETTER =============================================================
void Board::setInitMatY(int number)
{
    initMatY += number;
    return;
}
int Board::getInitMatY()
{
    return initMatY;
}
void Board::setInitMatX(int number)
{
    initMatX += number;
    return;
}
int Board::getInitMatX()
{
    return initMatX;
}