#include "conversion.h"

namespace core::conversion::sdl
{
    SDL_FRect FRect(SDL_Rect& rect)
    {
        return { (float)rect.x, (float)rect.y, (float)rect.w, (float)rect.h };
    }

    SDL_FPoint FPoint(SDL_Point& point)
    {
        return { (float)point.x, (float)point.y };
    }
}