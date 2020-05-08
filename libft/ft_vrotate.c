/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vrotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:48:44 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 04:40:16 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector			ft_vrotate(t_vector v, double mat[3][3])
{
	double			tmpx;
	double			tmpy;
	t_vector		result;

	tmpx = v.x;
	tmpy = v.y;
	result.x = mat[0][0] * tmpx + mat[0][1] * tmpy + mat[0][2] * v.z;
	result.y = mat[1][0] * tmpx + mat[1][1] * tmpy + mat[1][2] * v.z;
	result.z = mat[2][0] * tmpx + mat[2][1] * tmpy + mat[2][2] * v.z;
	return (result);
}
