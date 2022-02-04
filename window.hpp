#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>

class Window{
public:
    Window();
    ~Window();
    int Init();
    SDL_Renderer* GetRenderer();  
    
private:
    SDL_Window* fenetre;
    SDL_Renderer* renderer;
};


#endif