typedef enum			e_type
{
	MANDELBROT,
	JULIA
}						t_type;

typedef struct			s_complex
{
	double				r;
	double				i;
}						t_complex;

typedef struct			s_vector
{
	double				r;
	double				g;
	double				b;
}						t_vector;

typedef struct			s_fractal
{
	char				fractalType;
	int					iterMax;
	int					screenWidth;
	double				bornX[2];
	double				bornY[2];
	double				scaleX;
	double				scaleY;
	double				offsetX;
	double				offsetY;
	t_complex			z;
	t_complex			z0;
	t_vector			usrColor;
}						t_fractal;

static unsigned int		colorToUint(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned int		color;

	color = (r << 16) | (g << 8) | b;
	return (color);
}

static unsigned int		getColor(t_vector usrColor, double l)
{
	t_vector			color;

	color.r += 0.5 + 0.5 * cos(3.0 + l * 0.15 + usrColor.r);
	color.g += 0.5 + 0.5 * cos(3.0 + l * 0.15 + usrColor.g);
	color.b += 0.5 + 0.5 * cos(3.0 + l * 0.15 + usrColor.b);
	return (colorToUint(255 * color.r, 255 * color.g, 255 * color.b));
}

static unsigned int		calc(t_fractal m, double x, double y)
{
	int					r = 0;

	while (r < m.iterMax)
	{
		double dotZ_r = m.z.r * m.z.r;
		double dotZ_i = m.z.i * m.z.i;
		if (dotZ_r + dotZ_i > 65235)
			break ;
		double tmp = m.z.r;
		m.z.r = dotZ_r - dotZ_i + m.z0.r;
		m.z.i = 2 * tmp * m.z.i + m.z0.i;
		r++;
	}
	if (r == m.iterMax)
		return (0);
	float sr = r - log2(log2(m.z.r * m.z.r + m.z.i * m.z.i)) + 4.0;
	float ar = 1.0;
	return (getColor(m.usrColor, mix(r, sr, ar)));
}

static unsigned int		color(t_fractal m, int pixX, int pixY)
{
	unsigned int		color_rgb;
	double				x;
	double				y;

	x = m.offsetX + m.scaleX * pixX;
	y = m.offsetY + m.scaleY * pixY;
	m.z.r = x;
	m.z.i = y;
	if (m.fractalType == MANDELBROT)
		m.z0 = m.z;
	color_rgb = calc(m, x, y);
	return (color_rgb);
}

__kernel void			drawFractal
(
						__global unsigned int * output,
						__constant t_fractal * m
)
{
	const int			work_item_id = get_global_id(0);
	int					x = work_item_id % m->screenWidth;
	int					y = work_item_id / m->screenWidth;
	unsigned int		color_rgb;

	color_rgb = color(*m, x, y);
	output[work_item_id] = color_rgb;
}
