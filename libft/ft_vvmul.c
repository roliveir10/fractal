/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vvmul.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 02:01:12 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 02:31:17 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector			ft_vvmul(t_vector va, t_vector vb)
{
	t_vector		result;

	result.x = va.x * vb.x;
	result.y = va.y * vb.y;
	result.z = va.z * vb.z;
	return (result);
}
