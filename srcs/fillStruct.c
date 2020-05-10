#include "fractal.h"

static void		fillMandelbrotStruct(t_fractal *m)
{
	m->bornX[0] = -2.82;
	m->bornX[1] = -1.2;
	m->bornY[0] = -1.2;
	m->bornY[1] = 0.24;
}

static void		fillJuliaStruct(t_fractal *j)
{
	j->bornX[0] = -1.872;
	j->bornX[1] = -0.72;
	j->bornY[0] = 0.96;
	j->bornY[1] = -0.264;
	j->z0.r = -0.70176;
	j->z0.i = -0.3842;
}

void				fillFractalStruct(t_vector color, t_fractal *f, int type)
{
	f->color = color;
	f->fractalType = type;
	f->iterMax = 256;
	if (type == MANDELBROT)
		fillMandelbrotStruct(f);
	else if (type == JULIA)
		fillJuliaStruct(f);
}
