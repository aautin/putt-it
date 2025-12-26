#include <iostream>
#include <vector>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define PRIMARY_DISPLAY_INDEX 0

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    int imgFlags = IMG_INIT_PNG;
    if ((IMG_Init(imgFlags) & imgFlags) != imgFlags) {
        std::cerr << "IMG_Init: " << IMG_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    SDL_Surface* icon = IMG_Load("assets/icon.png");
    if (icon == NULL)
    {
        std::cerr << "IMG_Load: " << IMG_GetError() << std::endl;
        return EXIT_FAILURE;
    }


    SDL_Rect displayRectangle;
    if (SDL_GetDisplayUsableBounds(PRIMARY_DISPLAY_INDEX, &displayRectangle) != 0)
    {
        std::cerr << "SDL_GetDisplayUsableBounds: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    int windowHeight = displayRectangle.h * 0.8;
    int windowWidth  = windowHeight * 0.66;
    
    auto *window = SDL_CreateWindow("Putt-It",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        windowWidth, windowHeight, SDL_WINDOW_MOUSE_GRABBED);
    auto *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetWindowIcon(window, icon);

    while (true)
    {
        SDL_Event Event;
        while (SDL_PollEvent(&Event) != 0) {

        }
        SDL_Delay(100);
    }

    SDL_Quit();
}