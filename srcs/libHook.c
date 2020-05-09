#include "fractal.h"

static void		addOffset(t_env *env, double offsetX, double offsetY)
{
	env->m.offsetX += offsetX;
	env->m.offsetY += offsetY;
	env->print = 1;
}

static void		updateScreen(t_env *env)
{
	double		offsetX = env->m.scaleX * 5;
	double		offsetY = env->m.scaleY * 5;

	if (env->keyPress[0])
		addOffset(env, offsetX, 0);
	else if (env->keyPress[1])
		addOffset(env, -offsetX, 0);
	else if (env->keyPress[2])
		addOffset(env, 0, offsetY);
	else if (env->keyPress[3])
		addOffset(env, 0, -offsetY);
}

static int		drawWindow(t_env *env)
{
	int			error;

	if ((error = setUpKernel(env, &env->m)) < 0)
		return (0);
	if ((error = executeKernel(env)) < 0)
		return (0);
	return (1);
}

static int		printTexture(t_env *env)
{
	int			pitch;

	if (!SDL_LockTexture(env->lib.texture, NULL, (void**)&env->lib.image, &pitch))
	{
		if (!(drawWindow(env)))
			return (0);
		SDL_UnlockTexture(env->lib.texture);
		SDL_RenderCopy(env->lib.renderer, env->lib.texture, NULL, NULL);
		SDL_RenderPresent(env->lib.renderer);
	}
	return (1);
}

void			runLoop(t_env *env)
{
	SDL_Event	event;

	env->isRunning = 1;
	env->print = 1;
	while (env->isRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT
				|| (event.type == SDL_KEYDOWN
					&& event.key.keysym.sym == SDLK_ESCAPE)
				|| (event.type == SDL_WINDOWEVENT
					&& event.window.event == SDL_WINDOWEVENT_CLOSE))
			{
				env->isRunning = 0;
				break ;
			}
			keyHandler(env, &event);
		}
		if (env->isRunning && env->print)
		{
			if (!printTexture(env))
			{
				dprintf(2, "Could not print texture. Aborting...\n");
				env->isRunning = 0;
			}
			env->print = 0;
		}
		updateScreen(env);
	}
}
