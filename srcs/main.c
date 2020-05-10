#include <stdlib.h>
#include "fractal.h"

void			delenv(t_lib *lib, t_cl *ocl)
{
	delOpenCL(ocl);
	if (lib->texture)
		SDL_DestroyTexture(lib->texture);
	if (lib->renderer)
		SDL_DestroyRenderer(lib->renderer);
	if (lib->window)
		SDL_DestroyWindow(lib->window);
	if (lib->panel.arial_black_20)
		TTF_CloseFont(lib->panel.arial_black_20);
	TTF_Quit();
	if (lib->panel.renderer)
		SDL_DestroyRenderer(lib->panel.renderer);
	if (lib->panel.window)
		SDL_DestroyWindow(lib->panel.window);
	SDL_Quit();
	exit(1);
}

static int		initLib(t_lib *lib)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return (0);
	if (!(lib->window = SDL_CreateWindow(WIN_TITLE, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP)))
		return (0);
	SDL_GetWindowSize(lib->window, &lib->w, &lib->h);
	lib->wId = SDL_GetWindowID(lib->window);
	if (!(lib->renderer = SDL_CreateRenderer(lib->window, -1,
			SDL_RENDERER_PRESENTVSYNC)))
		return (0);
	if (!(lib->texture = SDL_CreateTexture(lib->renderer,
			SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING,
			lib->w, lib->h)))
		return (0);
	if (!initPanel(&lib->panel))
		return (0);
	return (1);
}

int				main(void)
{
	t_env		env;
	t_vector	usrColor;

	ft_bzero(&env, sizeof(t_env));
	if (!initLib(&env.lib))
		return (1);
	env.ocl.resolution = env.lib.w * env.lib.h;
	if (!initOpenCL(&env.ocl, CL_PLATFORM_UNINITIALIZED))
	{
		delenv(&env.lib, &env.ocl);
		return (1);
	}
	usrColor.x = 0;
	usrColor.y = 1.2;
	usrColor.z = 2;
	fillFractalStruct(usrColor, &env.f, MANDELBROT);
	env.f.screenWidth = env.lib.w;
	if (!drawPanel(&env))
		return (0);
	runLoop(&env);
	delenv(&env.lib, &env.ocl);
	return (0);
}
