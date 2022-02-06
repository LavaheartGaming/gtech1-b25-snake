#include "window.cpp"
#include "player.cpp"
#include <iostream>

using namespace std;
bool gameOver;
const int width =20;
const int height =20;
int x, y, fruitx, fruity, score, hiscore; 
enum direction{ STOP = 0, LEFT, RIGHT, UP, DOWN};
direction dir;

Window *init() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;
    Window *fenetre = new Window();
    fenetre->Init();
    SDL_Rect head {500,500,10,10};
}

void input()
{
    SDL_Event e;
    while ( SDL_PollEvent( &e ) )
    {
      switch (e.type)
      {
      case SDL_QUIT:
        gameOver = true;
        break;
      
      }
    }
    while(SDL_PollEvent(&e)){
      if(e.type == SDL_KEYDOWN){
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
}

switch(dir)
{
  case DOWN:
    y += 10; break;
  case UP:
    y -= 10; break;
  case LEFT:
    x += 10; break;
  case RIGHT:
    x -= 10; break;
}
void logic()
{

}
void draw(){
SDL_SetRenderDrawColor (renderer,255,255,255,255);
SDL_RenderFillRect(renderer,&head);
SDL_RenderPresent(renderer);
SDL_Delay(20);
}
main(void)
{
 Window *win = init();
 while(!gameOver)
 {
   draw();
   input();
   logic();
   SDL_Delay(20);
 }
  delete win;
  return 0;
}
//g++ snek.cpp -lSDL2
//cd ~/gtech1-b25-snake/