#define CL_SILENCE_DEPRECATION
#include "fractal.h"

int				drawWindow(t_env *env)
{
	size_t		global_work_size;
	size_t		local_work_size;
	int			width = SCREENX;
	int			height = SCREENY;
	int			error;

	global_work_size = SCREENX * SCREENY;
	local_work_size = 64;
	clSetKernelArg(env->ocl.kernel, 0, sizeof(cl_mem),
		&env->ocl.gpu_buf.canvas_pixels);
	clSetKernelArg(env->ocl.kernel, 1, sizeof(int), (void *)&width);
	clSetKernelArg(env->ocl.kernel, 2, sizeof(int), (void *)&height);

	if ((error = clEnqueueNDRangeKernel(env->ocl.cmd_queue, env->ocl.kernel, 1,
			NULL, &global_work_size, &local_work_size, 0, NULL, NULL)) < 0)
		return (0);
	if ((error = clEnqueueReadBuffer(env->ocl.cmd_queue,
			env->ocl.gpu_buf.canvas_pixels, CL_TRUE, 0,
			SCREENX * SCREENY * sizeof(cl_uint), env->lib.image,
			0, NULL, NULL)) < 0)
		return (0);
	return (1);
}
