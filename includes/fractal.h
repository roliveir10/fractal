#ifndef FRACTAL_H
# define FRACTAL_H

# include <OpenCL/cl.h>
# include "libft.h"
# include "SDL.h"

# define WIN_TITLE "fractal de Robin"
# define SCREENX 2048
# define SCREENY 1152
# define CL_PLATFORM_UNINITIALIZED -1
# define CL_PLATFORM_MAX_AMOUNT 2
# define CL_PROGRAM_SOURCE_ "kernel.cl"
# define CL_PROGRAM_OPTIONS "-Wall -Wextra -Werror"

# define NBR_KEY 7

typedef enum			e_type
{
	MANDELBROT,
	JULIA
}						t_type;

typedef enum			e_key
{
	LEFT,
	RIGHT,
	UP,
	DOWN,
	CLICK,
	PLUS,
	MINUS
}						t_key;

typedef struct			s_gpu
{
	cl_device_id		id;
}						t_gpu;

typedef struct			s_gpu_buffers
{
	cl_mem				canvas_pixels;
	cl_mem				fractalStruct;
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

typedef struct			s_fractal
{
	char				fractalType;
	int					iterMax;
	int					screenWidth;
	double				bornX[2];
	double				bornY[2];
	double				scaleX;
	double				scaleY;
	double				offsetX;
	double				offsetY;
	t_complex			z;
	t_complex			z0;
	t_vector			color;
}						t_fractal;

typedef struct			s_mouse
{
	double				deltaX;
	double				deltaY;
}						t_mouse;

typedef struct			s_env
{
	t_lib				lib;
	t_cl				ocl;
	t_fractal			f;
	char				isRunning;
	char				print;
	char				keyPress[NBR_KEY];
	t_mouse				mouse;
}						t_env;

int						initOpenCL(t_cl *ocl, int platform_index);
int						setUpKernel(t_env *env, t_fractal *m);
int						executeKernel(t_env *env);
void					delOpenCL(t_cl *ocl);
void					runLoop(t_env *env);
void					keyHandler(t_env *env, SDL_Event *event);
int						drawWindow(t_env *env);
void					updateScreen(t_env *env);
void					fillFractalStruct(t_vector color, t_fractal *f, int type);
t_vector				getColorArg(int argc, char **argv);
#endif
