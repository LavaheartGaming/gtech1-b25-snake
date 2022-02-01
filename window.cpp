#include "window.hpp"

Window::Window(){
    this->fenetre = NULL;
}
int Window::Init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)  // initialisation de la SDL
    {
       printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
       return EXIT_FAILURE;
    }

    this->fenetre = SDL_CreateWindow("Snek",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 600, 600, SDL_WINDOW_RESIZABLE);  // Création de la fenêtre
    if (this->fenetre == NULL)  //gestion des erreurs
    {
        printf("Erreur lors de la creation d'une fenetre : %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    this->renderer = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC); // Création du renderer
    if(this->renderer == NULL)//gestion des erreurs
    {
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
//programme carré
    int  SDL_SetRenderTarget(SDL_Renderer* renderer, SDL_Texture*  texture){
SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,200,100);
SDL_SetRenderDrawColor(renderer,255,0,0,255);
SDL_SetRenderTarget(renderer, texture); //on modifie la texture
SDL_RenderDrawLine(renderer,0,0,200,100);
SDL_SetRenderTarget(renderer, NULL);// Dorénavent, on modifie à nouveau le renderer
SDL_Texture *texture_modifiee = SDL_GetRenderTarget(renderer);
SDL_DestroyTexture(texture);

SDL_Rect position;
position.x = 100;
position.y = 200;
SDL_QueryTexture(texture, NULL, NULL, &position.w, &position.h);
SDL_RenderCopy(renderer, texture, NULL, &position);
SDL_RenderPresent(renderer);
    }
    return EXIT_SUCCESS;
}

SDL_Renderer* Window::GetRenderer(){
    return renderer;
}

Window::~Window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(fenetre);
    SDL_Quit();  //on quitte la SDL
}
