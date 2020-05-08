/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2nd_degree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:45:29 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/26 09:31:21 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

t_solution		ft_2nd_degree(double a, double b, double c)
{
	double		t1;
	double		t2;
	double		delta;
	t_solution	sol;

	ft_bzero(&sol, sizeof(t_solution));
	if ((delta = pow(b, 2) - 4 * a * c) < 0)
		return (sol);
	t1 = (-b + sqrt(delta)) / (2.0 * a);
	if (!delta)
	{
		sol.nbrSol = 1;
		sol.sol[0] = t1;
		return (sol);
	}
	t2 = (-b - sqrt(delta)) / (2.0 * a);
	if (t1 <= 0 && t2 > 0)
	{
		sol.nbrSol = 1;
		sol.sol[0] = t2;
		return (sol);
	}
	if (t1 > 0 && t2 <= 0)
	{
		sol.nbrSol = 1;
		sol.sol[0] = t1;
		return (sol);
	}
	sol.nbrSol = 2;
	sol.sol[0] = t1;
	sol.sol[1] = t2;
	return (sol);
}
