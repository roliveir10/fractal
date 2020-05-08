/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roliveir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 01:59:14 by roliveir          #+#    #+#             */
/*   Updated: 2019/06/23 02:09:59 by roliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"

double				ft_vdist(t_vector pos_a, t_vector pos_b)
{
	t_vector		vc;

	vc = ft_vsub(pos_a, pos_b);
	return (sqrt(pow(vc.x, 2) + pow(vc.y, 2) + pow(vc.z, 2)));
}
