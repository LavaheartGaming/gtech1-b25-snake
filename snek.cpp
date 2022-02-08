#include "window.hpp"
#include "player.hpp"
#include <iostream>

using namespace std;
const int frameRate  = 5;
const int frameDelay = 1000 / frameRate;
Uint32 frameTime;
int frameElapsedTime;
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score, hiscore;
enum direction
{
  STOP = 0,
  LEFT,
  RIGHT,
  UP,
  DOWN
};
direction dir;

Window *wdw = NULL;

Window *init()
{
  gameOver = false;
  frameTime = SDL_GetTicks();
  frameElapsedTime = SDL_GetTicks() - frameTime;
  if (frameDelay > frameElapsedTime)
    SDL_Delay(frameDelay - frameElapsedTime);
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitx = rand() % width;
  fruity = rand() % height;
  score = 0;
  Window *fenetre = new Window();
  fenetre->Init();
  return fenetre;
}

void input()
{
  SDL_Event e;
  while (SDL_PollEvent(&e))
  {
    switch (e.type)
    {
    case SDL_QUIT:
      gameOver = true;
      break;
    }
  }
  while (SDL_PollEvent(&e))
  {
    if (e.type == SDL_KEYDOWN)
    {
      if (e.key.keysym.sym == SDLK_DOWN)
      {
        dir = DOWN;
      }
      if (e.key.keysym.sym == SDLK_UP)
      {
        dir = UP;
      }
      if (e.key.keysym.sym == SDLK_RIGHT)
      {
        dir = RIGHT;
      }
      if (e.key.keysym.sym == SDLK_LEFT)
      {
        dir = LEFT;
      }
    }
  }
  switch (dir)
  {
  case DOWN:
    y += 10;
    break;
  case UP:
    y -= 10;
    break;
  case LEFT:
    x += 10;
    break;
  case RIGHT:
    x -= 10;
    break;
  }
}
void logic()
{
}
void draw()
{
  wdw->DrawSnake();
}

main(void)
{
  wdw = init();
  wdw->head = {500, 500, 50, 48};
  while (!gameOver)
  {
    draw();
    input();
    logic();
    SDL_Delay(20);
  }
  if (wdw != NULL) delete wdw;
  return 0;
}
// g++ snek.cpp window.cpp player.cpp -lSDL2 -o snek && ./snek
// cd ~/gtech1-b25-snake/