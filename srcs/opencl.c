#define CL_SILENCE_DEPRECATION
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "fractal.h"

void			delOpenCL(t_cl *ocl)
{
	clFlush(ocl->cmd_queue);
	clFinish(ocl->cmd_queue);
	clReleaseKernel(ocl->kernel);
	clReleaseProgram(ocl->program);
	clReleaseMemObject(ocl->gpu_buf.canvas_pixels);
	clReleaseMemObject(ocl->gpu_buf.mandelbrot);
	clReleaseCommandQueue(ocl->cmd_queue);
	clReleaseContext(ocl->context);
}

static int		clInitializePlatform(t_cl *ocl)
{
	int			gpu = 0;

	if (clGetPlatformIDs(CL_PLATFORM_MAX_AMOUNT, ocl->platforms,
			&ocl->platform_amount) < 0)
		return (0);
	ocl->gpu_platform_index = -1;
	while (!gpu && ++ocl->gpu_platform_index < ocl->platform_amount)
	{
		if (clGetDeviceIDs(ocl->platforms[ocl->gpu_platform_index],
			CL_DEVICE_TYPE_GPU, 1, &ocl->gpu.id, NULL) == CL_SUCCESS)
			gpu = 1;
	}
	return (gpu);
}

static int		clPlatformData(t_cl *ocl, int platform_index)
{
	if (platform_index == CL_PLATFORM_UNINITIALIZED)
	{
		if (!clInitializePlatform(ocl))
			return (0);
	}
	else
	{
		ocl->gpu_platform_index = platform_index;
		if (clGetDeviceIDs(ocl->platforms[ocl->gpu_platform_index],
			CL_DEVICE_TYPE_GPU, 1, &ocl->gpu.id, NULL) < 0)
			return (0);
	}
	return (1);
}

static int		clCreateContextAndQueue(t_cl *ocl)
{
	cl_int		error;

	ocl->context = clCreateContext(NULL, 1, &ocl->gpu.id, NULL, NULL, &error);
	if (error < 0)
		return (0);
	ocl->cmd_queue = clCreateCommandQueue(ocl->context, ocl->gpu.id, 0, &error);
	return (error >= 0);
}

static int		clReadAndBuildProgram(t_cl *ocl)
{
	int			fd;
	cl_int		error;
	char		*file_buf;
	size_t		file_len;

	if ((fd = open(CL_PROGRAM_SOURCE_, O_RDONLY)) == -1)
		return (0);
	if (!ft_readFile(fd, &file_buf, (size_t)-1))
		return (0);
	file_len = ft_strlen(file_buf);
	ocl->program = clCreateProgramWithSource(ocl->context, 1,
		(char const **)&file_buf, &file_len, &error);
	ft_strdel(&file_buf);
	if (error < 0)
		return (0);
	if ((error = clBuildProgram(ocl->program, 1, &ocl->gpu.id,
			NULL, NULL, NULL)) < 0)
		return (0);
	close(fd);
	return (1);
}

static int		clInitGpuMemory(t_cl *ocl)
{
	int			error;

	ocl->gpu_buf.canvas_pixels = clCreateBuffer(ocl->context,
		CL_MEM_WRITE_ONLY, sizeof(cl_uint) * SCREENX * SCREENY,
		NULL, &error);
	ocl->gpu_buf.mandelbrot = clCreateBuffer(ocl->context,
		CL_MEM_READ_ONLY, sizeof(t_mandelbrot), NULL, &error);
	return (error >= 0);
}

static int		clInitKernel(t_cl *ocl)
{
	int			error;

	ocl->kernel = clCreateKernel(ocl->program, "mandelbrot", &error);
	return (error >= 0);
}

int				initOpenCL(t_cl *ocl, int platform_index)
{
	if (!clPlatformData(ocl, platform_index))
	{
		dprintf(2, "Could not find an appropriate GPU/platform. Aborting...\n");
		return (0);
	}
	if (!clCreateContextAndQueue(ocl))
	{
		dprintf(2, "Could not create device, context or queue. Aborting...\n");
		return (0);
	}
	if (!clReadAndBuildProgram(ocl))
	{
		dprintf(2, "Could not build program. Aborting...\n");
		return (0);
	}
	if (!clInitGpuMemory(ocl))
	{
		dprintf(2, "Could not initialize gpu memory buffers. Aborting...\n");
		return (0);
	}
	if (!clInitKernel(ocl))
	{
		dprintf(2, "Could not initialize kernels. Aborting...\n");
		return (0);
	}
	return (1);
}

int				setUpKernel(t_env *env, t_mandelbrot *m)
{
	int			error;

	if ((error = clEnqueueWriteBuffer(env->ocl.cmd_queue,
			env->ocl.gpu_buf.mandelbrot, CL_TRUE, 0, sizeof(t_mandelbrot),
			m, 0, NULL, NULL)) < 0)
		return (error);
	if ((error = clSetKernelArg(env->ocl.kernel, 0, sizeof(cl_mem),
			&env->ocl.gpu_buf.canvas_pixels)) < 0)
		return (error);
	if ((error = clSetKernelArg(env->ocl.kernel, 1, sizeof(cl_mem),
			&env->ocl.gpu_buf.mandelbrot)) < 0)
		return (error);
	return (0);
}

int				executeKernel(t_env *env)
{
	size_t		global_work_size;
	size_t		local_work_size;
	int			error;

	global_work_size = SCREENX * SCREENY;
	local_work_size = 64;
	if ((error = clEnqueueNDRangeKernel(env->ocl.cmd_queue, env->ocl.kernel, 1,
			NULL, &global_work_size, &local_work_size, 0, NULL, NULL)) < 0)
		return (error);
	if ((error = clEnqueueReadBuffer(env->ocl.cmd_queue,
			env->ocl.gpu_buf.canvas_pixels, CL_TRUE, 0,
			SCREENX * SCREENY * sizeof(cl_uint), env->lib.image,
			0, NULL, NULL)) < 0)
		return (error);
	return (1);
}
