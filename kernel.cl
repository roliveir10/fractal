typedef struct			s_mandelbrot
{
	int					screenWidth;
	double				bornX[2];
	double				bornY[2];
	double				scaleX;
	double				scaleY;
	double				offsetX;
	double				offsetY;
}						t_mandelbrot;

static unsigned int		colorToUint(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned int		color;

	color = (r << 16) | (g << 8) | b;
	return (color);
}

static unsigned int		calcMandelbrot(double x, double y)
{
	double				z_r = x;
	double				z_i = y;
	double				z0_r = x;
	double				z0_i = y;
	int					r = 0;
	double				tmp;
	int					iterMax = 200;

	while (z_r * z_r + z_i * z_i < 4 && r < iterMax)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + z0_r;
		z_i = 2 * tmp * z_i + z0_i;
		r++;
	}
	if (r == iterMax)
		return (colorToUint(0, 0, 0));
	return (colorToUint(0, 0, r * 255 / iterMax));
}

static unsigned int		color(t_mandelbrot m, int pixX, int pixY)
{
	unsigned int		color_rgb;
	double				x;
	double				y;

	x = m.offsetX + m.scaleX * pixX;
	y = m.offsetY + m.scaleY * pixY;
	color_rgb = calcMandelbrot(x, y);
	return (color_rgb);
}

__kernel void			mandelbrot
(
						__global unsigned int * output,
						__constant t_mandelbrot * m
)
{
	const int			work_item_id = get_global_id(0);
	int					x = work_item_id % m->screenWidth;
	int					y = work_item_id / m->screenWidth;
	unsigned int		color_rgb;

	color_rgb = color(*m, x, y);
	output[work_item_id] = color_rgb;
}
