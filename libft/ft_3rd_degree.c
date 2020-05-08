/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3rd_degree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:17:09 by oboutrol          #+#    #+#             */
/*   Updated: 2019/07/01 17:17:25 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

static double	valid_small(double r1, double r2)
{
	if (r1 < 0 && r2 < 0)
		return (-1);
	if (r1 >= 0 && r2 >= 0)
	{
		if (r1 < r2)
			return (r1);
		else
			return (r2);
	}
	if (r1 > 0)
		return (r1);
	else
		return (r2);
}

static double	valid_smallt(double r1, double r2, double r3)
{
	r1 = valid_small(r1, r2);
	r1 = valid_small(r1, r3);
	return (r1);
}

double			ft_3rd_degree(double a, double b, double c, double d)
{
	double	var[2];
	double	del[2];
	double	r1;
	double	r2;
	double	r3;
	
	var[1] = (3 * a * c - pow(b, 2)) / (3 * pow(a, 2));
	var[0] = (2 * pow(b, 3) - 9 * a * b * c + 27 * pow(a, 2) * d)
		/ (27.0 * pow(a, 3));
	del[1] = pow(var[0], 2) + (pow(var[1], 3) * 4) / 27.0;
	r1 = cbrt((-var[0] - sqrt(del[1])) / 2.0)
		+ cbrt((-var[0] + sqrt(del[1])) / 2.0) - (b / (3 * a));
	del[0] = pow(b + a * r1, 2) - 4 * a * (c + (b + a * r1) * r1);
	r2 = (-b - a * r1 - sqrt(del[0])) / (2 * a);
	r3 = (-b - a * r1 + sqrt(del[0])) / (2 * a);
	printf("%f %f %f\n", r1, r2, r3);
	return (valid_smallt(r1, r2, r3));
}
