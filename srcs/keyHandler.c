#include "fractal.h"

void			keyHandler(SDL_Event *event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN)
		return ;
	else if (event->type == SDL_MOUSEWHEEL)
		return ;
	else if (event->type == SDL_KEYDOWN)
		return ;
	else if (event->type == SDL_KEYUP)
		return ;
}
