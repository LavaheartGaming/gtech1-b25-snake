#include <iostream>
using namespace std;
bool gameOver;
const int width =20;
const int height =20;
int x, y, fruitx, fruity, score, hiscore; 
enum direction{ STOP = 0, LEFT, RIGHT, UP, DOWN};
direction dir;
void setup()
{
  gameOver=false;
  dir = STOP;
  x = width / 2;
  y = height / 2;
  fruitx = rand() % width;
  fruity = rand() % height;
  score = 0;
}
void draw()
{
    system("clear");
    for (int i = 0; i < width; i++)
    cout << "#";
    cout << endl;

    for(int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        if (j == 0)
          cout << "#";
          else
          cout << " ";

          if (j == width - 1)
          cout << "#";
      }
      cout << endl;
    }

    for(int i = 0; i < width; i++)
    cout << "#";
    cout << endl;
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