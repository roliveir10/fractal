#include "fractal.h"

static void		fillMandelbrotStruct(t_fractal *m)
{
	m->bornX[0] = -3.6;
	m->bornX[1] = -0.9;
	m->bornY[0] = -1.7;
	m->bornY[1] = 0.7;
}

static void		fillJuliaStruct(t_fractal *j)
{
	j->bornX[0] = -3.6;
	j->bornX[1] = -0.72;
	j->bornY[0] = 2.1;
	j->bornY[1] = -0.96;
	j->z0.r = -0.70176;
	j->z0.i = -0.3842;
}

void				fillFractalStruct(t_vector color, t_fractal *f, int type)
{
	f->screenWidth = SCREENX;
	f->color = color;
	f->fractalType = type;
	f->iterMax = 256;
	if (type == MANDELBROT)
		fillMandelbrotStruct(f);
	else if (type == JULIA)
		fillJuliaStruct(f);
}
