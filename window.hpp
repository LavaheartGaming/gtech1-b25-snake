#include <SDL2/SDL.h>

class Window{
public:
    SDL_Rect head;

    Window()
    {
        this->fenetre = NULL;
        this->renderer = NULL;
    }
    ~Window()
    {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(fenetre);
        SDL_Quit();  //on quitte la SDL
    }

    void DrawSnake();
    int Init();
    SDL_Renderer* GetRenderer() {return renderer; }
    
private:
    SDL_Window* fenetre;
    SDL_Renderer* renderer;
};