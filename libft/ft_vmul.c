/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:06:51 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 02:27:54 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector			ft_vmul(t_vector v, double f)
{
	t_vector		result;

	result.x = v.x * f;
	result.y = v.y * f;
	result.z = v.z * f;
	return (result);
}
