// STL headers
#include <iostream>

// SDL headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Putt-It-core headers
#include <conversion.h>

#define PRIMARY_DISPLAY_INDEX 0
#define ORIGINAL_WIDTH        1000.f
#define ORIGINAL_HEIGHT       1500.f
#define WINDOW_OFFSET 0.9f

using namespace core::conversion::sdl;

SDL_FPoint getWindowSize(SDL_FRect& display)
{
    if (display.w / display.h < ORIGINAL_WIDTH / ORIGINAL_HEIGHT)
    {
        return { display.w * WINDOW_OFFSET, display.w * (ORIGINAL_HEIGHT / ORIGINAL_WIDTH) * WINDOW_OFFSET };
    }
    else
    {
        return { display.h * (ORIGINAL_WIDTH / ORIGINAL_HEIGHT) * WINDOW_OFFSET, display.h * WINDOW_OFFSET };
    }
}

int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL_Init: " << SDL_GetError() << std::endl;
        return EXIT_FAILURE;
    }

    IMG_Init(IMG_INIT_PNG);
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
    
    auto  size = getWindowSize(FRect(displayRectangle));
    auto *window = SDL_CreateWindow("Putt-It",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        size.x, size.y,
        SDL_WINDOW_MOUSE_GRABBED);

    SDL_SetWindowIcon(window, icon);
    while (true)
    {
        //
        // Inputs handling
        //
        SDL_Event Event;
        while (SDL_PollEvent(&Event) != 0) {
        
        }
    }

    SDL_Quit();
}