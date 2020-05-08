/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:03:26 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 02:40:49 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector			ft_vsub(t_vector pos_a, t_vector pos_b)
{
	t_vector		result;

	result.x = pos_b.x - pos_a.x;
	result.y = pos_b.y - pos_a.y;
	result.z = pos_b.z - pos_a.z;
	return (result);
}
