#include "fractal.h"

static void		addOffset(t_env *env, double offsetX, double offsetY)
{
	env->m.bornX[0] += offsetX;
	env->m.bornX[1] += offsetX;
	env->m.bornY[0] += offsetY;
	env->m.bornY[1] += offsetY;
	env->print = 1;
}

void			updateScreen(t_env *env)
{
	double		offsetX = (env->m.bornX[1] - env->m.bornX[0]) * 0.01;
	double		offsetY = (env->m.bornY[1] - env->m.bornY[0]) * 0.01;

	if (env->keyPress[0])
		addOffset(env, offsetX, 0);
	else if (env->keyPress[1])
		addOffset(env, -offsetX, 0);
	else if (env->keyPress[2])
		addOffset(env, 0, offsetY);
	else if (env->keyPress[3])
		addOffset(env, 0, -offsetY);
}

static void		updateData(t_mandelbrot *m)
{
	m->offsetX =m->bornX[0];
	m->scaleX = (m->bornX[1] - m->bornX[0]) * 0.00125;
	m->offsetY = m->bornY[0];
	m->scaleY = (m->bornY[1] - m->bornY[0]) * 0.00125;
}

int				drawWindow(t_env *env)
{
	int			error;

	updateData(&env->m);
	if ((error = setUpKernel(env, &env->m)) < 0)
		return (0);
	if ((error = executeKernel(env)) < 0)
		return (0);
	return (1);
}
