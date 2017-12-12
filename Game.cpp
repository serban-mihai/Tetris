// GAME FILE ===================================================================
#include "Game.h"
#include "Piece.h"
#include "Board.h"
#include "TextureManager.h"
#include "Timer.h"
// RENDERER & EVENT ============================================================
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
// OBJECTS =====================================================================
Piece* randomPiece;
Board* mainBoard;
Timer* scoreBoard;
// CONSTRUCTORS & DESTRUCTOR ===================================================
Game::Game()
{}
Game::~Game()
{}
// METHODS =====================================================================
void Game::init(const char* title, int xP, int yP, int width, int height, bool fullscreen)
{
  int flags = 0;
  if(fullscreen)
  {
    flags = SDL_WINDOW_FULLSCREEN;
  }
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
  {
    std::cout << "System Initialized" << std::endl;
    // WINDOW CREATION
    window = SDL_CreateWindow(title, xP, yP, width, height, flags);
    if(window) // if the window has been created
    {
      std::cout << "Window Created" << std::endl;
    }
    // RENDERER CREATION
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(renderer)  // if the renderer has been created
    {
      std::cout << "Renderer Created" << std::endl;
      SDL_SetRenderDrawColor(renderer, 100, 100, 100, 100); //r, g, b, alpha
    }
    // TTF INIT
    TTF_Init();
    std::cout << "TTF INITIALIZED" << std::endl;
    // BOARD CREATION
    mainBoard = new Board();
    //
    // TIMER DECLARATION
    scoreBoard = new Timer();
    //
    // FIRST PIECE TIMER
    srand((int)time(0));
    randomChoice = rand() % 7 + 1;
    // BACKGROUND SETUP
    backgroundTexture = TextureManager::LoadTexture("img/BackgroundTest8.png");
    srcBackground.x = 0;
    srcBackground.y = 0;
    srcBackground.h = 704;
    srcBackground.w = 800;
    destBackground.x = 0;
    destBackground.y = 0;
    destBackground.h = 704;
    destBackground.w = 800;
    pauseTexture = TextureManager::LoadTexture("img/PauseTest2.png");
    srcPause.x = 0;
    srcPause.y = 0;
    srcPause.h = 704;
    srcPause.w = 800;
    destPause.x = 0;
    destPause.y = 0;
    destPause.h = 704;
    destPause.w = 800;
    howToPlayTexture = TextureManager::LoadTexture("img/HowToPlayTest2.png");
    aboutTexture = TextureManager::LoadTexture("img/About.png");
    running = true;
  }
  else
  { running = false; }
  return;
}
void Game::update() // UPDATE =================================================
{
  counter++;
  // PIECE CREATION
  if(newPiece == true)
  {
    mainBoard->resetMatrixPositions();
    // std::cout << "Init Coordinates: " << mainBoard->getInitMatX() << "x" << mainBoard->getInitMatY() << std::endl;
    // srand((int)time(0));  // for absolute random numbers anytime during runtime
    randomNext = rand() % 7 + 1;
    randomPiece = new Piece(randomChoice, randomNext, 128, -32, 598, 235);   // random number between 1 and 7 draw at 128px X -32px+
    // randomPiece->setYGhost(mainBoard->getCollisionPoint(randomPiece->getMatrixPoints()));
    // SDL_Delay(5000);
    newPiece = false;
    randomChoice = randomNext;
    std::cout << "NEXT RANDOM: " << randomChoice << std::endl;
  }
  // std::cout << counter << std::endl;
  mainBoard->update();
  // mainBoard->printBoard();  // DEBUG ONLY
  randomPiece->update();
  scoreBoard->update();
  // randomPiece->setYGhost(17);
  // std::cout << "Ghost Position Y = " << randomPiece->getYGhost() << std::endl;
  randomPiece->setYGhost(mainBoard->getCollisionPoint(randomPiece->getMatrixPoints()));
  if(randomPiece->getNextType() == 1)
  {
    randomPiece->setXNext(582);
    randomPiece->setYNext(224);
  }
  else if(randomPiece->getNextType() == 2)
  {
    randomPiece->setXNext(582);
    randomPiece->setYNext(242);
  }
  if(mainBoard->isPieceI(randomPiece->getMatrixPoints()) == -1)
  {
    pieceI = -1;
    // randomPiece->setYGhost(-2);
  }
  else if(mainBoard->isPieceI(randomPiece->getMatrixPoints()) == 1)
  {
    pieceI = 1;
    // randomPiece->setYGhost(-2);
  }
  else
  {
    pieceI = 0;
  }
  // randomPiece->printMatrixPoints(randomPiece->getMatrixPoints());
  if(counter == speed)
  {
    scoreBoard->setScore(1);
    std::cout << "Score = " << scoreBoard->getScore() << std::endl;
    if(mainBoard->gameOver())
    {
      std::cout << "GAME OVER!!!" << std::endl;
      SDL_Delay(5000);
    }
    else
    {
      std::cout << "\nNEW UPDATE\n" << std::endl;
      // put here all instructions for movement and delete rotation
      // mainBoard->printBoard();
      // mainBoard->syncPosition();
      // randomPiece->printMatrixPoints(randomPiece->getMatrixPoints());
      if(!mainBoard->groundCollision(randomPiece->getMatrixPoints()))
      {
        randomPiece->movePiece(32);
        mainBoard->setInitMatX(1);
      }
      else
      {
        randomPiece->movePiece(0);
        mainBoard->setInitMatX(0);
        mainBoard->fillBoard(randomPiece->getMatrixPoints(), randomPiece->getType());
        // randomPiece->setYGhost(0);
        // delete randomPiece;    // With delete it returns segmentetion fault after collision
        newPiece = true;
        counter = 0;
        return;
      }
      counter = 0;
    }
  }
  // std::cout << "LINES FULL = " << mainBoard->getLines() << std::endl;
  if(mainBoard->areLinesFull())
  {
    mainBoard->eraseLines(mainBoard->checkLines());
    scoreBoard->setLines(1);
    scoreBoard->setScore(100);
  }
  if(scoreBoard->getScore() >= 1000)
  {
    std::cout << "Speed = " << speed << std::endl;
    speed = 50;
    return;
  }
  else if(scoreBoard->getScore() >= 2000 && scoreBoard->getScore() < 3000)
  {
    std::cout << "Speed = " << speed << std::endl;
    speed = 40;
    return;
  }
  else if(scoreBoard->getScore() >= 3000 && scoreBoard->getScore() < 4000)
  {
    std::cout << "Speed = " << speed << std::endl;
    speed = 30;
    return;
  }
  else if(scoreBoard->getScore() >= 4000 && scoreBoard->getScore() < 5000)
  {
    std::cout << "Speed = " << speed << std::endl;
    speed = 20;
    return;
  }
  else if(scoreBoard->getScore() > 5000)
  {
    std::cout << "Speed = " << speed << std::endl;
    speed = 10;
    return;
  }
  // randomPiece->printPiece();
  // mainBoard->printBoard();
  return;
}
void Game::render() // RENDER =================================================
{
  SDL_RenderClear(renderer); // clear previous render
  // things to render:
  mainBoard->render();
  randomPiece->render();
  TextureManager::Draw(backgroundTexture, srcBackground, destBackground);
  randomPiece->renderNext();
  scoreBoard->render();
  // SDL_Delay(500);
  SDL_RenderPresent(renderer);
  return;
}
void Game::renderPause()
{
  // q = false;
  // a = false;
  std::cout << "MENU is " << menu << std::endl;
  SDL_RenderClear(renderer); // clear previous render
  // things to render:
  // mainBoard->render();
  // randomPiece->render();
  TextureManager::Draw(backgroundTexture, srcBackground, destBackground);
  switch(menu)
  {
    case 0:
      TextureManager::Draw(pauseTexture, srcPause, destPause);
      break;
    case 1:
      TextureManager::Draw(howToPlayTexture, srcPause, destPause);
      break;
    case 2:
      TextureManager::Draw(aboutTexture, srcPause, destPause);
      break;
    default:
      break;
  }
  randomPiece->renderNext();
  scoreBoard->render();
  // SDL_Delay(500);
  SDL_RenderPresent(renderer);
  return;
}
void Game::events() // EVENTS =================================================
{
  while(SDL_PollEvent(&event) != 0)
  {
    if(event.type == SDL_QUIT)
    {
      paused = true;
      running = false;
    }
    else if(event.type == SDL_KEYDOWN)
    {
      switch(event.key.keysym.sym)
      {
        case SDLK_UP:     // UP KEY =================================
          if(!mainBoard->isRotationSafe(randomPiece->getMatrixPoints()) || paused == true)
          {
            break;
          }
          else
          {
            if(mainBoard->pivotAtWalls() == -1)
            {
              if(pieceI == -1)
              {
                if(!mainBoard->isRotationSafeI(randomPiece->getMatrixPoints()))
                {
                  break;
                }
                else
                {
                  mainBoard->setInitMatY(1);
                  randomPiece->strifePiece(1);
                  // randomPiece->setYGhost(2);
                }
              }
              std::cout << "PIECE MOVED RIGHT" << std::endl;
              mainBoard->setInitMatY(1);
              randomPiece->strifePiece(1);
              randomPiece->rotatePiece();
            }
            else if(mainBoard->pivotAtWalls() == 1)
            {
              if(pieceI == 1)
              {
                if(!mainBoard->isRotationSafeI(randomPiece->getMatrixPoints()))
                {
                  break;
                }
                else
                {
                  mainBoard->setInitMatY(-1);
                  randomPiece->strifePiece(-1);
                  // randomPiece->setYGhost(-2);
                }
              }
              std::cout << "PIECE MOVED LEFT" << std::endl;
              randomPiece->rotatePiece();
              mainBoard->setInitMatY(-1);
              randomPiece->strifePiece(-1);
            }
            else if(mainBoard->pivotAtWalls() == 3)
            {
              std::cout << "CAN'T ROTATE PIECE" << std::endl;
              break;
            }
            else
            {
              // rotationGhost = 0;
              randomPiece->rotatePiece();
            }
            // randomPiece->setYGhost(mainBoard->getCollisionPoint(randomPiece->getMatrixPoints()));
            break;
          }
        case SDLK_DOWN:   // DOWN KEY ===============================
          if(mainBoard->groundCollision(randomPiece->getMatrixPoints()) || paused == true)
          {
            randomPiece->movePiece(0);
            mainBoard->setInitMatX(0);
          }
          else
          {
            randomPiece->movePiece(32);
            mainBoard->setInitMatX(1);
            scoreBoard->setScore(2);
          }
          break;
        case SDLK_LEFT:   // LEFT KEY ===============================
          if(paused == true)
          {
            std::cout << "Can't move to the left, Game is paused" << std::endl;
            break;
          }
          else if(!mainBoard->wallCollisionLeft(randomPiece->getMatrixPoints()))
          {
            mainBoard->setInitMatY(-1);
            randomPiece->strifePiece(-1);
            randomPiece->setYGhost(mainBoard->getCollisionPoint(randomPiece->getMatrixPoints()));
          }
          break;
        case SDLK_RIGHT:   // RIGHT KEY =============================
          if(paused == true)
          {
            std::cout << "Can't move to the left, Game is paused" << std::endl;
            break;
          }
          else if(!mainBoard->wallCollisionRight(randomPiece->getMatrixPoints()))
          {
            mainBoard->setInitMatY(1);
            randomPiece->strifePiece(1);
            randomPiece->setYGhost(mainBoard->getCollisionPoint(randomPiece->getMatrixPoints()));
          }
          break;
        case SDLK_ESCAPE:
          std::cout << "ESC Pressed" << std::endl;
          if(paused == false)
          {
            paused = true;
          }
          else if(paused == true)
          {
            paused = false;
          }
        case SDLK_q:
          std::cout << "MENU Q" << std::endl;
          if(menu != 1)
          {
            menu = 1;
          }
          else
          {
            menu = 0;
          }
          break;
        case SDLK_a:
          std::cout << "MENU A" << std::endl;
          if(menu != 2)
          {
            menu = 2;
          }
          else
          {
            menu = 0;
          }
          break;
        default:
          break;
      }
    }
  }
  return;
}
void Game::clean() // CLEAN ===================================================
{
  SDL_DestroyWindow(window);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
  std::cout << "Game cleaned" << std::endl;
  return;
}
bool Game::isRunning()
{ return running; }
bool Game::isPaused()
{ return paused;  }