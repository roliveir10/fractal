#include <stdlib.h>
#include "fractal.h"

void			delenv(t_lib *lib, t_cl *ocl)
{
	delOpenCL(ocl);
	if (lib->renderer)
		SDL_DestroyRenderer(lib->renderer);
	if (lib->window)
		SDL_DestroyWindow(lib->window);
	SDL_Quit();
	exit(1);
}

static int		initLib(t_lib *lib)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (0);
	if (!(lib->window = SDL_CreateWindow(WIN_TITLE, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, SCREENX, SCREENY, 0)))
		return (0);
	if (!(lib->renderer = SDL_CreateRenderer(lib->window, -1,
			SDL_RENDERER_PRESENTVSYNC)))
		return (0);
	if (!(lib->texture = SDL_CreateTexture(lib->renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
			SCREENX, SCREENY)))
		return (0);
	return (1);
}

int				main(void)
{
	t_env		env;

	ft_bzero(&env, sizeof(t_env));
	if (!initLib(&env.lib))
		return (1);
	if (!initOpenCL(&env.ocl, CL_PLATFORM_UNINITIALIZED))
	{
		delenv(&env.lib, &env.ocl);
		return (1);
	}
	runLoop(&env);
	delenv(&env.lib, &env.ocl);
	return (0);
}
