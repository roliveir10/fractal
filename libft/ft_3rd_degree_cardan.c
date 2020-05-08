/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_3rd_degree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboutrol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 17:17:09 by oboutrol          #+#    #+#             */
/*   Updated: 2019/07/01 17:39:41 by oboutrol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

double			ft_3rd_degree_cardan(double a, double b, double c, double d)
{
	double	var[2];
	double	del[2];
	double	r1;
	
	var[1] = (3 * a * c - pow(b, 2)) / (3 * pow(a, 2));
	var[0] = (2 * pow(b, 3) - 9 * a * b * c + 27 * pow(a, 2) * d)
		/ (27.0 * pow(a, 3));
	del[1] = pow(var[0], 2) + (pow(var[1], 3) * 4) / 27.0;
	r1 = cbrt((-var[0] - sqrt(del[1])) / 2.0)
		+ cbrt((-var[0] + sqrt(del[1])) / 2.0) - (b / (3 * a));
	return (r1);
}
