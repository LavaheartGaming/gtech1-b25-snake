
#include <iostream>
#include "window.cpp"
#include "body.cpp"
#include "logic.cpp"

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
}  
void logic()
{

}
void draw()
{

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