
#include <iostream>
#include "window.hpp"

using namespace std;
bool gameOver;
const int width =20;
const int height =20;
int x, y, fruitx, fruity, score, hiscore; 
enum direction{ STOP = 0, LEFT, RIGHT, UP, DOWN};
direction dir;

Window *init() {
    Window *fenetre = new Window();
    fenetre->Init();
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitx = rand() % width;
    fruity = rand() % height;
    score = 0;

}

void input()
{
    
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
  if (win != NULL) delete win;
  return 0;
}
