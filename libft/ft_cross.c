/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoussa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 21:16:29 by mmoussa           #+#    #+#             */
/*   Updated: 2019/06/25 21:16:30 by mmoussa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector			ft_cross(t_vector vect1, t_vector vect2)
{
	t_vector		result;

	result.x =  vect1.y * vect2.z - vect2.y * vect1.z;
	result.y =  vect1.z * vect2.x - vect2.z * vect1.x;
	result.z =  vect1.x * vect2.y - vect2.x * vect1.y;
	return (result);
}
