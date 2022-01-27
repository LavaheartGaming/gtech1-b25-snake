#include <iostream>
#include "mainSDLWindow.cpp"
#include <SDL2/SDL.h>

int main()
{
    SDL_init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow(
      "Snek",
      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      1920,
      1080,
      SDL_WINDOW_SHOWN );


  bool quit = false;
  while (!quit)
  {
    SDL_EVENT e;
    while ( SDL_PollEvent( &e ) )
    {
      switch (e.type)
      {
      case SDL_QUIT:
        quit = true;
        break;
      
      default:
        break;
      }
    }
  }

  SDL_DestroyWindow( window );
  SDL_Quit();
}
//cd ~/gtech1-b25-snake/
//g++ [fichier] -lSDL2
