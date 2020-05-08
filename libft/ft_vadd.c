/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:05:18 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 02:06:43 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector			ft_vadd(t_vector pos_a, t_vector pos_b)
{
	t_vector		result;

	result.x = pos_a.x + pos_b.x;
	result.y = pos_a.y + pos_b.y;
	result.z = pos_a.z + pos_b.z;
	return (result);
}
