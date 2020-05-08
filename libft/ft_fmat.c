/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:56:58 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/24 14:24:35 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

static void		ft_fmatx(double (*mat)[3][3][3], double cos, double sin)
{
	(*mat)[0][0][0] = 1.0;
	(*mat)[0][1][1] = cos;
	(*mat)[0][1][2] = -sin;
	(*mat)[0][2][1] = sin;
	(*mat)[0][2][2] = cos;
}

static void		ft_fmaty(double (*mat)[3][3][3], double cos, double sin)
{
	(*mat)[1][0][0] = cos;
	(*mat)[1][0][2] = sin;
	(*mat)[1][1][1] = 1.0;
	(*mat)[1][2][0] = -sin;
	(*mat)[1][2][2] = cos;
}

static void		ft_fmatz(double (*mat)[3][3][3], double cos, double sin)
{
	(*mat)[2][0][0] = cos;
	(*mat)[2][0][1] = -sin;
	(*mat)[2][1][0] = sin;
	(*mat)[2][1][1] = cos;
	(*mat)[2][2][2] = 1.0;
}

void			ft_fmat(double (*mat)[3][3][3], t_vector rotation,
		double way)
{
	double		teta;

	ft_bzero(mat, sizeof(double) * 27);
	teta = rotation.x * M_PI / 180 * way;
	ft_fmatx(mat, cos(teta), sin(teta));
	teta = rotation.y * M_PI / 180 * way;
	ft_fmaty(mat, cos(teta), sin(teta));
	teta = rotation.z * M_PI / 180 * way;
	ft_fmatz(mat, cos(teta), sin(teta));
}
