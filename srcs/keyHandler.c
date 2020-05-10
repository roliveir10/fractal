#include "fractal.h"

static void			keyUp(t_env *env, int keycode)
{
	if (keycode == SDLK_LEFT)
		env->keyPress[LEFT] = 0;
	else if (keycode == SDLK_RIGHT)
		env->keyPress[RIGHT] = 0;
	else if (keycode == SDLK_UP)
		env->keyPress[UP] = 0;
	else if (keycode == SDLK_DOWN)
		env->keyPress[DOWN] = 0;
	else if (keycode == SDLK_SPACE)
	{
		fillFractalStruct(env->f.color, &env->f, env->f.fractalType);
		env->print = 1;
	}
	else if (keycode == SDLK_n)
	{
		fillFractalStruct(env->f.color, &env->f, !env->f.fractalType);
		env->print = 1;
	}
	else if (keycode == SDLK_EQUALS)
		env->keyPress[PLUS] = 0;
	else if (keycode == SDLK_MINUS)
		env->keyPress[MINUS] = 0;
}

static void			keyDown(t_env *env, int keycode)
{
	if (keycode == SDLK_LEFT)
		env->keyPress[LEFT] = 1;
	else if (keycode == SDLK_RIGHT)
		env->keyPress[RIGHT] = 1;
	else if (keycode == SDLK_UP)
		env->keyPress[UP] = 1;
	else if (keycode == SDLK_DOWN)
		env->keyPress[DOWN] = 1;
	else if (keycode == SDLK_EQUALS)
		env->keyPress[PLUS] = 1;
	else if (keycode == SDLK_MINUS)
		env->keyPress[MINUS] = 1;
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
	offsetX = (env->f.bornX[1] - env->f.bornX[0]) * offsetX * 0.00125;
	offsetY = (env->f.bornY[1] - env->f.bornY[0]) * offsetY * 0.00125;
	zoomX = (env->f.bornX[1] - env->f.bornX[0]) * (1.0 - zo[type]);
	zoomY = (env->f.bornY[1] - env->f.bornY[0]) * (1.0 - zo[type]);
	env->f.bornX[0] -= zoomX * 0.5 + offsetX;
	env->f.bornX[1] += zoomX * 0.5 - offsetX;
	env->f.bornY[0] -= zoomY * 0.5 + offsetY;
	env->f.bornY[1] += zoomY * 0.5 - offsetY;
	env->print = 1;
}

static void			mouseMotion(t_env *env, SDL_Event *event)
{
	(void)event;

	if (env->f.fractalType == JULIA && env->keyPress[CLICK])
	{
		env->f.z0.r += (env->mouse.deltaX - event->button.x) * 0.0005;
		env->f.z0.i += (env->mouse.deltaY - event->button.y) * 0.0005;
		env->print = 1;
	}
	env->mouse.deltaX = event->button.x;
	env->mouse.deltaY = event->button.y;
}

static void			mouseButtonDown(t_env *env, SDL_Event *event)
{
	if (event->button.button == SDL_BUTTON_LEFT)
		env->keyPress[CLICK] = 1;
}

static void			mouseButtonUp(t_env *env, SDL_Event *event)
{
	if (event->button.button == SDL_BUTTON_LEFT)
		env->keyPress[CLICK] = 0;
}

void				keyHandler(t_env *env, SDL_Event *event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN)
		mouseButtonDown(env, event);
	if (event->type == SDL_MOUSEBUTTONUP)
		mouseButtonUp(env, event);
	if (event->type == SDL_MOUSEWHEEL)
		zoom(env, event);
	if (event->type == SDL_KEYDOWN)
		keyDown(env, event->key.keysym.sym);
	if (event->type == SDL_KEYUP)
		keyUp(env, event->key.keysym.sym);
	if (event->type == SDL_MOUSEMOTION)
		mouseMotion(env, event);
}
