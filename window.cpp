#include "window.hpp"
 
int Window::Init()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)  // initialisation de la SDL
    {
       printf("Erreur d'initialisation de la SDL : %s", SDL_GetError());
       return EXIT_FAILURE;
    }
 
    this->fenetre = SDL_CreateWindow("Snek",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 1000, 1000, SDL_WINDOW_MINIMIZED);  // Création de la fenêtre
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
    return EXIT_SUCCESS;
}
 
void Window::DrawSnake(){
    SDL_SetRenderDrawColor (renderer,0,255,0,255);
    SDL_RenderFillRect(renderer,&head);
    SDL_RenderPresent(renderer);
    SDL_Delay(20);
}
void Window::DrawFruit(){
     SDL_SetRenderDrawColor (renderer,255,0,0,255);
    SDL_RenderFillRect(renderer,&fruit);
     SDL_RenderPresent(renderer);
     SDL_Delay(20);
}
void Window::DrawSegment(){
    SDL_SetRenderDrawColor (renderer,255,255,255,255);
    SDL_RenderFillRect(renderer,&segment);
     SDL_RenderPresent(renderer);
     SDL_Delay(20);
}
