/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdiv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 01:49:35 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 02:10:02 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector			ft_vdiv(t_vector v, double f)
{
	t_vector		result;

	if (!f)
	{
		ft_bzero(&result, sizeof(t_vector));
		return (result);
	}
	result.x = v.x / f;
	result.y = v.y / f;
	result.z = v.z / f;
	return (result);
}
