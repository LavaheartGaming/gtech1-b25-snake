#include "Snake.hpp"

Snake::Snake(int startx, int starty, char dir, SDL_Renderer* ren) {
    direction       = dir;
    renderer        = ren;
    alive           = true;
    headTexture     = loadTexture("img/head.png");
    bodyTexture     = loadTexture("img/body.png");
    gameOverTexture = loadTexture("img/gameover.png");
    foodTexture     = loadTexture("img/food.png");
    food = new Segment(0, 0);
    do {
        food->x = rand() % GRID;
        food->y = rand() % GRID;
    }
    while (food->x != startx && food->y != starty);
    addSegment(startx, starty);
}

Snake::~Snake() {
    for (int i = 0; i < body.size(); i++)
        delete body[i];
}

void Snake::addSegment(int x, int y) {
    Segment * seg = new Segment(x, y);
    body.push_back(seg);
}

void Snake::move() {
    if (!alive) return;
    int dx, dy;
    switch (direction) {
        case Snake::NORTH:
            dx = 0;
            dy = -1;
            break;
        case Snake::SOUTH:
            dx = 0;
            dy = 1;
            break;
        case Snake::EAST:
            dx = 1;
            dy = 0;
            break;
        case Snake::WEST:
            dx = -1;
            dy = 0;
            break;
        default:
            break;
    }
    for (int i = body.size() - 1; i > 0; i--) {
        body[i]->x = body[i - 1]->x;
        body[i]->y = body[i - 1]->y;
    }
    Segment * snakeHead = *( body.begin() );
    snakeHead->x += dx;
    snakeHead->y += dy;
}

SDL_Texture* Snake::loadTexture(const char* filename) {
    SDL_Surface * tSurface = IMG_Load(filename);
    if (!tSurface)
        std::cout << "Failed to load image " << filename << ": " << IMG_GetError() << std::endl;
    SDL_Texture * texture  = SDL_CreateTextureFromSurface(renderer, tSurface);
    SDL_FreeSurface(tSurface);
    return texture;
}

void Snake::setDirection(char dir) {
    switch (direction) {
        case Snake::NORTH:
            if (dir == Snake::SOUTH) return;
            if (body.size() > 1 && body[0]->y == body[1]->y) return;
            break;
        case Snake::SOUTH:
            if (dir == Snake::NORTH) return;
            if (body.size() > 1 && body[0]->y == body[1]->y) return;
            break;
        case Snake::EAST:
            if (dir == Snake::WEST) return;
            if (body.size() > 1 && body[0]->x == body[1]->x) return;
            break;
        case Snake::WEST:
            if (dir == Snake::EAST) return;
            if (body.size() > 1 && body[0]->x == body[1]->x) return;
            break;
    }
    direction = dir;
}

void Snake::checkCollision() {
    Segment * head = body[0];
    if (head->x < 0 || head->x > GRID - 1 || head->y < 0 || head->y > GRID - 1) {
        alive = false;
        return;
    }
    for (int i = 1; i < body.size(); i++) {
        if (head->x == body[i]->x && head->y == body[i]->y) {
            alive = false;
            break;
        }
    }
}

void Snake::render() {
    SDL_Rect r;
    r.w = r.h = C_SIZE;
  