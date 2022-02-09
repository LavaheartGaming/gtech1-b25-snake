#include "game.hpp"

Game::Game() {
    window   = nullptr;
    renderer = nullptr;
    running  = false;
    snake    = nullptr;
}

Game::~Game() {
    delete snake;
}

void Game::init(const char* title, int posx, int posy, int width, int height, bool maximised) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL2 initialisation failed: " << SDL_GetError() << std::endl;
        return;
    }
    window = SDL_CreateWindow(title, posx, posy, width, height, maximised == true ? SDL_WINDOW_MAXIMIZED : NULL);
    if (window == NULL) {
        std::cout << "Window creation failed: " << SDL_GetError() << std::endl;
        return;
    }
    renderer = SDL_CreateRenderer(window, -1, NULL);
    if (renderer == NULL) {
        std::cout << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer, 170, 170, 170, 255);
    running = true;
    snake = new Snake(GRID / 2, GRID / 2, rand() % 4, renderer);
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_KEYDOWN) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    snake->setDirection(Snake::NORTH);
                    break;
                case SDLK_DOWN:
                    snake->setDirection(Snake::SOUTH);
                    break;
                case SDLK_LEFT:
                    snake->setDirection(Snake::WEST);
                    break;
                case SDLK_RIGHT:
                    snake->setDirection(Snake::EAST);
                    break;
                case SDLK_RETURN:
                    if (!snake->isAlive()) running = false;
                    break;
                default:
                    break;
            }
        }
        else if (event.type == SDL_QUIT) running = false;
    }
}
