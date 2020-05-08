#include "libft.h"

t_vector			ft_vvdiv(t_vector va, t_vector vb)
{
	t_vector		result;

	if (vb.x)
		result.x = va.x / vb.x;
	if (vb.y)
		result.y = va.y / vb.y;
	if (vb.z)
		result.z = va.z / vb.z;
	return (result);
}
