#include "fractal.h"

static void			keyUp(t_env *env, int keycode)
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

static void			keyDown(t_env *env, int keycode)
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

static void			zoom(t_env *env, SDL_Event *event)
{
	const double	zo[2] = {0.75, 1.25};
	double			offsetX;
	double			offsetY;
	double			zoomX;
	double			zoomY;
	int				type = 0;
	int				mouseX;
	int				mouseY;

	if (event->wheel.y > 0)
		type = 1;
	SDL_GetMouseState(&mouseX, &mouseY);
	offsetX = (mouseX - 400) * (1.0 - zo[type]);
	offsetY = (mouseY - 400) * (1.0 - zo[type]);
	offsetX = (env->m.bornX[1] - env->m.bornX[0]) * offsetX * 0.00125;
	offsetY = (env->m.bornY[1] - env->m.bornY[0]) * offsetY * 0.00125;
	zoomX = (env->m.bornX[1] - env->m.bornX[0]) * (1.0 - zo[type]);
	zoomY = (env->m.bornY[1] - env->m.bornY[0]) * (1.0 - zo[type]);
	env->m.bornX[0] -= zoomX * 0.5 + offsetX;
	env->m.bornX[1] += zoomX * 0.5 - offsetX;
	env->m.bornY[0] -= zoomY * 0.5 + offsetY;
	env->m.bornY[1] += zoomY * 0.5 - offsetY;
	env->print = 1;
}

void				keyHandler(t_env *env, SDL_Event *event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN)
		return ;
	if (event->type == SDL_MOUSEWHEEL)
		zoom(env, event);
	if (event->type == SDL_KEYDOWN)
		keyDown(env, event->key.keysym.sym);
	if (event->type == SDL_KEYUP)
		keyUp(env, event->key.keysym.sym);
}
