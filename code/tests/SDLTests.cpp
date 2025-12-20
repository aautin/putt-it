#include <gtest/gtest.h>
#include <SDL2/SDL.h>

TEST(SLDTests, SDL_Init) {
	ASSERT_NO_THROW(SDL_Init(SDL_INIT_EVERYTHING));
}