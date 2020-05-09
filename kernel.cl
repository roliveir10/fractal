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

typedef struct			s_vector
{
	double				r;
	double				g;
	double				b;
}						t_vector;

static unsigned int		colorToUint(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned int		color;

	color = (r << 16) | (g << 8) | b;
	return (color);
}

static unsigned int		getColor(double l)
{
	t_vector			color;

	color.r += 0.5 + 0.5 * cos(3.0 + l * 0.15);
	color.g += 0.5 + 0.5 * cos(3.0 + l * 0.15 + 0.6);
	color.b += 0.5 + 0.5 * cos(3.0 + l * 0.15 + 1.0);
	return (colorToUint(255 * color.r, 255 * color.g, 255 * color.b));
}

static unsigned int		calcMandelbrot(double x, double y)
{
	double				z_r = x;
	double				z_i = y;
	int					r = 0;
	int					iterMax = 256;

	while (r < iterMax)
	{
		double dotZ_r = z_r * z_r;
		double dotZ_i = z_i * z_i;
		if (dotZ_r + dotZ_i > 65235)
			break ;
		double tmp = z_r;
		z_r = dotZ_r - dotZ_i + x;
		z_i = 2 * tmp * z_i + y;
		r++;
	}
	if (r == iterMax)
		return (0);
	float sr = r - log2(log2(z_r * z_r + z_i * z_i)) + 4.0;
	float ar = 1.0;
	return (getColor(mix(r, sr, ar)));
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
