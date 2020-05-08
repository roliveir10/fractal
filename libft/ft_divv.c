#include "libft.h"

t_vector			ft_divv(double f, t_vector v)
{
	t_vector		result;

	if (!f)
	{
		ft_bzero(&result, sizeof(t_vector));
		return (result);
	}
	if (v.x)
		result.x = f / v.x;
	if (v.y)
		result.y = f / v.y;
	if (v.z)
		result.z = f / v.z;
	return (result);
}
