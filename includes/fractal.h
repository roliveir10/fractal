#ifndef FRACTAL_H
# define FRACTAL_H

# include <OpenCL/cl.h>
# include "libft.h"
# include "SDL.h"

# define WIN_TITLE "fractal de Robin"
# define SCREENX 1280
# define SCREENY 720
# define CL_PLATFORM_UNINITIALIZED -1
# define CL_PLATFORM_MAX_AMOUNT 2
# define CL_PROGRAM_SOURCE_ "kernel.cl"
# define CL_PROGRAM_OPTIONS "-Wall -Wextra -Werror"

typedef struct			s_gpu
{
	cl_device_id		id;
}						t_gpu;

typedef struct			s_gpu_buffers
{
	cl_mem				canvas_pixels;
}						t_gpu_buffers;

typedef struct			s_cl
{
	cl_platform_id		platforms[CL_PLATFORM_MAX_AMOUNT];
	cl_uint				gpu_platform_index;
	cl_uint				platform_amount;
	t_gpu				gpu;
	cl_context			context;
	cl_command_queue	cmd_queue;
	cl_program			program;
	t_gpu_buffers		gpu_buf;
	cl_kernel			kernel;
}						t_cl;

typedef struct			s_lib
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Texture			*texture;
	unsigned int		*image;
}						t_lib;

typedef struct			s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct			s_env
{
	t_lib				lib;
	t_cl				ocl;
	char				isRunning;
}						t_env;

int						initOpenCL(t_cl *ocl, int platform_index);
void					delOpenCL(t_cl *ocl);
void					runLoop(t_env *env);
int						drawWindow(t_env *env);
void					keyHandler(SDL_Event *event);
#endif
