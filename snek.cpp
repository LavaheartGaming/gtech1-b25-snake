#include "window.hpp"
#include "player.hpp"
#include <iostream>
#include <ctime>
 
using namespace std;
const int frameRate  = 5;
const int frameDelay = 1000 / frameRate;
Uint32 frameTime;
int frameElapsedTime;
bool gameOver;
bool eatFruit;
const int width = 20;
const int height = 20;
int x, y, fruitx, fruity, score, hiscore, randy, randx;
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
     srand((unsigned) time(0));
  randy = (rand() % 19) + 1;
  fruity = randy * 20;
  cout << fruity << endl;
  randx = (rand() % 19) + 1;
  fruitx = randx * 20;
  cout << fruitx << endl;
  eatFruit = false;
  gameOver = false;
  dir = STOP;
  x = 500;
  y = 500;
  score = 0;
  Window *fenetre = new Window();
  fenetre->Init();
  return fenetre;
  void tpfruit();
}
 
 void framerate(){
   frameTime = SDL_GetTicks();
  frameElapsedTime = SDL_GetTicks() - frameTime;
  if (frameDelay > frameElapsedTime)
    SDL_Delay(frameDelay - frameElapsedTime);
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
void draw()
{
  wdw->DrawSnake();
  wdw->DrawFruit();
  wdw->DrawSegment();
 
}
void tpfruit(){

  eatFruit = false;
}
 
main(void)
{
  wdw = init();
  wdw->head = {x, y, 50, 48};
  wdw->fruit = {fruitx, fruity, 50, 48};
  wdw->segment = {x-50, y, 50, 48};
  while (!gameOver)
  {
    if (eatFruit = true)
    {
      tpfruit();
    }
    draw();
    input();
    framerate();
    SDL_Delay(20);
  }
  if (wdw != NULL) delete wdw;
  return 0;
}
// g++ snek.cpp window.cpp player.cpp -lSDL2 -o snek && ./snek
// cd ~/gtech1-b25-snake/
