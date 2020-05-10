#include "fractal.h"

t_vector			getColorArg(int argc, char **argv)
{
	t_vector		color;
	int				i = 1;

	if (argc < 2)
	{
		color.x = 0;
		color.y = 0.6;
		color.z = 1;
		return (color);
	}
	while (argv[i])
	{
		if (i == 1)
			color.x = ft_clamp(atof(argv[i]) / 255, 0, 1);
		else if (i == 2)
			color.y = ft_clamp(atof(argv[i]) / 255, 0, 1);
		else if (i == 3)
			color.z = ft_clamp(atof(argv[i]) / 255, 0, 1);
		i++;
	}
	return (color);
}
