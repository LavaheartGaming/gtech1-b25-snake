#include "mainSDLWindow.hpp"
#include <SDL2>

SDL_Window* window;

if(SDL_Init(SDL_INIT_VIDEO) < 0){
    std::cout << "SDL could not be initialized: " << SDL_GetError();
}else{
    std::cout << "SDL video is ready to go \n"
}

window = SDL_CreateWindow("MainSDLWindow",
        0,
        0,
        1920,
        1020,
        SDL_WINDOW_SHOWN);

SDL_Delay(3000)

SDL_DestroyWindow(window);

SDL_Quit();
return 0;