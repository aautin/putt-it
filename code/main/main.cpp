// STL headers
#include <iostream>

// SDL headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Putt-It-core headers
#include <conversion.h>

#define PRIMARY_DISPLAY_INDEX 0
#define WINDOW_OFFSET         0.9f

using namespace core::conversion::sdl;

int main(int argc, char* argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "SDL_Init: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	SDL_Rect display;
	if (SDL_GetDisplayUsableBounds(PRIMARY_DISPLAY_INDEX, &display) != 0)
	{
		std::cerr << "SDL_GetDisplayUsableBounds: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	
	auto *window = SDL_CreateWindow("Putt-It",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		800, 800,
		0);
	
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* icon = IMG_Load("assets/icon.png");
	if (icon == NULL)
	{
		std::cerr << "IMG_Load: " << IMG_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	
	SDL_SetWindowIcon(window, icon);
	SDL_FreeSurface(icon);

	//
	// Main game loop
	//
	while (true)
	{
		//
		// Inputs handling
		//
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_EventType::SDL_WINDOWEVENT
				&& event.window.event == SDL_WindowEventID::SDL_WINDOWEVENT_CLOSE)
			{
				SDL_Quit();
			}
		}
	}
}