#include <iostream>
using namespace std;
bool gameOver;
const int width =20;
const int heigt =20;
int x, y, fruitx, fruity, score, hiscore; 
enum direction{ STOP = 0, LEFT, RIGHT, UP, DOWN};
direction dir;
void setup()
{
  gameOver=false
  dir = STOP;
}
void draw()
{

}
void input()
{

}
void logic()
{

}
int main()
{
 setup();
 while(!gameOver)
 {
   draw();
   input();
   logic();  
 }
    return 0;
}