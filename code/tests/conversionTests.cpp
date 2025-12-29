// GTest headers
#include <gtest/gtest.h>

// SDL headers
#include <SDL2/SDL_rect.h>

// Putt-It-core headers
#include <conversion.h>

using namespace core::conversion::sdl;

TEST(conversion, FRect_Zero)
{
    SDL_Rect src{0, 0, 0, 0};
    SDL_FRect dst = FRect(src);
    EXPECT_FLOAT_EQ(dst.x, 0.0f);
    EXPECT_FLOAT_EQ(dst.y, 0.0f);
    EXPECT_FLOAT_EQ(dst.w, 0.0f);
    EXPECT_FLOAT_EQ(dst.h, 0.0f);
}

TEST(conversion, FRect_PositiveValues)
{
    SDL_Rect src{10, 20, 300, 400};
    SDL_FRect dst = FRect(src);
    EXPECT_FLOAT_EQ(dst.x, 10.0f);
    EXPECT_FLOAT_EQ(dst.y, 20.0f);
    EXPECT_FLOAT_EQ(dst.w, 300.0f);
    EXPECT_FLOAT_EQ(dst.h, 400.0f);
}

TEST(conversion, FRect_NegativeValues)
{
    SDL_Rect src{-15, -25, 50, 75};
    SDL_FRect dst = FRect(src);
    EXPECT_FLOAT_EQ(dst.x, -15.0f);
    EXPECT_FLOAT_EQ(dst.y, -25.0f);
    EXPECT_FLOAT_EQ(dst.w, 50.0f);
    EXPECT_FLOAT_EQ(dst.h, 75.0f);
}

TEST(conversion, FPoint_Zero)
{
    SDL_Point src{0, 0};
    SDL_FPoint dst = FPoint(src);
    EXPECT_FLOAT_EQ(dst.x, 0.0f);
    EXPECT_FLOAT_EQ(dst.y, 0.0f);
}

TEST(conversion, FPoint_PositiveValues)
{
    SDL_Point src{10, 20};
    SDL_FPoint dst = FPoint(src);
    EXPECT_FLOAT_EQ(dst.x, 10.0f);
    EXPECT_FLOAT_EQ(dst.y, 20.0f);
}

TEST(conversion, FPoint_NegativeValues)
{
    SDL_Point src{-15, -25};
    SDL_FPoint dst = FPoint(src);
    EXPECT_FLOAT_EQ(dst.x, -15.0f);
    EXPECT_FLOAT_EQ(dst.y, -25.0f);
}