#include <SDL2/SDL.h>
#include <deque>
#include <vector>
#include <algorithm>

int main ()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  auto window = SDL_CreateWindow("Snek", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 1000, 0);
  auto renderer = SDL_CreateRenderer(window, -1, 0);
  SDL_Event  e;

  enum Direction
  {
    DOWN,
    LEFT,
    UP,
    RIGHT
  };

  //Snake head pos
  SDL_Rect head {500,500,50,48};

  //Snake Body
std::deque<SDL_Rect> rq;
int size = 1;

//Apple
std::vector<SDL_Rect> apples;

//Apple on map
for(int i = 0; i < 100; i++)
{
  apples.emplace_back(rand()%100*10, rand()%100*10, 10, 10);
}

bool running = true;
  int dir = 0;

int size = 1;
  while (running)
  {
   while (SDL_PollEvent(&e))
   {
     if(e.type == SDL_QUIT) {running = false; }
     if(e.type == SDL_KEYDOWN) {
       if(e.key.keysym.sym == SDLK_DOWN) {dir = DOWN;}
       if(e.key.keysym.sym == SDLK_UP) {dir = UP;}
       if(e.key.keysym.sym == SDLK_LEFT) {dir = LEFT;}
       if(e.key.keysym.sym == SDLK_RIGHT) {dir = RIGHT;}
       }
     }
   switch (dir)
   {
   case DOWN:
     head.y +=10; break;
    case UP: 
      head.y -=10; break;
    case RIGHT:
      head.x += 10; break;
    case LEFT:
      head.x -= 10; break;
   }
  }

  //Collision with apple
  std::for_each(apples.begin(), apples.end(), [&](auto& apple){
    if(head.x == apple.x && head.y == apple.y)
    {
      size +=50;
      apple.x = -10;
      apple.y = -10;
    }
  });

  //collision with snek's body
  std::for_each(rq.begin(), rq.end(), [&](auto& snake_segment){
    if(head.x == snake_segment.x && head.y == snake_segment.y)
    {
        size = 1;
    }
  });

//Add newest head to snake
  rq.push_front(head);

while(rq.size() > size)
  rq.pop_back();

  //Clear Window
  SDL_SetRenderDrawColor(renderer,0,0,0,255);
  SDL_RenderClear(renderer);

  //Draw Body
  SDL_SetRenderDrawColor (renderer,255,255,255,255);
  std::for_each(rq.begin(), rq.end(), [&](auto&snake_segment){
    SDL_RenderFillRect(renderer, &snake_segment);
  });
  SDL_RenderFillRect(renderer, &head);

  //Display
  SDL_RenderPresent(renderer);
  SDL_Delay(20);
}