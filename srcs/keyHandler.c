#include "fractal.h"

static void		keyUp(t_env *env, int keycode)
{
	if (keycode == SDLK_LEFT)
		env->keyPress[0] = 0;
	else if (keycode == SDLK_RIGHT)
		env->keyPress[1] = 0;
	else if (keycode == SDLK_UP)
		env->keyPress[2] = 0;
	else if (keycode == SDLK_DOWN)
		env->keyPress[3] = 0;
}

static void		keyDown(t_env *env, int keycode)
{
	if (keycode == SDLK_LEFT)
		env->keyPress[0] = 1;
	else if (keycode == SDLK_RIGHT)
		env->keyPress[1] = 1;
	else if (keycode == SDLK_UP)
		env->keyPress[2] = 1;
	else if (keycode == SDLK_DOWN)
		env->keyPress[3] = 1;
}

void			keyHandler(t_env *env, SDL_Event *event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN)
		return ;
	else if (event->type == SDL_MOUSEWHEEL)
		return ;
	else if (event->type == SDL_KEYDOWN)
		keyDown(env, event->key.keysym.sym);
	else if (event->type == SDL_KEYUP)
		keyUp(env, event->key.keysym.sym);
		return ;
}
