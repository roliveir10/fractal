#include "fractal.h"

static void		addOffset(t_env *env, double offsetX, double offsetY)
{
	env->f.bornX[0] += offsetX;
	env->f.bornX[1] += offsetX;
	env->f.bornY[0] += offsetY;
	env->f.bornY[1] += offsetY;
	env->print = 1;
}

static void		addIter(t_env *env, double toAdd)
{
	env->f.iterMax = ft_clamp(env->f.iterMax + toAdd, 2, 1000);
	env->print = 1;
}

void			updateScreen(t_env *env)
{
	double		offsetX = (env->f.bornX[1] - env->f.bornX[0]) * 0.05;
	double		offsetY = (env->f.bornY[1] - env->f.bornY[0]) * 0.05;

	if (env->keyPress[LEFT])
		addOffset(env, offsetX, 0);
	else if (env->keyPress[RIGHT])
		addOffset(env, -offsetX, 0);
	else if (env->keyPress[UP])
		addOffset(env, 0, offsetY);
	else if (env->keyPress[DOWN])
		addOffset(env, 0, -offsetY);
	else if (env->keyPress[PLUS])
		addIter(env, 1);
	else if (env->keyPress[MINUS])
		addIter(env, -1);
}

static void		updateData(t_fractal *f)
{
	f->offsetX = f->bornX[0];
	f->scaleX = (f->bornX[1] - f->bornX[0]) * 0.00125;
	f->offsetY = f->bornY[0];
	f->scaleY = (f->bornY[1] - f->bornY[0]) * 0.00125;
}

int				drawWindow(t_env *env)
{
	int			error;

	updateData(&env->f);
	if ((error = setUpKernel(env, &env->f)) < 0)
		return (0);
	if ((error = executeKernel(env)) < 0)
		return (0);
	return (1);
}
