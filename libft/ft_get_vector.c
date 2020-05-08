/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 01:45:44 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 01:58:59 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector			ft_get_vector(t_vector pos_a, t_vector pos_b)
{
	return (ft_normalize(ft_vsub(pos_a, pos_b)));
}
