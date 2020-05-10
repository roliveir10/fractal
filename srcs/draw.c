#include "fractal.h"

static void		addOffset(t_env *env, double offsetX, double offsetY)
{
	env->f.bornX[0] += offsetX;
	env->f.bornX[1] += offsetX;
	env->f.bornY[0] += offsetY;
	env->f.bornY[1] += offsetY;
	env->print = 1;
}

static void		addColor(t_env *env)
{
	int			x;
	int			y;

	if (env->windowId == env->lib.wId)
		return ;
	x = env->mouse.deltaX;
	y = env->mouse.deltaY;
	if (x > 136 && x < 164)
	{
		if (y > 232 || y <= 38)
			return ;
		else if (y > 200)
			env->f.color.z = ft_max(env->f.color.z - 0.01, 0);
		else if (y > 169)
			env->f.color.z = ft_min(env->f.color.z + 0.01, 2);
		else if (y > 135)
			env->f.color.y = ft_max(env->f.color.y - 0.01, 0);
		else if (y > 103)
			env->f.color.y = ft_min(env->f.color.y + 0.01, 2);
		else if (y > 72)
			env->f.color.x = ft_max(env->f.color.x - 0.01, 0);
		else if (y > 38)
			env->f.color.x = ft_min(env->f.color.x + 0.01, 2);
		env->print = 1;
		if (!(drawPanelMain(env)))
			return ;
		SDL_RenderPresent(env->lib.panel.renderer);
	}
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
	else if (env->keyPress[CLICK])
		addColor(env);
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
