static unsigned int		calcMandelbrot(double x, double y)
{
	double				z_r = x;
	double				z_i = y;
	double				z0_r = x;
	double				z0_i = y;
	int					r = 0;
	double				tmp;
	int					iterMax = 300;

	while (z_r * z_r + z_i * z_i < 4 && r < iterMax)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + z0_r;
		z_i = 2 * tmp * z_i + z0_i;
		r++;
	}
	if (r == iterMax)
		return (0x000000);
	return (0xffffff);
}

static unsigned int		color(int pixX, int pixY, int width, int height)
{
	unsigned int		color_rgb;
	unsigned int		rgb[3];
	const double		sizeX[2] = {-2.1, 0.6};
	const double		sizeY[2] = {-1.2, 1.2};
	double				x;
	double				y;

	x = 1.2 * sizeX[0] + (sizeX[1] - sizeX[0]) / 800 * pixX;
	y = sizeY[0] + (sizeY[1] - sizeY[0]) / 800 * pixY;
	color_rgb = calcMandelbrot(x, y);
	return (color_rgb);
}

__kernel void			mandelbrot(__global unsigned int *output, int width, int height)
{
	const int			work_item_id = get_global_id(0);
	int					x = work_item_id % width;
	int					y = work_item_id / width;
	unsigned int		color_rgb;

	color_rgb = color(x, y, width, height);
	output[work_item_id] = color_rgb;
}
